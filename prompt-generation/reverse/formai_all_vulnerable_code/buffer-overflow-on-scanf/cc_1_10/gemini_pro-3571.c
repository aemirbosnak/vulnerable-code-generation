//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define EXIT 5

typedef struct {
  int x;
  int y;
  int z;
} Position;

Position dronePosition = {0, 0, 0};

void moveDrone(int direction) {
  switch (direction) {
    case UP:
      dronePosition.z++;
      break;
    case DOWN:
      dronePosition.z--;
      break;
    case LEFT:
      dronePosition.x--;
      break;
    case RIGHT:
      dronePosition.x++;
      break;
    case EXIT:
      exit(0);
  }
}

int main() {
  printf("Welcome to the Drone Remote Control Simulator!\n");
  printf("Use the following commands to control the drone:\n");
  printf("1 - Up\n");
  printf("2 - Down\n");
  printf("3 - Left\n");
  printf("4 - Right\n");
  printf("5 - Exit\n");

  while (1) {
    int direction;
    printf("Enter a command: ");
    scanf("%d", &direction);
    moveDrone(direction);
    printf("Drone position: (%d, %d, %d)\n", dronePosition.x, dronePosition.y,
           dronePosition.z);
  }

  return 0;
}