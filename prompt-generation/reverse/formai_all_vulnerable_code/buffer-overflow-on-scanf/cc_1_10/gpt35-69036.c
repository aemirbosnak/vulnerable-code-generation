//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: authentic
#include <stdio.h>

// defining enum for remote control commands
typedef enum {
  FORWARD, BACKWARD, LEFT, RIGHT, STOP
} command_t;

// defining struct for remote control vehicle
typedef struct {
  int x, y; // current position
  int speed; // current speed
} rc_vehicle_t;

// function to handle remote control commands
void handle_command(rc_vehicle_t *vehicle, command_t command) {
  switch (command) {
    case FORWARD:
      vehicle->x += vehicle->speed;
      break;
    case BACKWARD:
      vehicle->x -= vehicle->speed;
      break;
    case LEFT:
      vehicle->y -= vehicle->speed;
      break;
    case RIGHT:
      vehicle->y += vehicle->speed;
      break;
    case STOP:
      vehicle->speed = 0;
      break;
  }
}

int main() {
  rc_vehicle_t vehicle = { 0, 0, 10 }; // creating a new vehicle at (0,0) with speed = 10

  // taking user input and handling remote control commands
  char input;
  do {
    printf("Enter command (F - forward, B - backward, L - left, R - right, S - stop): ");
    scanf(" %c", &input);

    switch (input) {
      case 'F':
        handle_command(&vehicle, FORWARD);
        break;
      case 'B':
        handle_command(&vehicle, BACKWARD);
        break;
      case 'L':
        handle_command(&vehicle, LEFT);
        break;
      case 'R':
        handle_command(&vehicle, RIGHT);
        break;
      case 'S':
        handle_command(&vehicle, STOP);
        break;
      default:
        printf("Invalid command.\n");
    }

    printf("Vehicle current position: (%d,%d)\n", vehicle.x, vehicle.y);
  } while (input != 'S');

  return 0;
}