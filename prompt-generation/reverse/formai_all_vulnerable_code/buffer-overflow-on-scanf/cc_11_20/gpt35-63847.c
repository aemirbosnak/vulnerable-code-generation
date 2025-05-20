//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
  //set up random number generator
  srand(time(NULL));
  
  //initialize variables
  int aliens = 0;
  int missiles = 100;
  int shields = 100;
  int distance = 0;
  int game_over = 0;
  
  //game loop
  while (!game_over) {
    
    //generate random events
    int event = rand() % 3;
    
    //alien attack
    if (event == 0) {
      aliens = rand() % 10 + 1;
      printf("You are being attacked by %d aliens!\n", aliens);
      if (shields >= aliens) {
        shields -= aliens;
        printf("Your shields are at %d%%\n", shields);
      }
      else {
        shields = 0;
        printf("Your shields have been depleted!\n");
        game_over = 1;
      }
    }
    
    //missile launch
    else if (event == 1) {
      int launch = rand() % 51 + 25;
      printf("You have %d missiles left.\n", missiles);
      if (missiles >= launch) {
        missiles -= launch;
        distance += launch;
        printf("You launched %d missiles and traveled %d light years.\n", launch, distance);
      }
      else {
        launch = missiles;
        missiles = 0;
        distance += launch;
        printf("You launched %d missiles and traveled %d light years.\n", launch, distance);
        printf("You have no missiles left.\n");
      }
    }
    
    //random encounter
    else {
      printf("You have encountered a strange object floating in space. Do you want to investigate?\n");
      char input;
      scanf("%c", &input);
      if (input == 'y' || input == 'Y') {
        printf("You approach the object and discover valuable resources!\n");
        missiles += rand() % 26 + 25;
        shields += rand() % 26 + 25;
        printf("You gained %d missiles and %d shield points.\n", missiles, shields);
      }
      else {
        printf("You decide to continue on your journey.\n");
      }
    }
    
    //check game conditions
    if (distance >= 1000) {
      printf("You have made it to your destination! You win!\n");
      game_over = 1;
    }
    if (missiles == 0 && shields == 0) {
      printf("You have been destroyed by the aliens. Game over.\n");
      game_over = 1;
    }
  }
  
  return 0;
}