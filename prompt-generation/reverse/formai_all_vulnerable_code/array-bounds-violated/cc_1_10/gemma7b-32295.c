//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DIRECTIONS 4
#define MAX_WAYPOINTS 10

typedef struct Waypoint {
  int x, y;
  char name[20];
} Waypoint;

int main() {
  time_t t;
  int i, j, k;
  char input;
  int current_direction = 0;
  int current_waypoint = 0;
  Waypoint waypoints[MAX_WAYPOINTS] = {{0, 0, "Start"},
    {5, 5, "First Stop"},
    {10, 10, "Second Stop"},
    {15, 15, "Final Destination"}};

  t = time(NULL);
  srand(t);

  printf("Welcome to the GPS Navigation System!\n");
  printf("Press 'h' for help, 'c' to continue, or 'q' to quit.\n");

  while (1) {
    printf("Current location: (%d, %d)\n", waypoints[current_waypoint].x, waypoints[current_waypoint].y);
    printf("Current direction: %s\n", waypoints[current_waypoint].name);

    input = getchar();

    switch (input) {
      case 'h':
        printf("Available directions:\n");
        for (k = 0; k < MAX_DIRECTIONS; k++) {
          printf("%d. %s\n", k + 1, waypoints[k].name);
        }
        break;
      case 'c':
        current_direction = (current_direction + 1) % MAX_DIRECTIONS;
        current_waypoint++;
        if (current_waypoint >= MAX_WAYPOINTS - 1) {
          printf("You have reached your destination!\n");
          break;
        }
        printf("Changing direction to: %s\n", waypoints[current_direction].name);
        break;
      case 'q':
        printf("Thank you for using the GPS Navigation System. Goodbye!\n");
        exit(0);
    }
  }
}