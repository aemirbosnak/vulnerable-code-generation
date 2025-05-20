//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a smart home device.
typedef struct {
  char *name;
  char *type;
  int is_on;
} device;

// Define an array of smart home devices.
device devices[] = {
  {"Lamp", "Light", 0},
  {"TV", "Entertainment", 0},
  {"Thermostat", "Climate", 0},
  {"Refrigerator", "Appliance", 0},
  {"Microwave", "Appliance", 0},
};

// Define a function to turn a device on or off.
void toggle_device(device *device) {
  if (device->is_on) {
    printf("Turning %s off...\n", device->name);
    device->is_on = 0;
  } else {
    printf("Turning %s on...\n", device->name);
    device->is_on = 1;
  }
}

// Define a function to print the status of all devices.
void print_status() {
  printf("Current status of smart home devices:\n");
  for (int i = 0; i < 5; i++) {
    printf("%s: %s\n", devices[i].name, devices[i].is_on ? "On" : "Off");
  }
}

int main() {
  // Create a variable to store the user's input.
  char input[100];

  // Start a loop to process user input.
  while (1) {
    // Prompt the user to enter a command.
    printf("Enter a command (on, off, status, or quit): ");
    gets(input);

    // Check if the user entered a valid command.
    if (strcmp(input, "on") == 0) {
      // Get the name of the device to turn on.
      printf("Enter the name of the device to turn on: ");
      gets(input);

      // Find the device in the array.
      for (int i = 0; i < 5; i++) {
        if (strcmp(devices[i].name, input) == 0) {
          // Turn the device on.
          toggle_device(&devices[i]);
          break;
        }
      }
    } else if (strcmp(input, "off") == 0) {
      // Get the name of the device to turn off.
      printf("Enter the name of the device to turn off: ");
      gets(input);

      // Find the device in the array.
      for (int i = 0; i < 5; i++) {
        if (strcmp(devices[i].name, input) == 0) {
          // Turn the device off.
          toggle_device(&devices[i]);
          break;
        }
      }
    } else if (strcmp(input, "status") == 0) {
      // Print the status of all devices.
      print_status();
    } else if (strcmp(input, "quit") == 0) {
      // Exit the program.
      break;
    } else {
      // Print an error message.
      printf("Invalid command. Please enter a valid command.\n");
    }
  }

  return 0;
}