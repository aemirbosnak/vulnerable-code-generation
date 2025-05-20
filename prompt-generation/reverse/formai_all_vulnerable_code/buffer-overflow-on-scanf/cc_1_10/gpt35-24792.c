//FormAI DATASET v1.0 Category: Smart home automation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Defining constants for various devices */
#define LIGHTS 1
#define FAN 2
#define AC 3
#define TV 4

/* Defining constants for various rooms */
#define BEDROOM 1
#define LIVING_ROOM 2
#define KITCHEN 3

/* Function to turn on/off different devices in rooms */
void control_devices(int device, int room, bool status) {
  if (status) {
    printf("Turning on ");
  } else {
    printf("Turning off ");
  }
  switch (device) {
    case LIGHTS:
      printf("lights in ");
      break;
    case FAN:
      printf("fan in ");
      break;
    case AC:
      printf("AC in ");
      break;
    case TV:
      printf("TV in ");
      break;
    default:
      printf("Invalid device selection.");
      return;
  }
  switch (room) {
    case BEDROOM:
      printf("bedroom.\n");
      break;
    case LIVING_ROOM:
      printf("living room.\n");
      break;
    case KITCHEN:
      printf("kitchen.\n");
      break;
    default:
      printf("Invalid room selection.");
      return;
  }
}

/* Main function */
int main() {
  printf("Welcome to the Smart Home Automation System!\n\n");

  int device, room, choice;
  bool status;

  do {
    printf("Please select an option:\n");
    printf("1. Turn on a device.\n");
    printf("2. Turn off a device.\n");
    printf("3. Exit the program.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("\nSelect a device:\n");
        printf("1. Lights.\n");
        printf("2. Fan.\n");
        printf("3. AC.\n");
        printf("4. TV.\n");
        printf("Enter your choice: ");
        scanf("%d", &device);

        printf("\nSelect a room:\n");
        printf("1. Bedroom.\n");
        printf("2. Living room.\n");
        printf("3. Kitchen.\n");
        printf("Enter your choice: ");
        scanf("%d", &room);

        control_devices(device, room, true); // Turning on selected device in selected room
        break;
      case 2:
        printf("\nSelect a device:\n");
        printf("1. Lights.\n");
        printf("2. Fan.\n");
        printf("3. AC.\n");
        printf("4. TV.\n");
        printf("Enter your choice: ");
        scanf("%d", &device);

        printf("\nSelect a room:\n");
        printf("1. Bedroom.\n");
        printf("2. Living room.\n");
        printf("3. Kitchen.\n");
        printf("Enter your choice: ");
        scanf("%d", &room);

        control_devices(device, room, false); // Turning off selected device in selected room
        break;
      case 3:
        printf("\nExiting the program. Goodbye!\n");
        exit(0);
      default:
        printf("\nInvalid choice. Please try again.\n");
    }

  } while (choice != 3);

  return 0;
}