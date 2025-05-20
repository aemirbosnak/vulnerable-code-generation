//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Welcome message
  printf("Welcome to the Remote Control Vehicle Simulation!\n\n");

  // Variables for direction and speed
  int direction;
  int speed;

  // Main loop
  while (1) {
    // Prompt user for input
    printf("Enter direction (1-4): ");
    scanf("%d", &direction);
    printf("Enter speed (0-10): ");
    scanf("%d", &speed);

    // Check for valid input
    if (direction < 1 || direction > 4) {
      printf("Invalid direction! Please enter a value between 1-4.\n\n");
      continue;
    }
    if (speed < 0 || speed > 10) {
      printf("Invalid speed! Please enter a value between 0-10.\n\n");
      continue;
    }

    // Print out the chosen action
    printf("Vehicle set to move ");

    switch (direction) {
      case 1:
        printf("forward");
        break;
      case 2:
        printf("backward");
        break;
      case 3:
        printf("left");
        break;
      case 4:
        printf("right");
        break;
    }

    // Print out the chosen speed
    printf(" at speed %d.\n\n", speed);

    // Wait for a moment
    printf("Vehicle moving...\n\n");
    system("sleep 1");

    // Check for emergency stop
    if (speed == 0) {
      printf("Vehicle emergency stop activated! Moving stopped immediately.\n\n");
      break;
    }
  }

  // Exit message
  printf("Thank you for using the Remote Control Vehicle Simulation!\n");

  return 0;
}