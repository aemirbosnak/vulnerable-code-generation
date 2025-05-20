//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of devices and commands
#define MAX_DEVICES 10
#define MAX_COMMANDS 10

// Define the device types
typedef enum {
  DEVICE_TYPE_LIGHT,
  DEVICE_TYPE_SWITCH,
  DEVICE_TYPE_SENSOR
} device_type_t;

// Define the device states
typedef enum {
  DEVICE_STATE_ON,
  DEVICE_STATE_OFF
} device_state_t;

// Define the command types
typedef enum {
  COMMAND_TYPE_TURN_ON,
  COMMAND_TYPE_TURN_OFF,
  COMMAND_TYPE_GET_STATE
} command_type_t;

// Define the device struct
typedef struct {
  char *name;
  device_type_t type;
  device_state_t state;
} device_t;

// Define the command struct
typedef struct {
  char *name;
  command_type_t type;
  device_t *device;
} command_t;

// Create an array of devices
device_t devices[MAX_DEVICES];

// Create an array of commands
command_t commands[MAX_COMMANDS];

// Initialize the devices and commands
void initialize() {
  // Create the devices
  devices[0] = (device_t) { .name = "Light 1", .type = DEVICE_TYPE_LIGHT, .state = DEVICE_STATE_OFF };
  devices[1] = (device_t) { .name = "Light 2", .type = DEVICE_TYPE_LIGHT, .state = DEVICE_STATE_OFF };
  devices[2] = (device_t) { .name = "Switch 1", .type = DEVICE_TYPE_SWITCH, .state = DEVICE_STATE_OFF };
  devices[3] = (device_t) { .name = "Switch 2", .type = DEVICE_TYPE_SWITCH, .state = DEVICE_STATE_OFF };
  devices[4] = (device_t) { .name = "Sensor 1", .type = DEVICE_TYPE_SENSOR, .state = DEVICE_STATE_OFF };

  // Create the commands
  commands[0] = (command_t) { .name = "Turn on Light 1", .type = COMMAND_TYPE_TURN_ON, .device = &devices[0] };
  commands[1] = (command_t) { .name = "Turn off Light 1", .type = COMMAND_TYPE_TURN_OFF, .device = &devices[0] };
  commands[2] = (command_t) { .name = "Get state of Light 1", .type = COMMAND_TYPE_GET_STATE, .device = &devices[0] };
  commands[3] = (command_t) { .name = "Turn on Light 2", .type = COMMAND_TYPE_TURN_ON, .device = &devices[1] };
  commands[4] = (command_t) { .name = "Turn off Light 2", .type = COMMAND_TYPE_TURN_OFF, .device = &devices[1] };
  commands[5] = (command_t) { .name = "Get state of Light 2", .type = COMMAND_TYPE_GET_STATE, .device = &devices[1] };
  commands[6] = (command_t) { .name = "Turn on Switch 1", .type = COMMAND_TYPE_TURN_ON, .device = &devices[2] };
  commands[7] = (command_t) { .name = "Turn off Switch 1", .type = COMMAND_TYPE_TURN_OFF, .device = &devices[2] };
  commands[8] = (command_t) { .name = "Get state of Switch 1", .type = COMMAND_TYPE_GET_STATE, .device = &devices[2] };
  commands[9] = (command_t) { .name = "Turn on Switch 2", .type = COMMAND_TYPE_TURN_ON, .device = &devices[3] };
}

// Execute a command
void execute_command(command_t *command) {
  switch (command->type) {
    case COMMAND_TYPE_TURN_ON:
      command->device->state = DEVICE_STATE_ON;
      printf("Turned on %s\n", command->device->name);
      break;
    case COMMAND_TYPE_TURN_OFF:
      command->device->state = DEVICE_STATE_OFF;
      printf("Turned off %s\n", command->device->name);
      break;
    case COMMAND_TYPE_GET_STATE:
      printf("%s is %s\n", command->device->name, command->device->state == DEVICE_STATE_ON ? "on" : "off");
      break;
  }
}

// Main function
int main() {
  // Initialize the devices and commands
  initialize();

  // Get the user input
  char input[100];
  printf("> ");
  scanf("%s", input);

  // Find the command
  command_t *command = NULL;
  for (int i = 0; i < MAX_COMMANDS; i++) {
    if (strcmp(input, commands[i].name) == 0) {
      command = &commands[i];
      break;
    }
  }

  // Execute the command
  if (command != NULL) {
    execute_command(command);
  } else {
    printf("Invalid command\n");
  }

  return 0;
}