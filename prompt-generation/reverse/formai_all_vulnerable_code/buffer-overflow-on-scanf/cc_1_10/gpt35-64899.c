//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: innovative
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main() {
  bool game_running = true;
  int player_choice;
  int ghost_location;
  int player_location = 1;
  int room[10] = {0,0,0,0,0,0,0,0,0,0};
  
  // seed random number generator
  srand(time(0));
  
  // place the ghost randomly in one of the rooms
  ghost_location = rand() % 10;
  room[ghost_location] = 1;
  
  printf("Welcome to the Haunted House Simulator!\n");
  printf("You are in Room 1. There are 10 rooms in total.\n");
  
  // game loop
  while (game_running) {
    printf("\nWhat would you like to do? (Enter the number of your choice)\n");
    printf("1. Move to the room on the left.\n");
    printf("2. Move to the room on the right.\n");
    printf("3. Stay in the current room.\n");
    printf("4. Quit the game.\n\n");
    
    scanf("%d", &player_choice);
    
    switch (player_choice) {
      case 1:
        if (player_location > 1) {
          player_location--;
          printf("You move to Room %d.\n", player_location);
        } else {
          printf("You can't move left from Room 1.\n");
        }
        break;
      case 2:
        if (player_location < 10) {
          player_location++;
          printf("You move to Room %d.\n", player_location);
        } else {
          printf("You can't move right from Room 10.\n");
        }
        break;
      case 3:
        printf("You stay in Room %d.\n", player_location);
        break;
      case 4:
        printf("Quitting the game...\n");
        game_running = false;
        break;
      default:
        printf("Invalid input. Please enter a number between 1 and 4.\n");
        break;
    }
    
    if (player_location == ghost_location) {
      printf("\nYou have encountered the ghost!\n");
      printf("GAME OVER\n");
      game_running = false;
    } else {
      printf("This room is %s.\n", room[player_location-1] ? "haunted" : "safe");
    }
  }
  
  return 0;
}