//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Drone {
  int altitude;
  int x;
  int y;
};

typedef struct Drone Drone;

void takeoff(Drone *drone) {
  drone->altitude = 10;
  printf("Drone has taken off to altitude %d\n", drone->altitude);
}

void land(Drone *drone) {
  if (drone->altitude > 0) {
    drone->altitude = 0;
    printf("Drone has landed\n");
  } else {
    printf("Drone is already on the ground\n");
  }
}

void move(Drone *drone, int x, int y) {
  drone->x = x;
  drone->y = y;
  printf("Drone has moved to position (%d, %d)\n", drone->x, drone->y);
}

void ascend(Drone *drone, int altitude) {
  if (altitude > drone->altitude) {
    printf("Drone has ascended to altitude %d\n", altitude);
    drone->altitude = altitude;
  } else {
    printf("Drone is already at a higher altitude than %d\n", altitude);
  }
}

void descend(Drone *drone, int altitude) {
  if (altitude < drone->altitude) {
    printf("Drone has descended to altitude %d\n", altitude);
    drone->altitude = altitude;
  } else {
    printf("Drone is already at a lower altitude than %d\n", altitude);
  }
}

int main() {
  Drone my_drone;

  my_drone.altitude = 0;
  my_drone.x = 0;
  my_drone.y = 0;

  printf("Welcome to the Drone Remote Control Program!\n");

  while (1) {
    char command[100];
    printf("\nEnter a command: ");
    fgets(command, 100, stdin);

    if (strcmp(command, "takeoff\n") == 0) {
      takeoff(&my_drone);
    } else if (strcmp(command, "land\n") == 0) {
      land(&my_drone);
    } else if (strncmp(command, "move", 4) == 0) {
      int x, y;
      sscanf(command, "move %d %d", &x, &y);
      move(&my_drone, x, y);
    } else if (strncmp(command, "ascend", 6) == 0) {
      int altitude;
      sscanf(command, "ascend %d", &altitude);
      ascend(&my_drone, altitude);
    } else if (strncmp(command, "descend", 7) == 0) {
      int altitude;
      sscanf(command, "descend %d", &altitude);
      descend(&my_drone, altitude);
    } else if (strcmp(command, "exit\n") == 0) {
      break;
    } else {
      printf("Invalid command\n");
    }
  }

  return 0;
}