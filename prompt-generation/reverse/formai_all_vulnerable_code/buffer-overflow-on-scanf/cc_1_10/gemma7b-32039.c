//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

void play_game() {
  // Declare variables
  int choice, inventory[] = {0, 0, 0}, current_room = 1;

  // Create a map of rooms
  struct room {
    char name[20];
    int connections[4];
  } rooms[] = {
    {"The Hallway", {2, 3, 4, 0}},
    {"The Kitchen", {1, 5, 0, 0}},
    {"The Dining Room", {0, 0, 6, 0}},
    {"The Library", {0, 0, 0, 0}},
    {"The Bedroom", {0, 0, 0, 0}},
    {"The Bathroom", {0, 0, 0, 0}}
  };

  // Loop until the player wins or loses
  while (1) {
    // Display the current room
    printf("You are in the %s.\n", rooms[current_room - 1].name);

    // List the available choices
    printf("What do you want to do? (1) Go north, (2) Go south, (3) Go east, (4) Go west:\n");

    // Get the player's choice
    scanf("%d", &choice);

    // Check if the player's choice is valid
    if (choice < 1 || choice > 4) {
      printf("Invalid choice.\n");
      continue;
    }

    // Move the player to the next room
    current_room = rooms[current_room - 1].connections[choice - 1];

    // If the player has won, they are congratulated
    if (current_room == 6) {
      printf("You have won! Congratulations!\n");
      break;
    }

    // If the player has lost, they are told to try again
    else if (current_room == 0) {
      printf("You have lost. Try again.\n");
      break;
    }
  }

  // Free the memory allocated for the inventory and rooms
  free(inventory);
  free(rooms);
}

int main() {
  play_game();

  return 0;
}