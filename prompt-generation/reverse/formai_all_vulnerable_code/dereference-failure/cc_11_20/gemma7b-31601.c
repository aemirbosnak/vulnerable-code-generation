//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
  system("clear");
  printf("Welcome to the curious world of Text-Based Adventure Game!\n");

  // Create a map of rooms
  char **map = malloc(5 * sizeof(char *));
  for (int i = 0; i < 5; i++) {
    map[i] = malloc(10 * sizeof(char));
  }

  // Define the room descriptions
  map[0][0] = 'A';
  map[0][1] = 'A cozy living room with a fireplace.';
  map[1][0] = 'B';
  map[1][1] = 'A spacious kitchen with a dining table.';
  map[2][0] = 'C';
  map[2][1] = 'A mysterious hallway with a locked door.';
  map[3][0] = 'D';
  map[3][1] = 'A library with a bookshelf and a desk.';
  map[4][0] = 'E';
  map[4][1] = 'A secret room with a treasure chest.';

  // Initialize the player's position
  int x = 0, y = 0;

  // Game loop
  while (1) {
    // Display the room description
    printf("%s\n", map[x][y]);

    // Get the player's input
    char input;
    scanf("Enter your move (north, south, east, west): ", &input);

    // Move the player
    switch (input) {
      case 'n':
        if (y > 0) {
          y--;
        } else {
          printf("You cannot go north.\n");
        }
        break;
      case 's':
        if (y < 4) {
          y++;
        } else {
          printf("You cannot go south.\n");
        }
        break;
      case 'e':
        if (x < 4) {
          x++;
        } else {
          printf("You cannot go east.\n");
        }
        break;
      case 'w':
        if (x > 0) {
          x--;
        } else {
          printf("You cannot go west.\n");
        }
        break;
      default:
        printf("Invalid input.\n");
    }

    // Check if the player has won or lost
    if (map[x][y] == 'T') {
      printf("You have won! Congratulations!\n");
      break;
    } else if (map[x][y] == 'L') {
      printf("You have lost. Game over.\n");
      break;
    }
  }

  // Free the memory allocated for the map
  for (int i = 0; i < 5; i++) {
    free(map[i]);
  }
  free(map);

  return 0;
}