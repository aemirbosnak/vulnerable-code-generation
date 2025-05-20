//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: brave
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
  int room, choice, treasure, ghost;
  char direction;
  srand(time(NULL)); // set random seed

  printf("Welcome to the haunted house simulator!\n\n");

  // start in the foyer of the house
  room = 1;

  // main game loop
  while (1) {
    printf("You are in room %d.\n", room);
    printf("You can go (N)orth, (S)outh, (E)ast, or (W)est.\n");
    printf("What do you do? ");
    scanf(" %c", &direction);

    // randomly encounter a ghost
    if (rand() % 4 == 0) {
      ghost = rand() % 3 + 1;
      printf("\nOh no! You have encountered a ghost in room %d!\n", room);
      printf("The ghost has %d health. What do you do?\n", ghost);
      printf("(1) Fight\n");
      printf("(2) Run\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      // choice 1: fight ghost
      if (choice == 1) {
        printf("You choose to fight the ghost!\n");
        printf("You attack the ghost with your sword!\n");

        // determine outcome of fight
        if (rand() % 2 == 0) {
          printf("You defeated the ghost!\n");
          printf("You feel a sense of accomplishment as you continue on your journey.\n");
        } else {
          printf("The ghost defeated you!\n");
          printf("You are dead.\n");
          return 0;
        }
      // choice 2: run away from ghost
      } else {
        printf("You choose to run away from the ghost!\n");

        // determine outcome of run
        if (rand() % 2 == 0) {
          printf("You successfully ran away from the ghost.\n");
          printf("You feel relieved as you continue on your journey.\n");
        } else {
          printf("You failed to run away from the ghost!\n");
          printf("The ghost defeated you!\n");
          printf("You are dead.\n");
          return 0;
        }
      }
    }

    // update room based on direction chosen
    switch (direction) {
      case 'N':
        if (room == 3) {
          treasure = rand() % 10 + 1;
          printf("\nYou found a treasure chest in room %d!\n", room);
          printf("It contains %d gold. Congratulations!\n", treasure);
        }
        if (room == 4) {
          printf("\nYou have found the exit!\n");
          printf("Congratulations, you have escaped the haunted house!\n");
          return 0;
        }
        if (room == 5) {
          printf("\nYou cannot go north from room %d.\n", room);
        } else {
          room += 1;
        }
        break;
      case 'S':
        if (room == 2) {
          printf("\nYou cannot go south from room %d.\n", room);
        } else {
          room -= 1;
        }
        break;
      case 'E':
        if (room == 1 || room == 2 || room == 3) {
          printf("\nYou cannot go east from room %d.\n", room);
        } else {
          room += 2;
        }
        break;
      case 'W':
        if (room == 1) {
          printf("\nYou cannot go west from room %d.\n", room);
        } else {
          room -= 2;
        }
        break;
      default:
        printf("\nInvalid direction! Please try again.\n");
        break;
    }
  }

  return 0;
}