//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

#define MAX_WAYPOINTS 10

typedef struct Waypoint {
  int x;
  int y;
  char name[20];
} Waypoint;

Waypoint waypoints[MAX_WAYPOINTS] = {
  {1, 1, "Start"},
  {4, 2, "Second Point"},
  {6, 5, "Third Point"},
  {8, 8, "Final Destination"}
};

int main() {
  int current_x = 0;
  int current_y = 0;

  char current_direction = 'N';

  char input_command[20];

  while (1) {
    // Display the map
    for (int y = 0; y < MAP_HEIGHT; y++) {
      for (int x = 0; x < MAP_WIDTH; x++) {
        if (x == current_x && y == current_y) {
          printf("X");
        } else if (waypoints[0].x == x && waypoints[0].y == y) {
          printf("S");
        } else if (waypoints[3].x == x && waypoints[3].y == y) {
          printf("F");
        } else {
          printf(".");
        }
      }
      printf("\n");
    }

    // Get the user input
    printf("Enter command (N/S/E/W/R/L): ");
    scanf("%s", input_command);

    // Process the user input
    switch (input_command[0]) {
      case 'N':
        current_direction = 'N';
        current_y--;
        break;
      case 'S':
        current_direction = 'S';
        current_y++;
        break;
      case 'E':
        current_direction = 'E';
        current_x++;
        break;
      case 'W':
        current_direction = 'W';
        current_x--;
        break;
      case 'R':
        current_direction = 'R';
        break;
      case 'L':
        current_direction = 'L';
        break;
      default:
        break;
    }

    // Move the cursor
    switch (current_direction) {
      case 'N':
        current_y--;
        break;
      case 'S':
        current_y++;
        break;
      case 'E':
        current_x++;
        break;
      case 'W':
        current_x--;
        break;
      default:
        break;
    }

    // Check if the user has reached the final destination
    if (current_x == waypoints[3].x && current_y == waypoints[3].y) {
      printf("Congratulations! You have reached your destination!");
      break;
    }
  }

  return 0;
}