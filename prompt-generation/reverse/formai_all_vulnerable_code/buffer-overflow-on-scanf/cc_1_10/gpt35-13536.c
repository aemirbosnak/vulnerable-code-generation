//FormAI DATASET v1.0 Category: Smart home automation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 5
#define MAX_DEVICES 5

int main() {
  char rooms[MAX_ROOMS][10] = {"Bedroom", "Living Room", "Kitchen", "Bathroom", "Home Office"};
  char devices[MAX_DEVICES][10] = {"Lights", "Thermostat", "TV", "Security System", "Sprinklers"};
  int room_index, device_index, choice;

  printf("Welcome to Smart Home Automation!\n");

  do {
    printf("\nWhat would you like to do?\n");
    printf("1. Control a device\n");
    printf("2. View device status\n");
    printf("3. Exit program\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("\nWhich device would you like to control?\n");

        for(int i = 0; i < MAX_DEVICES; i++) {
          printf("%d. %s\n", i+1, devices[i]);
        }
        printf("Enter your choice: ");
        scanf("%d", &device_index);

        printf("\nWhich room is the device in?\n");

        for(int i = 0; i < MAX_ROOMS; i++) {
          printf("%d. %s\n", i+1, rooms[i]);
        }
        printf("Enter your choice: ");
        scanf("%d", &room_index);

        printf("\nTurning on %s in %s...\n", devices[device_index-1], rooms[room_index-1]);
        break;

      case 2:
        printf("\nWhich device would you like to check?\n");

        for(int i = 0; i < MAX_DEVICES; i++) {
          printf("%d. %s\n", i+1, devices[i]);
        }
        printf("Enter your choice: ");
        scanf("%d", &device_index);

        printf("\nWhich room is the device in?\n");

        for(int i = 0; i < MAX_ROOMS; i++) {
          printf("%d. %s\n", i+1, rooms[i]);
        }
        printf("Enter your choice: ");
        scanf("%d", &room_index);

        printf("\nChecking status of %s in %s...\n", devices[device_index-1], rooms[room_index-1]);
        break;

      case 3:
        printf("\nExiting program...\n");
        break;

      default:
        printf("\nInvalid choice. Please try again.\n");
        break;
    }
  } while(choice != 3);

  return 0;
}