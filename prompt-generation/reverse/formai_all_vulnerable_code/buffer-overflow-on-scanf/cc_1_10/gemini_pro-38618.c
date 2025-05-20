//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define MAX_THRUST 1000 // Maximum thrust in Newtons
#define MIN_THRUST 0 // Minimum thrust in Newtons
#define MAX_TILT 30 // Maximum tilt angle in degrees
#define MIN_TILT -30 // Minimum tilt angle in degrees
#define CONTROL_RATE 100 // Control rate in milliseconds

typedef struct {
  int thrust; // Thrust in Newtons
  int tilt; // Tilt angle in degrees
} Controls;

void set_controls(Controls *controls, int thrust, int tilt) {
  controls->thrust = thrust;
  controls->tilt = tilt;
}

void print_controls(Controls *controls) {
  printf("Thrust: %d Newtons\n", controls->thrust);
  printf("Tilt: %d degrees\n", controls->tilt);
}

int main() {
  Controls controls;

  // Initialize the controls to default values
  set_controls(&controls, MAX_THRUST, 0);

  // Get user input
  while (1) {
    printf("Enter thrust (0-%d): ", MAX_THRUST);
    scanf("%d", &controls.thrust);

    printf("Enter tilt (-%d-%d): ", MAX_TILT, MIN_TILT);
    scanf("%d", &controls.tilt);

    // Check if the user wants to quit
    if (controls.thrust == 0 && controls.tilt == 0) {
      break;
    }

    // Send the controls to the drone
    // ...

    // Print the controls
    print_controls(&controls);

    // Sleep for the control rate
    usleep(CONTROL_RATE * 1000);
  }

  return 0;
}