//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>

// Define constants for the vehicle's movement
#define VEHICLE_STOPPED 0
#define VEHICLE_FORWARD 1
#define VEHICLE_BACKWARD 2
#define VEHICLE_LEFT 3
#define VEHICLE_RIGHT 4

// Declare variables to store the vehicle's state
int vehicle_direction = VEHICLE_STOPPED;
int vehicle_speed = 0;

// Define function to handle control signals
void handle_signal(int signal) {
  switch (signal) {
    case SIGUSR1:
      vehicle_direction = VEHICLE_FORWARD;
      break;
    case SIGUSR2:
      vehicle_direction = VEHICLE_BACKWARD;
      break;
    case SIGINT:
      vehicle_direction = VEHICLE_STOPPED;
      break;
    case SIGTERM:
      exit(EXIT_SUCCESS);
      break;
    default:
      break;
  }
}

// Define function to handle speed changes
void handle_speed_change(int speed) {
  vehicle_speed = speed;
}

// Define function to simulate vehicle movement
void simulate_vehicle_movement() {
  while (true) {
    switch (vehicle_direction) {
      case VEHICLE_FORWARD:
        printf("Vehicle moving forward at speed %d\n", vehicle_speed);
        break;
      case VEHICLE_BACKWARD:
        printf("Vehicle moving backward at speed %d\n", vehicle_speed);
        break;
      case VEHICLE_LEFT:
        printf("Vehicle turning left at speed %d\n", vehicle_speed);
        break;
      case VEHICLE_RIGHT:
        printf("Vehicle turning right at speed %d\n", vehicle_speed);
        break;
      default:
        printf("Vehicle stopped\n");
        break;
    }
    usleep(100000);
  }
}

int main() {
  // Register signal handlers
  signal(SIGUSR1, handle_signal);
  signal(SIGUSR2, handle_signal);
  signal(SIGINT, handle_signal);
  signal(SIGTERM, handle_signal);

  // Start vehicle movement simulation in a new thread
  pthread_t vehicle_thread;
  pthread_create(&vehicle_thread, NULL, simulate_vehicle_movement, NULL);

  // Listen for speed change signals
  while (true) {
    int speed;
    scanf("%d", &speed);
    handle_speed_change(speed);
  }

  return EXIT_SUCCESS;
}