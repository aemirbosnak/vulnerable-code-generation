//FormAI DATASET v1.0 Category: Smart home automation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  // Initializing variables
  char command[10];
  int temperature = 25;
  int lights = 0;
  int motion = 0;

  // Welcome message
  printf("Welcome to Smart Home Automation System\n");

  // Main loop
  while (1) {
    // Display the current status
    printf("Current status: Temperature: %d C, Lights: %s, Motion: %s\n",
           temperature, lights ? "on" : "off", motion ? "detected" : "not detected");

    // Get user input
    printf("Enter a command (temp, lights, motion, exit): ");
    fgets(command, sizeof(command), stdin);

    // Remove the newline character from the input
    command[strcspn(command, "\n")] = '\0';

    // Process the command
    if (strcmp(command, "temp") == 0) {
      // Adjust temperature
      int tempChange;
      printf("Enter temperature (-5 to +5): ");
      scanf("%d", &tempChange);
      temperature += tempChange;
      getchar(); // Remove the newline character from the buffer
    } else if (strcmp(command, "lights") == 0) {
      // Toggle lights
      lights = !lights;
    } else if (strcmp(command, "motion") == 0) {
      // Simulate motion detection
      motion = 1;
      printf("Motion detected!\n");
    } else if (strcmp(command, "exit") == 0) {
      // Exit the program
      printf("Goodbye!\n");
      exit(0);
    } else {
      // Invalid command
      printf("Invalid command\n");
    }

    // Check if temperature is too high or too low
    if (temperature > 30) {
      printf("Warning: Temperature is too high!\n");
    } else if (temperature < 20) {
      printf("Warning: Temperature is too low!\n");
    }

    // Check if motion has stopped
    if (motion) {
      printf("Motion stopped!\n");
      motion = 0;
    }
  }

  return 0;
}