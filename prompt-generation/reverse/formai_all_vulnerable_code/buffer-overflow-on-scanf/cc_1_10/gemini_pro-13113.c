//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: puzzling
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the states of the light
#define LIGHT_OFF 0
#define LIGHT_ON 1

// Define the commands that can be sent to the light
#define COMMAND_TURN_ON "ON"
#define COMMAND_TURN_OFF "OFF"
#define COMMAND_TOGGLE "TOGGLE"

// Define the maximum length of a command
#define MAX_COMMAND_LENGTH 10

// Define the number of lights
#define NUM_LIGHTS 4

// Define the array of lights
uint8_t lights[NUM_LIGHTS];

// Define the function to handle the commands
void handle_command(char *command) {
  // Get the light number
  uint8_t light_number = command[0] - '0';

  // Get the command
  char *command_string = command + 2;

  // Check if the command is valid
  if (strcmp(command_string, COMMAND_TURN_ON) == 0) {
    // Turn on the light
    lights[light_number] = LIGHT_ON;
  } else if (strcmp(command_string, COMMAND_TURN_OFF) == 0) {
    // Turn off the light
    lights[light_number] = LIGHT_OFF;
  } else if (strcmp(command_string, COMMAND_TOGGLE) == 0) {
    // Toggle the light
    lights[light_number] = !lights[light_number];
  } else {
    // Invalid command
    printf("Invalid command: %s\n", command);
  }
}

// Define the main function
int main() {
  // Initialize the lights
  for (uint8_t i = 0; i < NUM_LIGHTS; i++) {
    lights[i] = LIGHT_OFF;
  }

  // Get the commands from the user
  char command[MAX_COMMAND_LENGTH];
  while (1) {
    printf("Enter a command: ");
    scanf("%s", command);

    // Handle the command
    handle_command(command);

    // Print the state of the lights
    printf("Lights: ");
    for (uint8_t i = 0; i < NUM_LIGHTS; i++) {
      printf("%d ", lights[i]);
    }
    printf("\n");
  }

  return 0;
}