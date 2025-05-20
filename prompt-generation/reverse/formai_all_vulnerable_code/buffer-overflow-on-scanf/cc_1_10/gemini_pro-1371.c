//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 100
#define MAX_COMMAND_LEN 100

// Define the drone's state
typedef enum {
  DISARMED,
  ARMED,
  FLYING
} DroneState;

// Define the command types
typedef enum {
  TAKEOFF,
  LAND,
  MOVE_FORWARD,
  MOVE_BACKWARD,
  MOVE_LEFT,
  MOVE_RIGHT,
  ROTATE_LEFT,
  ROTATE_RIGHT,
  FLIP,
  CALIBRATE
} CommandType;

// Define the command structure
typedef struct {
  CommandType type;
  char *command;
} Command;

// Create an array of commands
Command commands[MAX_COMMANDS];

// Initialize the drone's state
DroneState state = DISARMED;

// Initialize the number of commands
int num_commands = 0;

// Function to add a command to the array
void add_command(CommandType type, char *command) {
  commands[num_commands].type = type;
  commands[num_commands].command = command;
  num_commands++;
}

// Function to parse a command
CommandType parse_command(char *command) {
  // Convert the command to lowercase
  for (int i = 0; command[i] != '\0'; i++) {
    command[i] = tolower(command[i]);
  }

  // Check if the command is valid
  if (strcmp(command, "takeoff") == 0) {
    return TAKEOFF;
  } else if (strcmp(command, "land") == 0) {
    return LAND;
  } else if (strcmp(command, "move forward") == 0) {
    return MOVE_FORWARD;
  } else if (strcmp(command, "move backward") == 0) {
    return MOVE_BACKWARD;
  } else if (strcmp(command, "move left") == 0) {
    return MOVE_LEFT;
  } else if (strcmp(command, "move right") == 0) {
    return MOVE_RIGHT;
  } else if (strcmp(command, "rotate left") == 0) {
    return ROTATE_LEFT;
  } else if (strcmp(command, "rotate right") == 0) {
    return ROTATE_RIGHT;
  } else if (strcmp(command, "flip") == 0) {
    return FLIP;
  } else if (strcmp(command, "calibrate") == 0) {
    return CALIBRATE;
  } else {
    return -1;
  }
}

// Function to execute a command
void execute_command(CommandType type) {
  switch (type) {
    case TAKEOFF:
      if (state == DISARMED) {
        state = ARMED;
        printf("Drone armed.\n");
      } else if (state == ARMED) {
        state = FLYING;
        printf("Drone taking off.\n");
      } else {
        printf("Error: Drone is already flying.\n");
      }
      break;
    case LAND:
      if (state == FLYING) {
        state = ARMED;
        printf("Drone landing.\n");
      } else {
        printf("Error: Drone is not flying.\n");
      }
      break;
    case MOVE_FORWARD:
      if (state == FLYING) {
        printf("Drone moving forward.\n");
      } else {
        printf("Error: Drone is not flying.\n");
      }
      break;
    case MOVE_BACKWARD:
      if (state == FLYING) {
        printf("Drone moving backward.\n");
      } else {
        printf("Error: Drone is not flying.\n");
      }
      break;
    case MOVE_LEFT:
      if (state == FLYING) {
        printf("Drone moving left.\n");
      } else {
        printf("Error: Drone is not flying.\n");
      }
      break;
    case MOVE_RIGHT:
      if (state == FLYING) {
        printf("Drone moving right.\n");
      } else {
        printf("Error: Drone is not flying.\n");
      }
      break;
    case ROTATE_LEFT:
      if (state == FLYING) {
        printf("Drone rotating left.\n");
      } else {
        printf("Error: Drone is not flying.\n");
      }
      break;
    case ROTATE_RIGHT:
      if (state == FLYING) {
        printf("Drone rotating right.\n");
      } else {
        printf("Error: Drone is not flying.\n");
      }
      break;
    case FLIP:
      if (state == FLYING) {
        printf("Drone flipping.\n");
      } else {
        printf("Error: Drone is not flying.\n");
      }
      break;
    case CALIBRATE:
      if (state == DISARMED) {
        printf("Drone calibrating.\n");
      } else {
        printf("Error: Drone is not disarmed.\n");
      }
      break;
    default:
      printf("Error: Invalid command.\n");
  }
}

// Main function
int main() {
  // Add the commands to the array
  add_command(TAKEOFF, "takeoff");
  add_command(LAND, "land");
  add_command(MOVE_FORWARD, "move forward");
  add_command(MOVE_BACKWARD, "move backward");
  add_command(MOVE_LEFT, "move left");
  add_command(MOVE_RIGHT, "move right");
  add_command(ROTATE_LEFT, "rotate left");
  add_command(ROTATE_RIGHT, "rotate right");
  add_command(FLIP, "flip");
  add_command(CALIBRATE, "calibrate");

  // Get the user input
  char input[MAX_COMMAND_LEN];
  while (1) {
    printf("Enter a command: ");
    scanf("%s", input);

    // Parse the command
    CommandType type = parse_command(input);

    // Execute the command
    execute_command(type);
  }

  return 0;
}