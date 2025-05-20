//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: puzzling
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Define the types of home automation devices
typedef enum {
  LIGHT,
  THERMOSTAT,
  DOOR_LOCK,
  CAMERA
} device_type;

// Define the states of home automation devices
typedef enum {
  ON,
  OFF,
  OPEN,
  CLOSED,
  LOCKED,
  UNLOCKED
} device_state;

// Define the commands that can be sent to home automation devices
typedef enum {
  TURN_ON,
  TURN_OFF,
  OPEN_DOOR,
  CLOSE_DOOR,
  LOCK_DOOR,
  UNLOCK_DOOR,
  START_STREAMING,
  STOP_STREAMING
} command;

// Define the structure of a home automation device
typedef struct {
  device_type type;
  device_state state;
  char *name;
} device;

// Create an array of home automation devices
device devices[] = {
  { LIGHT, OFF, "Living Room Light" },
  { THERMOSTAT, ON, "Thermostat" },
  { DOOR_LOCK, LOCKED, "Front Door Lock" },
  { CAMERA, OFF, "Security Camera" }
};

// Define the number of home automation devices
#define NUM_DEVICES (sizeof(devices) / sizeof(device))

// Define the maximum length of a command string
#define MAX_COMMAND_LENGTH 100

// Get the device by its name
device *get_device_by_name(char *name) {
  for (int i = 0; i < NUM_DEVICES; i++) {
    if (strcmp(devices[i].name, name) == 0) {
      return &devices[i];
    }
  }
  return NULL;
}

// Execute a command on a device
void execute_command(device *device, command command) {
  switch (device->type) {
    case LIGHT:
      switch (command) {
        case TURN_ON:
          device->state = ON;
          printf("%s turned on.\n", device->name);
          break;
        case TURN_OFF:
          device->state = OFF;
          printf("%s turned off.\n", device->name);
          break;
      }
      break;
    case THERMOSTAT:
      switch (command) {
        case TURN_ON:
          device->state = ON;
          printf("%s turned on.\n", device->name);
          break;
        case TURN_OFF:
          device->state = OFF;
          printf("%s turned off.\n", device->name);
          break;
      }
      break;
    case DOOR_LOCK:
      switch (command) {
        case OPEN_DOOR:
          device->state = OPEN;
          printf("%s opened.\n", device->name);
          break;
        case CLOSE_DOOR:
          device->state = CLOSED;
          printf("%s closed.\n", device->name);
          break;
        case LOCK_DOOR:
          device->state = LOCKED;
          printf("%s locked.\n", device->name);
          break;
        case UNLOCK_DOOR:
          device->state = UNLOCKED;
          printf("%s unlocked.\n", device->name);
          break;
      }
      break;
    case CAMERA:
      switch (command) {
        case START_STREAMING:
          device->state = ON;
          printf("%s streaming started.\n", device->name);
          break;
        case STOP_STREAMING:
          device->state = OFF;
          printf("%s streaming stopped.\n", device->name);
          break;
      }
      break;
  }
}

// Parse a command string and execute it on the specified device
void parse_command(char *command_string) {
  char device_name[MAX_COMMAND_LENGTH];
  char command_name[MAX_COMMAND_LENGTH];
  sscanf(command_string, "%s %s", device_name, command_name);

  device *device = get_device_by_name(device_name);
  if (device == NULL) {
    printf("Device not found.\n");
    return;
  }

  command command;
  if (strcmp(command_name, "TURN_ON") == 0) {
    command = TURN_ON;
  } else if (strcmp(command_name, "TURN_OFF") == 0) {
    command = TURN_OFF;
  } else if (strcmp(command_name, "OPEN_DOOR") == 0) {
    command = OPEN_DOOR;
  } else if (strcmp(command_name, "CLOSE_DOOR") == 0) {
    command = CLOSE_DOOR;
  } else if (strcmp(command_name, "LOCK_DOOR") == 0) {
    command = LOCK_DOOR;
  } else if (strcmp(command_name, "UNLOCK_DOOR") == 0) {
    command = UNLOCK_DOOR;
  } else if (strcmp(command_name, "START_STREAMING") == 0) {
    command = START_STREAMING;
  } else if (strcmp(command_name, "STOP_STREAMING") == 0) {
    command = STOP_STREAMING;
  } else {
    printf("Command not recognized.\n");
    return;
  }

  execute_command(device, command);
}

// Main function
int main() {
  while (true) {
    char command_string[MAX_COMMAND_LENGTH];
    printf("> ");
    fgets(command_string, MAX_COMMAND_LENGTH, stdin);

    parse_command(command_string);
  }

  return 0;
}