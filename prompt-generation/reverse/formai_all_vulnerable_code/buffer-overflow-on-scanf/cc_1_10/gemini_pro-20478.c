//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of lights that can be controlled.
#define MAX_LIGHTS 10

// Define the states of the light bulbs.
#define OFF 0
#define ON  1

// Define the commands that can be sent to the light bulbs.
#define TURN_ON  1
#define TURN_OFF 2
#define TOGGLE   3

// Define the structure of the light bulb.
typedef struct {
  int state;
  char *name;
} light_bulb;

// Create an array of light bulbs.
light_bulb lights[MAX_LIGHTS];

// Define the function to turn on a light bulb.
void turn_on_light(int light_number) {
  if (light_number < 0 || light_number >= MAX_LIGHTS) {
    printf("Invalid light number.\n");
  } else {
    lights[light_number].state = ON;
    printf("Light %s turned on.\n", lights[light_number].name);
  }
}

// Define the function to turn off a light bulb.
void turn_off_light(int light_number) {
  if (light_number < 0 || light_number >= MAX_LIGHTS) {
    printf("Invalid light number.\n");
  } else {
    lights[light_number].state = OFF;
    printf("Light %s turned off.\n", lights[light_number].name);
  }
}

// Define the function to toggle a light bulb.
void toggle_light(int light_number) {
  if (light_number < 0 || light_number >= MAX_LIGHTS) {
    printf("Invalid light number.\n");
  } else {
    lights[light_number].state = !lights[light_number].state;
    printf("Light %s toggled.\n", lights[light_number].name);
  }
}

// Define the function to print the status of all light bulbs.
void print_light_status() {
  for (int i = 0; i < MAX_LIGHTS; i++) {
    printf("Light %s is %s\n", lights[i].name, lights[i].state == ON ? "on" : "off");
  }
}

// Define the main function.
int main() {
  // Initialize the light bulbs.
  for (int i = 0; i < MAX_LIGHTS; i++) {
    lights[i].name = malloc(10);
    sprintf(lights[i].name, "Light %d", i);
    lights[i].state = OFF;
  }

  // Print the initial status of the light bulbs.
  print_light_status();

  // Get the command from the user.
  int command;
  printf("Enter a command (1: turn on, 2: turn off, 3: toggle, 4: quit): ");
  scanf("%d", &command);

  // Execute the command.
  while (command != 4) {
    int light_number;
    printf("Enter the light number: ");
    scanf("%d", &light_number);

    switch (command) {
      case 1:
        turn_on_light(light_number);
        break;
      case 2:
        turn_off_light(light_number);
        break;
      case 3:
        toggle_light(light_number);
        break;
      default:
        printf("Invalid command.\n");
        break;
    }

    // Print the new status of the light bulbs.
    print_light_status();

    // Get the next command from the user.
    printf("Enter a command (1: turn on, 2: turn off, 3: toggle, 4: quit): ");
    scanf("%d", &command);
  }

  // Free the memory allocated for the light bulbs.
  for (int i = 0; i < MAX_LIGHTS; i++) {
    free(lights[i].name);
  }

  return 0;
}