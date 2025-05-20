//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // Seed random generator with current time

  printf("Welcome to the Haunted House Simulator!\n");
  printf("Press any key to continue...\n");
  getchar();

  // Begin the simulation
  int current_room = 1;
  int has_key = 0;
  int ghost_spotted = 0;

  // Loop until player reaches the end
  while (current_room <= 5) {
    printf("You are in room %d. ", current_room);

    // Randomly determine if there is a ghost in the room
    int ghost_exists = rand() % 2;
    if (ghost_exists && !ghost_spotted) {
      printf("You see a ghost!\n");
      ghost_spotted = 1;
    } else {
      printf("The room is quiet.\n");
    }

    // Check if there is a key in the room
    if (current_room == 3 && !has_key) {
      printf("You found a key!\n");
      has_key = 1;
    }

    // Ask player what to do next
    char choice;
    printf("What do you want to do?\n");
    printf("a) Go to the next room\n");
    printf("b) Use the key to unlock the door\n");
    printf("c) Quit the game\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    switch (choice) {
      case 'a':
        current_room++;
        break;
      case 'b':
        if (current_room == 4 && has_key) {
          printf("You unlocked the door and escaped the haunted house!\n");
          return 0;
        } else {
          printf("You can't use the key here.\n");
        }
        break;
      case 'c':
        printf("Thanks for playing the Haunted House Simulator!\n");
        return 0;
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }

    printf("\n");
  }

  printf("Oops, you got lost in the haunted house and never made it out!\n");
  printf("Thanks for playing the Haunted House Simulator!\n");

  return 0;
}