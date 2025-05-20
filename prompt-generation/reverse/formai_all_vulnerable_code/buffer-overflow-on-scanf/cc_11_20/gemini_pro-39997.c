//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize the random number generator.
  srand(time(NULL));

  // Create a haunted house.
  struct room {
    char *description;
    int num_doors;
    int doors[4];
  };

  struct room rooms[5];

  rooms[0].description = "You are in the foyer. There is a door to the north, a door to the east, and a door to the west.";
  rooms[0].num_doors = 3;
  rooms[0].doors[0] = 1;
  rooms[0].doors[1] = 2;
  rooms[0].doors[2] = 3;

  rooms[1].description = "You are in the living room. There is a door to the south, a door to the east, and a door to the west.";
  rooms[1].num_doors = 3;
  rooms[1].doors[0] = 0;
  rooms[1].doors[1] = 2;
  rooms[1].doors[2] = 3;

  rooms[2].description = "You are in the kitchen. There is a door to the south, a door to the east, and a door to the west.";
  rooms[2].num_doors = 3;
  rooms[2].doors[0] = 0;
  rooms[2].doors[1] = 1;
  rooms[2].doors[2] = 3;

  rooms[3].description = "You are in the dining room. There is a door to the south, a door to the east, and a door to the west.";
  rooms[3].num_doors = 3;
  rooms[3].doors[0] = 0;
  rooms[3].doors[1] = 1;
  rooms[3].doors[2] = 2;

  rooms[4].description = "You are in the basement. There is a door to the north.";
  rooms[4].num_doors = 1;
  rooms[4].doors[0] = 0;

  // Start the game.
  int current_room = 0;

  while (1) {
    // Print the description of the current room.
    printf("%s\n", rooms[current_room].description);

    // Get the player's input.
    char input[10];
    printf("What do you want to do?\n");
    scanf("%s", input);

    // Parse the player's input.
    if (strcmp(input, "n") == 0) {
      // Move to the north.
      if (rooms[current_room].doors[0] != -1) {
        current_room = rooms[current_room].doors[0];
      } else {
        printf("There is no door to the north.\n");
      }
    } else if (strcmp(input, "e") == 0) {
      // Move to the east.
      if (rooms[current_room].doors[1] != -1) {
        current_room = rooms[current_room].doors[1];
      } else {
        printf("There is no door to the east.\n");
      }
    } else if (strcmp(input, "s") == 0) {
      // Move to the south.
      if (rooms[current_room].doors[2] != -1) {
        current_room = rooms[current_room].doors[2];
      } else {
        printf("There is no door to the south.\n");
      }
    } else if (strcmp(input, "w") == 0) {
      // Move to the west.
      if (rooms[current_room].doors[3] != -1) {
        current_room = rooms[current_room].doors[3];
      } else {
        printf("There is no door to the west.\n");
      }
    } else if (strcmp(input, "q") == 0) {
      // Quit the game.
      break;
    } else {
      // Invalid input.
      printf("Invalid input.\n");
    }
  }

  // End the game.
  printf("Thank you for playing!\n");

  return 0;
}