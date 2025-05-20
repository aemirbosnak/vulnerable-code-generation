//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ghost_attack();
void ghost_cry();
void ghost_move();
void restart_game();

int main() {

  const int NUM_ROOMS = 5;
  int current_room = 1;
  char player_choice;
  int ghost_chance = 0;

  srand(time(NULL));

  printf("Welcome to the Haunted House Simulator\n\n");

  while (current_room <= NUM_ROOMS) {

    printf("You are in room %d. ", current_room);
    printf("There are two doors ahead.\n");
    printf("What do you do? (A or B)\n");

    ghost_chance = (rand() % 10) + 1;

    if (ghost_chance <= 3) {
      ghost_attack();
      restart_game();
      continue;
    }

    scanf(" %c", &player_choice);

    while (player_choice != 'A' && player_choice != 'B') {
      printf("Invalid choice. Please choose A or B.\n");
      scanf(" %c", &player_choice);
    }

    if (player_choice == 'A') {
      printf("You chose door A.\n");
      ghost_chance = (rand() % 10) + 1;
      if (ghost_chance <= 5) {
        ghost_cry();
      }
      current_room ++;
    } else {
      printf("You chose door B.\n");
      ghost_chance = (rand() % 10) + 1;
      if (ghost_chance <= 5) {
        ghost_move();
        current_room --;
      } else {
        current_room ++;
      }
    }
  }

  printf("You have escaped the haunted house!\n");
  printf("Thanks for playing.\n");

  return 0;
}

void ghost_attack() {
  printf("\nOh no! You were attacked by a ghost!\n");
}

void ghost_cry() {
  printf("You hear a ghostly cry from the other room.\n");
}

void ghost_move() {
  printf("You see a ghostly figure moving in the hallway.\n");
}

void restart_game() {
  char restart_choice;
  printf("\nDo you want to restart the game? (Y/N)\n");
  scanf(" %c", &restart_choice);

  while (restart_choice != 'Y' && restart_choice != 'N') {
    printf("Invalid choice. Please choose Y or N.\n");
    scanf(" %c", &restart_choice);
  }

  if (restart_choice == 'Y') {
    main();
  } else {
    printf("Thanks for playing.\n");
    exit(0);
  }
}