//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROBOT_NAME_LENGTH 20
#define MAX_ROBOT_INSTRUCTIONS 100

typedef struct Robot {
  char name[MAX_ROBOT_NAME_LENGTH];
  int x;
  int y;
  int orientation; // 0 = north, 1 = east, 2 = south, 3 = west
  char instructions[MAX_ROBOT_INSTRUCTIONS];
  int num_instructions;
} Robot;

void print_robot_instructions(Robot *robot) {
  printf("Robot %s instructions:\n", robot->name);
  for (int i = 0; i < robot->num_instructions; i++) {
    printf("%c", robot->instructions[i]);
  }
  printf("\n");
}

void move_robot(Robot *robot) {
  for (int i = 0; i < robot->num_instructions; i++) {
    switch (robot->instructions[i]) {
      case 'F':
        if (robot->orientation == 0) {
          robot->y++;
        } else if (robot->orientation == 1) {
          robot->x++;
        } else if (robot->orientation == 2) {
          robot->y--;
        } else if (robot->orientation == 3) {
          robot->x--;
        }
        break;
      case 'R':
        robot->orientation = (robot->orientation + 1) % 4;
        break;
      case 'L':
        robot->orientation = (robot->orientation - 1 + 4) % 4;
        break;
    }
  }
}

int main() {
  // Create a new robot
  Robot robot;

  // Get the robot's name from the user
  printf("Enter the robot's name: ");
  scanf("%s", robot.name);

  // Get the robot's instructions from the user
  printf("Enter the robot's instructions (F, R, L): ");
  scanf("%s", robot.instructions);

  // Set the robot's initial position and orientation
  robot.x = 0;
  robot.y = 0;
  robot.orientation = 0;

  // Parse the robot's instructions
  robot.num_instructions = strlen(robot.instructions);

  // Print the robot's instructions
  print_robot_instructions(&robot);

  // Move the robot
  move_robot(&robot);

  // Print the robot's final position and orientation
  printf("Robot %s has moved to (%d, %d) and is facing %d degrees clockwise from north.\n", robot.name, robot.x, robot.y, robot.orientation * 90);

  return 0;
}