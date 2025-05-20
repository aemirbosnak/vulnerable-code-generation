//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define the drone's state
enum drone_state {
  DRONE_STATE_IDLE,
  DRONE_STATE_TAKING_OFF,
  DRONE_STATE_FLYING,
  DRONE_STATE_LANDING,
  DRONE_STATE_CRASHED
};

// Define the drone's commands
enum drone_command {
  DRONE_COMMAND_TAKE_OFF,
  DRONE_COMMAND_LAND,
  DRONE_COMMAND_MOVE_FORWARD,
  DRONE_COMMAND_MOVE_BACKWARD,
  DRONE_COMMAND_MOVE_LEFT,
  DRONE_COMMAND_MOVE_RIGHT,
  DRONE_COMMAND_ROTATE_LEFT,
  DRONE_COMMAND_ROTATE_RIGHT,
  DRONE_COMMAND_FLIP,
  DRONE_COMMAND_EXIT
};

// Define the drone's structure
struct drone {
  enum drone_state state;
  int altitude;
  int x_position;
  int y_position;
  int z_position;
};

// Initialize the drone
struct drone drone_init() {
  struct drone drone;

  drone.state = DRONE_STATE_IDLE;
  drone.altitude = 0;
  drone.x_position = 0;
  drone.y_position = 0;
  drone.z_position = 0;

  return drone;
}

// Update the drone's state
void drone_update(struct drone *drone, enum drone_command command) {
  switch (command) {
    case DRONE_COMMAND_TAKE_OFF:
      if (drone->state == DRONE_STATE_IDLE) {
        drone->state = DRONE_STATE_TAKING_OFF;
      }
      break;
    case DRONE_COMMAND_LAND:
      if (drone->state == DRONE_STATE_FLYING) {
        drone->state = DRONE_STATE_LANDING;
      }
      break;
    case DRONE_COMMAND_MOVE_FORWARD:
      if (drone->state == DRONE_STATE_FLYING) {
        drone->y_position++;
      }
      break;
    case DRONE_COMMAND_MOVE_BACKWARD:
      if (drone->state == DRONE_STATE_FLYING) {
        drone->y_position--;
      }
      break;
    case DRONE_COMMAND_MOVE_LEFT:
      if (drone->state == DRONE_STATE_FLYING) {
        drone->x_position--;
      }
      break;
    case DRONE_COMMAND_MOVE_RIGHT:
      if (drone->state == DRONE_STATE_FLYING) {
        drone->x_position++;
      }
      break;
    case DRONE_COMMAND_ROTATE_LEFT:
      if (drone->state == DRONE_STATE_FLYING) {
        drone->z_position--;
      }
      break;
    case DRONE_COMMAND_ROTATE_RIGHT:
      if (drone->state == DRONE_STATE_FLYING) {
        drone->z_position++;
      }
      break;
    case DRONE_COMMAND_FLIP:
      if (drone->state == DRONE_STATE_FLYING) {
        drone->z_position += 180;
      }
      break;
    case DRONE_COMMAND_EXIT:
      drone->state = DRONE_STATE_CRASHED;
      break;
  }
}

// Print the drone's state
void drone_print_state(struct drone *drone) {
  switch (drone->state) {
    case DRONE_STATE_IDLE:
      printf("The drone is idle.\n");
      break;
    case DRONE_STATE_TAKING_OFF:
      printf("The drone is taking off.\n");
      break;
    case DRONE_STATE_FLYING:
      printf("The drone is flying.\n");
      break;
    case DRONE_STATE_LANDING:
      printf("The drone is landing.\n");
      break;
    case DRONE_STATE_CRASHED:
      printf("The drone has crashed.\n");
      break;
  }
}

// Main function
int main() {
  // Initialize the drone
  struct drone drone = drone_init();

  // Print the drone's initial state
  drone_print_state(&drone);

  // Get the user's input
  while (1) {
    enum drone_command command;
    printf("Enter a command: ");
    scanf("%d", &command);

    // Update the drone's state
    drone_update(&drone, command);

    // Print the drone's new state
    drone_print_state(&drone);

    // Exit if the drone has crashed
    if (drone.state == DRONE_STATE_CRASHED) {
      break;
    }
  }

  return 0;
}