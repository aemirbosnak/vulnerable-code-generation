//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MIN_BATTERY_LEVEL 20

typedef struct {
  int x;
  int y;
  int z;
} Position;

typedef struct {
  int battery_level;
  Position position;
} Drone;

void takeoff(Drone* drone) {
  if (drone->battery_level > MIN_BATTERY_LEVEL) {
    printf("Drone has taken off!\n");
  } else {
    printf("Sorry, the drone's battery level is too low to take off.\n");
  }
}

void hover(Drone* drone) {
  printf("Drone is hovering at position (%d,%d,%d).\n", drone->position.x, drone->position.y, drone->position.z);
}

void land(Drone* drone) {
  printf("Drone has landed at position (%d,%d,%d).\n", drone->position.x, drone->position.y, drone->position.z);
}

void return_home(Drone* drone) {
  printf("Drone is heading back to its home position.\n");
  // code to return the drone to its home position
}

int main() {
  Drone drone = {
    .battery_level = 100,
    .position = {0, 0, 0}
  };

  // code to read inputs from remote control
  int input = 0;

  while (input != -1) {
    printf("Enter a command for the drone (-1 to exit):\n");
    scanf("%d", &input);

    switch (input) {
      case 0:
        takeoff(&drone);
        break;
      case 1:
        hover(&drone);
        break;
      case 2:
        land(&drone);
        break;
      case 3:
        return_home(&drone);
        break;
      default:
        printf("Invalid command!\n");
        break;
    }
  }

  printf("Exiting drone program.\n");
  return 0;
}