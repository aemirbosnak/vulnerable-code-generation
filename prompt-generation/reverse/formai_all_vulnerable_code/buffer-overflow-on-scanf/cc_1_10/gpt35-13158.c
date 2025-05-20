//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Define constants
#define SPEED_LIMIT 50
#define TURN_ANGLE 30

// Define a struct for the remote control vehicle
typedef struct {
  int speed;
  int heading;
  int x;
  int y;
} RCVehicle;

// Function to set the speed of the vehicle
void set_speed(RCVehicle *vehicle, int speed) {
  if (speed > SPEED_LIMIT) {
    printf("Speed limit exceeded, reducing speed to %d\n", SPEED_LIMIT);
    vehicle->speed = SPEED_LIMIT;
  } else {
    vehicle->speed = speed;
  }
}

// Function to set the heading of the vehicle
void set_heading(RCVehicle *vehicle, int heading) {
  vehicle->heading = heading;
}

// Function to turn the vehicle
void turn(RCVehicle *vehicle, int angle) {
  vehicle->heading += angle;
  vehicle->heading %= 360;
}

// Function to move the vehicle forward
void move_forward(RCVehicle *vehicle) {
  vehicle->x += vehicle->speed * (int)(sin(vehicle->heading * 3.14159 / 180));
  vehicle->y += vehicle->speed * (int)(cos(vehicle->heading * 3.14159 / 180));
}

// Function to move the vehicle backward
void move_backward(RCVehicle *vehicle) {
  vehicle->x -= vehicle->speed * (int)(sin(vehicle->heading * 3.14159 / 180));
  vehicle->y -= vehicle->speed * (int)(cos(vehicle->heading * 3.14159 / 180));
}

// Main function
int main() {
  // Initialize the vehicle
  RCVehicle vehicle;
  vehicle.speed = 0;
  vehicle.heading = 0;
  vehicle.x = 0;
  vehicle.y = 0;

  // Control loop
  while(1) {
    // Get user input
    printf("Enter a command (f/b/l/r): ");
    char command;
    scanf(" %c", &command);

    // Execute the command
    switch(command) {
      case 'f':
        move_forward(&vehicle);
        break;
      case 'b':
        move_backward(&vehicle);
        break;
      case 'l':
        turn(&vehicle, TURN_ANGLE);
        break;
      case 'r':
        turn(&vehicle, -TURN_ANGLE);
        break;
      default:
        printf("Invalid command, please try again.\n");
    }

    // Print out the vehicle's status
    printf("\nVehicle Status:\n");
    printf("Speed: %d\n", vehicle.speed);
    printf("Heading: %d\n", vehicle.heading);
    printf("Location: (%d,%d)\n", vehicle.x, vehicle.y);
  }

  return 0;
}