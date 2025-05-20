//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL));
  int room = 1;
  int ghostInRoom = 0;
  int gameWon = 0;

  printf("Welcome to the Haunted House Simulator\n\n");

  while (!gameWon) {
    printf("You are in room %d\n", room);

    // Check if there is a ghost in the room
    if (ghostInRoom) {
      printf("You hear spooky noises and see a ghost\n");
      printf("Game over\n");
      exit(0);
    }

    // Check for winning condition
    if (room == 10) {
      printf("You've made it out of the haunted house alive!\n");
      printf("Congratulations!\n");
      gameWon = 1;
      break;
    }

    printf("Where would you like to go? (enter 1 or 2)\n");
    int direction;
    scanf("%d", &direction);

    if (direction == 1) {
      printf("You walk down the hallway\n");
      room++;
    } else if (direction == 2) {
      printf("You open the door to another room\n");
      room++;
      // 20% chance of there being a ghost in the room
      if (rand() % 5 == 0) {
        ghostInRoom = 1;
      }
    } else {
      printf("Invalid input. Please enter 1 or 2\n");
    }
  }

  return 0;
}