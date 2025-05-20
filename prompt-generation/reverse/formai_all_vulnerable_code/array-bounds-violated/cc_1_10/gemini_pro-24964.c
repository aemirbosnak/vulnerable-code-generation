//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10

// An enumeration of the different types of devices
enum device_type {
  DEVICE_TYPE_LIGHT,
  DEVICE_TYPE_DOOR,
  DEVICE_TYPE_WINDOW
};

// A structure representing a device
struct device {
  char *name;
  enum device_type type;
  int state; // 0 for off, 1 for on
};

// An array of devices
struct device devices[MAX_DEVICES];

// A function to initialize the devices array
void init_devices() {
  // Create a light named "Lantern"
  devices[0].name = "Lantern";
  devices[0].type = DEVICE_TYPE_LIGHT;
  devices[0].state = 0;

  // Create a door named "Oaken Door"
  devices[1].name = "Oaken Door";
  devices[1].type = DEVICE_TYPE_DOOR;
  devices[1].state = 0;

  // Create a window named "Casement Window"
  devices[2].name = "Casement Window";
  devices[2].type = DEVICE_TYPE_WINDOW;
  devices[2].state = 0;
}

// A function to print the state of all devices
void print_devices() {
  for (int i = 0; i < MAX_DEVICES; i++) {
    printf("%s: ", devices[i].name);

    switch (devices[i].type) {
      case DEVICE_TYPE_LIGHT:
        printf("Light is %s\n", devices[i].state ? "on" : "off");
        break;
      case DEVICE_TYPE_DOOR:
        printf("Door is %s\n", devices[i].state ? "open" : "closed");
        break;
      case DEVICE_TYPE_WINDOW:
        printf("Window is %s\n", devices[i].state ? "open" : "closed");
        break;
    }
  }
}

// A function to change the state of a device
void change_device_state(char *name, int state) {
  for (int i = 0; i < MAX_DEVICES; i++) {
    if (strcmp(devices[i].name, name) == 0) {
      devices[i].state = state;
      return;
    }
  }

  printf("Error: Device not found\n");
}

// A function to toggle the state of a device
void toggle_device_state(char *name) {
  for (int i = 0; i < MAX_DEVICES; i++) {
    if (strcmp(devices[i].name, name) == 0) {
      devices[i].state = !devices[i].state;
      return;
    }
  }

  printf("Error: Device not found\n");
}

// A function to handle user input
void handle_input() {
  char input[100];

  while (1) {
    printf("> ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character from the input
    input[strlen(input) - 1] = '\0';

    // Check if the user wants to exit
    if (strcmp(input, "exit") == 0) {
      break;
    }

    // Check if the user wants to print the state of all devices
    else if (strcmp(input, "list") == 0) {
      print_devices();
    }

    // Check if the user wants to change the state of a device
    else if (strncmp(input, "set ", 4) == 0) {
      char *name = strtok(input + 4, " ");
      char *state = strtok(NULL, " ");

      if (name != NULL && state != NULL) {
        change_device_state(name, atoi(state));
      } else {
        printf("Error: Invalid input\n");
      }
    }

    // Check if the user wants to toggle the state of a device
    else if (strncmp(input, "toggle ", 7) == 0) {
      char *name = input + 7;

      if (name != NULL) {
        toggle_device_state(name);
      } else {
        printf("Error: Invalid input\n");
      }
    }

    // Check if the user entered an invalid command
    else {
      printf("Error: Invalid command\n");
    }
  }
}

int main() {
  init_devices();
  handle_input();

  return 0;
}