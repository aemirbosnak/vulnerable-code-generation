//FormAI DATASET v1.0 Category: Smart home light control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for the on and off states
#define ON 1
#define OFF 0

// Define structure for light data
typedef struct Light {
  char name[20];
  int state;
  int brightness;
} Light;

int main() {
  // Define array of lights with pre-set data
  Light lights[3] = {
    {"Bedroom Light", OFF, 0},
    {"Living Room Light", ON, 100},
    {"Kitchen Light", OFF, 0}
  };

  // Display initial state of all lights
  for (int i = 0; i < 3; i++) {
    printf("%s is %s with brightness %d%%\n", lights[i].name,
           lights[i].state ? "on" : "off",
           lights[i].brightness);
  }

  // Loop to receive user input for light control
  while (1) {
    char input[50];
    printf("Enter light name and action ('exit' to quit): ");
    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline character

    // Check if user entered 'exit'
    if (strcmp(input, "exit") == 0) {
      break;
    }

    // Parse user input and perform corresponding action
    char* lightName = strtok(input, " ");
    char* action = strtok(NULL, " ");
    int actionValue;
    if (action != NULL && sscanf(action, "%d", &actionValue) == 1) {
      if (actionValue >= 0 && actionValue <= 100) {
        for (int i = 0; i < 3; i++) {
          if (strcmp(lights[i].name, lightName) == 0) {
            // User entered light name
            if (strcmp(action, "on") == 0) {
              // User wants to turn light on
              lights[i].state = ON;
              lights[i].brightness = actionValue;
            } else if (strcmp(action, "off") == 0) {
              // User wants to turn light off
              lights[i].state = OFF;
              lights[i].brightness = 0;
            } else if (strcmp(action, "dim") == 0) {
              // User wants to dim light
              if (lights[i].state == OFF) {
                // Light is off, cannot dim
                printf("%s is off, cannot dim\n", lightName);
              } else {
                lights[i].brightness = actionValue;
              }
            }
            break;
          }
        }
      } else {
        // User entered invalid brightness value
        printf("Invalid brightness value\n");
      }
    } else {
      // User entered invalid input
      printf("Invalid input\n");
    }
  }

  // Display final state of all lights
  for (int i = 0; i < 3; i++) {
    printf("%s is %s with brightness %d%%\n", lights[i].name,
           lights[i].state ? "on" : "off",
           lights[i].brightness);
  }

  return 0;
}