//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Define the possible directions
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// Define the maximum number of steps
#define MAX_STEPS 100

// Define the maximum size of the map
#define MAX_SIZE 10

// Define the starting position
#define START_X 0
#define START_Y 0

// Create the map
char map[MAX_SIZE][MAX_SIZE];

// Create the player's position
int player_x = START_X;
int player_y = START_Y;

// Create the player's direction
int player_direction = NORTH;

// Create the main function
int main() {
  // Initialize the map
  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      map[i][j] = ' ';
    }
  }

  // Set the player's position on the map
  map[player_y][player_x] = 'P';

  // Print the map
  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      printf("%c", map[i][j]);
    }
    printf("\n");
  }

  // Get the player's input
  char input;
  printf("Enter a command (N, E, S, W, Q): ");
  scanf(" %c", &input);

  // Process the player's input
  while (input != 'Q') {
    switch (input) {
      case 'N':
        // Move the player north
        if (player_y > 0) {
          map[player_y][player_x] = ' ';
          player_y--;
          map[player_y][player_x] = 'P';
        } else {
          printf("You can't go north, you're at the edge of the map!\n");
        }
        break;
      case 'E':
        // Move the player east
        if (player_x < MAX_SIZE - 1) {
          map[player_y][player_x] = ' ';
          player_x++;
          map[player_y][player_x] = 'P';
        } else {
          printf("You can't go east, you're at the edge of the map!\n");
        }
        break;
      case 'S':
        // Move the player south
        if (player_y < MAX_SIZE - 1) {
          map[player_y][player_x] = ' ';
          player_y++;
          map[player_y][player_x] = 'P';
        } else {
          printf("You can't go south, you're at the edge of the map!\n");
        }
        break;
      case 'W':
        // Move the player west
        if (player_x > 0) {
          map[player_y][player_x] = ' ';
          player_x--;
          map[player_y][player_x] = 'P';
        } else {
          printf("You can't go west, you're at the edge of the map!\n");
        }
        break;
      default:
        // Invalid input
        printf("Invalid input!\n");
        break;
    }

    // Print the map
    for (int i = 0; i < MAX_SIZE; i++) {
      for (int j = 0; j < MAX_SIZE; j++) {
        printf("%c", map[i][j]);
      }
      printf("\n");
    }

    // Get the player's input
    printf("Enter a command (N, E, S, W, Q): ");
    scanf(" %c", &input);
  }

  // Exit the program
  return 0;
}