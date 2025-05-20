//Gemma-7B DATASET v1.0 Category: Robot movement control ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define FORWARD 0
#define RIGHT 1
#define LEFT 2
#define BACK 3

void move_robot(int direction) {
  switch (direction) {
    case FORWARD:
      printf("The robot moves forward.\n");
      break;
    case RIGHT:
      printf("The robot moves right.\n");
      break;
    case LEFT:
      printf("The robot moves left.\n");
      break;
    case BACK:
      printf("The robot moves back.\n");
      break;
  }
}

int main() {
  int choice;

  printf("Welcome to the robot control center!\n");
  printf("Please select an action:\n");
  printf("1. Forward\n");
  printf("2. Right\n");
  printf("3. Left\n");
  printf("4. Back\n");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      move_robot(FORWARD);
      break;
    case 2:
      move_robot(RIGHT);
      break;
    case 3:
      move_robot(LEFT);
      break;
    case 4:
      move_robot(BACK);
      break;
  }

  return 0;
}