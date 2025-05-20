//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Define the states of the light
#define OFF 0
#define ON 1

// Define the commands that can be sent to the light
#define TURN_ON 1
#define TURN_OFF 2
#define TOGGLE 3

// Define the maximum number of lights that can be controlled
#define MAX_LIGHTS 10

// Create an array to store the states of the lights
int lights[MAX_LIGHTS];

// Create a function to turn on a light
void turn_on(int light) {
  if (light < 0 || light >= MAX_LIGHTS) {
    printf("Invalid light number\n");
    return;
  }

  lights[light] = ON;
}

// Create a function to turn off a light
void turn_off(int light) {
  if (light < 0 || light >= MAX_LIGHTS) {
    printf("Invalid light number\n");
    return;
  }

  lights[light] = OFF;
}

// Create a function to toggle a light
void toggle(int light) {
  if (light < 0 || light >= MAX_LIGHTS) {
    printf("Invalid light number\n");
    return;
  }

  lights[light] = !lights[light];
}

// Create a function to print the states of the lights
void print_lights() {
  for (int i = 0; i < MAX_LIGHTS; i++) {
    printf("Light %d is %s\n", i, lights[i] ? "ON" : "OFF");
  }
}

// Create a function to process a command
void process_command(int command, int light) {
  switch (command) {
    case TURN_ON:
      turn_on(light);
      break;
    case TURN_OFF:
      turn_off(light);
      break;
    case TOGGLE:
      toggle(light);
      break;
    default:
      printf("Invalid command\n");
  }
}

// Main function
int main() {
  // Initialize the lights to be off
  for (int i = 0; i < MAX_LIGHTS; i++) {
    lights[i] = OFF;
  }

  // Get the command from the user
  int command;
  int light;
  printf("Enter a command (1 for turn on, 2 for turn off, 3 for toggle): ");
  scanf("%d", &command);
  printf("Enter the light number: ");
  scanf("%d", &light);

  // Process the command
  process_command(command, light);

  // Print the states of the lights
  print_lights();

  return 0;
}