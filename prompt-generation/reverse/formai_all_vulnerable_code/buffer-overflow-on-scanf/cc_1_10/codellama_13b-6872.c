//Code Llama-13B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the vehicle structure
typedef struct {
  char name[20];
  int speed;
  int direction;
} vehicle_t;

// Define the remote control structure
typedef struct {
  int channel;
  char command[20];
} remote_control_t;

// Function to send a command to the vehicle
void send_command(vehicle_t *vehicle, remote_control_t *remote_control) {
  if (strcmp(remote_control->command, "forward") == 0) {
    vehicle->speed++;
  } else if (strcmp(remote_control->command, "backward") == 0) {
    vehicle->speed--;
  } else if (strcmp(remote_control->command, "left") == 0) {
    vehicle->direction = -1;
  } else if (strcmp(remote_control->command, "right") == 0) {
    vehicle->direction = 1;
  }
}

// Function to receive a command from the remote control
void receive_command(remote_control_t *remote_control) {
  char command[20];
  scanf("%s", command);
  strcpy(remote_control->command, command);
}

int main() {
  // Define the vehicle and remote control
  vehicle_t vehicle;
  strcpy(vehicle.name, "Car");
  vehicle.speed = 0;
  vehicle.direction = 0;

  remote_control_t remote_control;
  remote_control.channel = 1;

  // Loop until the user enters "exit"
  while (1) {
    // Receive a command from the remote control
    receive_command(&remote_control);

    // Check if the command is "exit"
    if (strcmp(remote_control.command, "exit") == 0) {
      break;
    }

    // Send the command to the vehicle
    send_command(&vehicle, &remote_control);

    // Print the vehicle's current state
    printf("Vehicle: %s, Speed: %d, Direction: %d\n", vehicle.name, vehicle.speed, vehicle.direction);
  }

  return 0;
}