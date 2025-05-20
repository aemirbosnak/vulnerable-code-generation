//FormAI DATASET v1.0 Category: Robot movement control ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define a struct to represent the robot's position
typedef struct {
  int x;
  int y;
} Position;

// Define a struct to represent a movement command
typedef struct {
  char direction;
  int distance;
} Command;

// Define constants for the maximum x and y values the robot can move to
const int MAX_X = 10;
const int MAX_Y = 10;

// Global variable to store the current position of the robot
Position robot_position = {0, 0};

// Define a function to move the robot in a given direction by a given distance
void move_robot(char direction, int distance) {
  switch(direction) {
    case 'U':
      robot_position.y += distance;
      break;
    case 'D':
      robot_position.y -= distance;
      break;
    case 'L':
      robot_position.x -= distance;
      break;
    case 'R':
      robot_position.x += distance;
      break;
    default:
      printf("Invalid direction: %c\n", direction);
  }
  
  // Ensure that the robot's new position stays within the grid
  if(robot_position.x < 0) {
    robot_position.x = 0;
  } else if(robot_position.x > MAX_X) {
    robot_position.x = MAX_X;
  }
  
  if(robot_position.y < 0) {
    robot_position.y = 0;
  } else if(robot_position.y > MAX_Y) {
    robot_position.y = MAX_Y;
  }
}

// Define a function to parse a movement command from a string
bool parse_command(char* command_string, Command* command) {
  int length = strlen(command_string);
  
  if(length < 2 || length > 3) {
    return false;
  }
  
  char direction = command_string[0];
  
  if(direction != 'U' && direction != 'D' && direction != 'L' && direction != 'R') {
    return false;
  }
  
  int distance = atoi(&command_string[1]);
  
  if(distance < 1 || distance > 3) {
    return false;
  }
  
  command->direction = direction;
  command->distance = distance;
  
  return true;
}

int main() {
  char command_string[4];
  Command command;
  
  // Loop to continually accept commands until the user types "q"
  while(true) {
    printf("Enter a movement command for the robot (e.g. U2, D1, L3, R2) or 'q' to quit: ");
    scanf("%s", command_string);
    
    if(command_string[0] == 'q') {
      break;
    }
    
    if(parse_command(command_string, &command)) {
      move_robot(command.direction, command.distance);
      printf("Robot moved to position (%d, %d)\n", robot_position.x, robot_position.y);
    } else {
      printf("Invalid command: %s\n", command_string);
    }
  }
  
  return 0;
}