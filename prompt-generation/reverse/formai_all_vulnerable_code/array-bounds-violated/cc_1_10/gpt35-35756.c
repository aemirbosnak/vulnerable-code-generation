//FormAI DATASET v1.0 Category: Temperature monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10
#define MAX_NAME_LENGTH 20
#define MAX_TEMP_LENGTH 5

typedef struct {
  char name[MAX_NAME_LENGTH];
  double temperature;
} device;

device monitored_devices[MAX_DEVICES]; // array of monitored devices
int num_devices = 0; // number of monitored devices

// function to add a new device to the array of monitored devices
void add_device(char* name) {
  if (num_devices == MAX_DEVICES) {
    printf("Cannot add more devices\n");
    return;
  }
  strcpy(monitored_devices[num_devices].name, name);
  monitored_devices[num_devices].temperature = 0.0;
  num_devices++;
}

// function to update the temperature of a device
void update_temperature(char* name, double temperature) {
  for (int i = 0; i < num_devices; i++) {
    if (strcmp(monitored_devices[i].name, name) == 0) {
      monitored_devices[i].temperature = temperature;
      return;
    }
  }
  printf("Device not found: %s\n", name);
}

// function to print the current temperature of all monitored devices
void print_temperatures() {
  printf("Current temperatures:\n");
  for (int i = 0; i < num_devices; i++) {
    printf("%s: %.2f°C\n", monitored_devices[i].name, monitored_devices[i].temperature);
  }
}

int main() {
  char command[100]; // buffer to hold user input
  char name[MAX_NAME_LENGTH];
  double temperature;

  printf("Welcome to the temperature monitor program!\n");

  // main program loop
  while (1) {
    printf("Enter a command (add, update, print, quit): ");
    fgets(command, 100, stdin);

    if (strcmp(command, "quit\n") == 0) {
      break;
    }
    else if (strcmp(command, "add\n") == 0) {
      printf("Enter the name of the device to add: ");
      fgets(name, MAX_NAME_LENGTH, stdin);
      name[strlen(name) - 1] = '\0'; // remove newline character from name
      add_device(name);
    }
    else if (strcmp(command, "update\n") == 0) {
      printf("Enter the name of the device to update: ");
      fgets(name, MAX_NAME_LENGTH, stdin);
      name[strlen(name) - 1] = '\0'; // remove newline character from name
      printf("Enter the new temperature: ");
      char temp_str[MAX_TEMP_LENGTH];
      fgets(temp_str, MAX_TEMP_LENGTH, stdin);
      temperature = atof(temp_str);
      update_temperature(name, temperature);
    }
    else if (strcmp(command, "print\n") == 0) {
      print_temperatures();
    }
    else {
      printf("Invalid command, please try again\n");
    }
  }

  printf("Goodbye!\n");
  return 0;
}