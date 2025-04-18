#include "screen.h"
#include <SDL2/SDL_timer.h>
#include <algorithm>
#include <array>
#include <cstdlib>
const int GAME_WIDTH=640;
const int GAME_LENGHT=480;
bool isAlive(std::array<std::array<int, GAME_LENGHT>, GAME_WIDTH> & game, const int x , const int y){
  int alive =0;
  if (x >0 && game[x-1] [y] ==1 )alive++;
  if (y >0 && game[x] [y-1] ==1 )alive++;
  if (x<GAME_WIDTH&& game[x +1][y]==1)alive++;
  if (y<GAME_LENGHT&& game[x][y+1]==1)alive++;

  if (x >0 &&y>0&& game[x-1] [y-1] ==1 )alive++;
  if (y >0 &&x<GAME_WIDTH&& game[x+1] [y-1] ==1 )alive++;
  if (x >0 &&y<GAME_LENGHT&& game[x-1] [y+1] ==1 )alive++;
  if (y <GAME_LENGHT&&x<GAME_WIDTH&& game[x+1] [y+1] ==1 )alive++;
  if (game[x][y] ==1 && alive <2) 
    return false;
  if (game[x][y] ==1 &&( alive ==2|| alive ==3)) 
    return true;
  if(alive>3)return false;
  if(game[x][y]==0 && alive==3)return true;
  return false;





}
int main (int argc, char *argv[]) {
  G screen;
  std::array<std::array<int, GAME_LENGHT>, GAME_WIDTH> display{};
  std::array<std::array<int, GAME_LENGHT>, GAME_WIDTH> swap{};
  for (auto& row : display) {
    std::generate(row.begin(), row.end(), [](){ return rand()%10 == 0 ?1 : 0;});
  
  }
  while (true) {
    for (int i=0; i < GAME_WIDTH; ++i) {
      for (int k = 0; k < GAME_LENGHT; ++k){
        swap[i][k]= isAlive(display,i , k) ?1:0;
        
      }
    }
    for (int i=0; i < GAME_WIDTH; ++i) {
      for (int k = 0; k < GAME_LENGHT; ++k){
        if (swap[i][k]) {
          screen.drawpixel(i, k);
        
        }
        
      }
    
    }
          copy(swap.begin(), swap.end(), display.begin());
          screen.update();
          SDL_Delay(20);
          screen.input();
          screen.clearpixels();
    
  
  }
  
  return 0;
}

