//Code Llama-13B DATASET v1.0 Category: Haunted House Simulator ; Style: synchronous
// Haunted House Simulator
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int rand_num(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

// Function to check if a player is alive
int is_alive(int health) {
  return health > 0;
}

// Function to print the menu
void print_menu() {
  printf("Welcome to the Haunted House Simulator!\n");
  printf("1. Play the game\n");
  printf("2. Quit the game\n");
  printf("Choose an option: ");
}

// Function to play the game
void play_game() {
  int health = 100;
  int choice = 0;

  while (is_alive(health)) {
    print_menu();
    scanf("%d", &choice);

    if (choice == 1) {
      // Check if player is in the kitchen
      if (rand_num(0, 100) <= 20) {
        // Ghost appears and attacks
        health -= 10;
        printf("You were attacked by a ghost!\n");
      }
      // Check if player is in the living room
      else if (rand_num(0, 100) <= 40) {
        // Ghost appears and attacks
        health -= 15;
        printf("You were attacked by a ghost!\n");
      }
      // Check if player is in the bedroom
      else if (rand_num(0, 100) <= 60) {
        // Ghost appears and attacks
        health -= 20;
        printf("You were attacked by a ghost!\n");
      }
      // Check if player is in the attic
      else if (rand_num(0, 100) <= 80) {
        // Ghost appears and attacks
        health -= 25;
        printf("You were attacked by a ghost!\n");
      }
      // Check if player is in the basement
      else if (rand_num(0, 100) <= 100) {
        // Ghost appears and attacks
        health -= 30;
        printf("You were attacked by a ghost!\n");
      }
    } else if (choice == 2) {
      break;
    }
  }

  if (is_alive(health)) {
    printf("You survived the haunted house!\n");
  } else {
    printf("You died in the haunted house.\n");
  }
}

int main() {
  srand(time(NULL));
  play_game();
  return 0;
}