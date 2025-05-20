//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define the smart home devices
#define LIGHT_1 1
#define LIGHT_2 2
#define FAN 3
#define DOOR 4

// Define the smart home states
#define ON 1
#define OFF 0

// Define the smart home actions
#define TOGGLE 0
#define SET_ON 1
#define SET_OFF 2

// Create a smart home device
struct device {
  int type;
  int state;
};

// Create an array of smart home devices
struct device devices[] = {
  { LIGHT_1, OFF },
  { LIGHT_2, OFF },
  { FAN, OFF },
  { DOOR, OFF }
};

// Define the smart home commands
#define CMD_TOGGLE "toggle"
#define CMD_SET_ON "on"
#define CMD_SET_OFF "off"

// Define the smart home command functions
void toggle_device(struct device *device) {
  device->state = !device->state;
}

void set_device_on(struct device *device) {
  device->state = ON;
}

void set_device_off(struct device *device) {
  device->state = OFF;
}

// Parse the smart home command
int parse_command(char *command) {
  if (strcmp(command, CMD_TOGGLE) == 0) {
    return TOGGLE;
  } else if (strcmp(command, CMD_SET_ON) == 0) {
    return SET_ON;
  } else if (strcmp(command, CMD_SET_OFF) == 0) {
    return SET_OFF;
  } else {
    return -1;
  }
}

// Execute the smart home command
void execute_command(struct device *device, int command) {
  switch (command) {
    case TOGGLE:
      toggle_device(device);
      break;
    case SET_ON:
      set_device_on(device);
      break;
    case SET_OFF:
      set_device_off(device);
      break;
  }
}

// Print the smart home state
void print_state(struct device *device) {
  printf("%s is %s\n", device->type == LIGHT_1 ? "Light 1" : device->type == LIGHT_2 ? "Light 2" : device->type == FAN ? "Fan" : device->type == DOOR ? "Door" : "Unknown device", device->state == ON ? "on" : "off");
}

// Main function
int main() {
  // Get the smart home command
  char command[100];
  printf("Enter a command: ");
  scanf("%s", command);

  // Parse the smart home command
  int command_code = parse_command(command);

  // Execute the smart home command
  for (int i = 0; i < 4; i++) {
    execute_command(&devices[i], command_code);
  }

  // Print the smart home state
  for (int i = 0; i < 4; i++) {
    print_state(&devices[i]);
  }

  return 0;
}