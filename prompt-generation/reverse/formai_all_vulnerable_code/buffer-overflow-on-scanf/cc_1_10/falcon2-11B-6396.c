//Falcon2-11B DATASET v1.0 Category: Robot movement control ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE 100
#define MAX_STRING 100
#define MAX_NUM 100
#define MAX_COMMANDS 5

typedef struct robot_command_t {
  int command_id;
  char command[MAX_STRING];
  int params[MAX_NUM];
} robot_command_t;

typedef struct robot_t {
  int state;
  int position_x;
  int position_y;
  int orientation;
} robot_t;

int get_command_id(char* command) {
  if (strcmp(command, "move") == 0) {
    return 0;
  } else if (strcmp(command, "turn") == 0) {
    return 1;
  } else if (strcmp(command, "stop") == 0) {
    return 2;
  } else if (strcmp(command, "get_position") == 0) {
    return 3;
  } else if (strcmp(command, "set_position") == 0) {
    return 4;
  } else {
    return -1;
  }
}

void execute_command(robot_command_t* command, robot_t* robot) {
  switch (command->command_id) {
    case 0: // move
      if (command->params[0] == 1) {
        robot->orientation += 90;
      } else if (command->params[0] == 2) {
        robot->orientation -= 90;
      } else if (command->params[0] == 3) {
        robot->orientation += 180;
      } else if (command->params[0] == 4) {
        robot->orientation -= 180;
      } else {
        printf("Invalid orientation parameter: %d\n", command->params[0]);
      }
      break;
    case 1: // turn
      if (command->params[0] == 1) {
        robot->orientation += 90;
      } else if (command->params[0] == 2) {
        robot->orientation -= 90;
      } else if (command->params[0] == 3) {
        robot->orientation += 180;
      } else if (command->params[0] == 4) {
        robot->orientation -= 180;
      } else {
        printf("Invalid orientation parameter: %d\n", command->params[0]);
      }
      break;
    case 2: // stop
      robot->orientation = 0;
      break;
    case 3: // get_position
      printf("Robot position: (%d, %d)\n", robot->position_x, robot->position_y);
      break;
    case 4: // set_position
      if (command->params[0] == 1) {
        robot->position_x = command->params[1];
      } else if (command->params[0] == 2) {
        robot->position_y = command->params[1];
      } else {
        printf("Invalid parameter: %d\n", command->params[0]);
      }
      break;
    default:
      printf("Invalid command: %s\n", command->command);
  }
}

int main() {
  robot_t robot;
  robot.state = 0;
  robot.position_x = 0;
  robot.position_y = 0;
  robot.orientation = 0;

  robot_command_t commands[MAX_COMMANDS];

  printf("Enter commands (move, turn, stop, get_position, set_position):\n");
  int command_count = 0;
  int command_id;
  char command[MAX_STRING];
  int params[MAX_NUM];
  int i;

  while (1) {
    printf("Command %d: ", command_count + 1);
    scanf("%s", command);
    if (strcmp(command, "quit") == 0) {
      break;
    }
    command_id = get_command_id(command);
    if (command_id == -1) {
      printf("Invalid command: %s\n", command);
      continue;
    }
    printf("Parameters: ");
    for (i = 0; i < command_count; i++) {
      scanf("%d", &params[i]);
    }
    commands[command_count].command_id = command_id;
    strcpy(commands[command_count].command, command);
    strcpy(commands[command_count].params[0], "1");
    for (i = 1; i < MAX_NUM; i++) {
      commands[command_count].params[i] = params[i - 1];
    }
    command_count++;

    execute_command(&commands[command_count - 1], &robot);
  }

  return 0;
}