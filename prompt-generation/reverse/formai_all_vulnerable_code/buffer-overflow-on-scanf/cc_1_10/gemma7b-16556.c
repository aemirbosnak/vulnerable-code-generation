//Gemma-7B DATASET v1.0 Category: Drone Remote Control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CONTROLS 5

typedef struct Controller {
  int pin;
  char name[20];
} Controller;

Controller controllers[NUM_CONTROLS] = {
  {1, "Throttle"},
  {2, "Yaw"},
  {3, "Pitch"},
  {4, "Roll"},
  {5, "Landing Gear"}
};

void handle_controller(int controller_index) {
  printf("Enter command for %s: ", controllers[controller_index].name);
  char command[20];
  scanf("%s", command);

  switch (command[0]) {
    case 'F':
      printf("Forward!\n");
      break;
    case 'B':
      printf("Backwards!\n");
      break;
    case 'L':
      printf("Left!\n");
      break;
    case 'R':
      printf("Right!\n");
      break;
    case 'S':
      printf("Stop!\n");
      break;
    default:
      printf("Invalid command.\n");
  }
}

int main() {
  for (int i = 0; i < NUM_CONTROLS; i++) {
    handle_controller(i);
  }

  return 0;
}