//Code Llama-13B DATASET v1.0 Category: Smart home automation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants
#define NUM_DEVICES 5
#define MAX_NAME_LENGTH 32
#define MAX_COMMAND_LENGTH 16

// Define structure to hold device information
typedef struct {
  char name[MAX_NAME_LENGTH];
  char command[MAX_COMMAND_LENGTH];
  int state;
} Device;

// Define function to read device information from file
void read_devices_from_file(Device *devices) {
  FILE *fp = fopen("devices.txt", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return;
  }
  int i = 0;
  while (i < NUM_DEVICES && fscanf(fp, "%s %s %d", devices[i].name, devices[i].command, &devices[i].state) == 3) {
    i++;
  }
  fclose(fp);
}

// Define function to write device information to file
void write_devices_to_file(Device *devices) {
  FILE *fp = fopen("devices.txt", "w");
  if (fp == NULL) {
    printf("Error opening file\n");
    return;
  }
  for (int i = 0; i < NUM_DEVICES; i++) {
    fprintf(fp, "%s %s %d\n", devices[i].name, devices[i].command, devices[i].state);
  }
  fclose(fp);
}

// Define function to execute command
void execute_command(Device *devices, char *command) {
  for (int i = 0; i < NUM_DEVICES; i++) {
    if (strcmp(devices[i].command, command) == 0) {
      devices[i].state = 1;
      break;
    }
  }
}

// Define function to turn off devices
void turn_off_devices(Device *devices) {
  for (int i = 0; i < NUM_DEVICES; i++) {
    devices[i].state = 0;
  }
}

int main() {
  Device devices[NUM_DEVICES];
  read_devices_from_file(devices);
  char command[MAX_COMMAND_LENGTH];
  while (1) {
    scanf("%s", command);
    execute_command(devices, command);
    write_devices_to_file(devices);
    turn_off_devices(devices);
  }
  return 0;
}