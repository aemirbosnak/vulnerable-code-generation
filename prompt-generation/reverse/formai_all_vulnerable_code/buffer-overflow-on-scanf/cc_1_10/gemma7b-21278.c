//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WAYPOINTS 10
#define MAX_DISTANCE 1000

typedef struct waypoint {
  char name[20];
  int x, y;
} waypoint;

waypoint waypoints[MAX_WAYPOINTS] = {
  {"Start", 0, 0},
  {"East", 500, 0},
  {"South", 500, -500},
  {"West", 0, -500},
  {"North", 0, 0}
};

int main() {
  int current_waypoint = 0;
  int distance_traveled = 0;
  char input;

  time_t t = time(NULL);
  srand(t);

  while (distance_traveled < MAX_DISTANCE) {
    // Display current waypoint and distance traveled
    printf("Current waypoint: %s\n", waypoints[current_waypoint].name);
    printf("Distance traveled: %d miles\n", distance_traveled);

    // Get user input
    printf("Enter 'n' to navigate north, 's' to navigate south, 'e' to navigate east, 'w' to navigate west: ");
    scanf(" %c", &input);

    // Calculate new direction
    switch (input) {
      case 'n':
        current_waypoint++;
        distance_traveled += rand() % 50;
        break;
      case 's':
        current_waypoint--;
        distance_traveled += rand() % 50;
        break;
      case 'e':
        distance_traveled += rand() % 50;
        break;
      case 'w':
        distance_traveled += rand() % 50;
        break;
      default:
        printf("Invalid input.\n");
    }

    // Check if new waypoint is valid
    if (current_waypoint >= MAX_WAYPOINTS) {
      current_waypoint = MAX_WAYPOINTS - 1;
    } else if (current_waypoint < 0) {
      current_waypoint = 0;
    }
  }

  // Final destination
  printf("Congratulations! You have reached your final destination: %s\n", waypoints[current_waypoint].name);

  return 0;
}