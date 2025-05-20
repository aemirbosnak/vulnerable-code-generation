//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand((unsigned) time(NULL)); // initialize random seed

  // define variables
  int player_health = 100;
  int ghost_health = 50;
  int player_choice;
  int ghost_choice;

  // print welcome message
  printf("Welcome to the Haunted House Simulator!\n");

  // main game loop
  while (1) {
    // print player and ghost health
    printf("Your health: %d\n", player_health);
    printf("Ghost health: %d\n", ghost_health);

    // prompt player for choice
    printf("What do you want to do?\n");
    printf("1. Attack\n");
    printf("2. Run\n");
    scanf("%d", &player_choice);

    // process player choice
    switch (player_choice) {
      case 1:
        // generate random ghost choice
        ghost_choice = rand() % 2 + 1;

        if (ghost_choice == 1) {
          // player wins
          printf("You attacked the ghost and defeated it!\n");
          ghost_health = 0;
        } else {
          // ghost wins
          printf("You attacked the ghost but it dodged your attack!\n");
          printf("The ghost attacked you and dealt 10 damage.\n");
          player_health -= 10;
        }
        break;
      case 2:
        // player runs away
        printf("You ran away from the haunted house.\n");
        return 0;
      default:
        // invalid input
        printf("Invalid input. Please try again.\n");
        break;
    }

    // check if game is over
    if (player_health <= 0 || ghost_health <= 0) {
      // print game over message and exit
      if (player_health <= 0) {
        printf("You have been defeated by the ghost. Game over.\n");
      } else {
        printf("Congratulations! You have defeated the ghost. You win!\n");
      }
      return 0;
    }
  }
}