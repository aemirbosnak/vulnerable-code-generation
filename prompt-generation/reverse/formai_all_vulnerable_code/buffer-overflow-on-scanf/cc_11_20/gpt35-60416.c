//FormAI DATASET v1.0 Category: Smart home automation ; Style: peaceful
#include <stdio.h>

int main() {
  // Declare variables to hold the status of the home devices
  int bedroom_light = 0;
  int kitchen_light = 0;
  int living_room_tv = 0;
  int living_room_ac = 0;
  int garage_door = 0;

  // Display a welcome message
  printf("Welcome to your Smart Home Automation System.\n");

  // Display the current status of all the devices
  printf("The current status of your home devices are:\n");
  printf("Bedroom Light - %s\n", bedroom_light ? "On" : "Off");
  printf("Kitchen Light - %s\n", kitchen_light ? "On" : "Off");
  printf("Living Room TV - %s\n", living_room_tv ? "On" : "Off");
  printf("Living Room AC - %s\n", living_room_ac ? "On" : "Off");
  printf("Garage Door - %s\n", garage_door ? "Open" : "Closed");

  // Ask the user what actions they would like to take
  printf("\nWhat would you like to do?\n");
  printf("1. Turn on/off the bedroom light\n");
  printf("2. Turn on/off the kitchen light\n");
  printf("3. Turn on/off the living room TV\n");
  printf("4. Turn on/off the living room AC\n");
  printf("5. Open/close the garage door\n");

  // Read the user's choice
  int choice;
  scanf("%d", &choice);

  // Perform the selected action
  switch (choice) {
    case 1:
      bedroom_light = !bedroom_light;
      printf("Bedroom Light - %s\n", bedroom_light ? "On" : "Off");
      break;
    case 2:
      kitchen_light = !kitchen_light;
      printf("Kitchen Light - %s\n", kitchen_light ? "On" : "Off");
      break;
    case 3:
      living_room_tv = !living_room_tv;
      printf("Living Room TV - %s\n", living_room_tv ? "On" : "Off");
      break;
    case 4:
      living_room_ac = !living_room_ac;
      printf("Living Room AC - %s\n", living_room_ac ? "On" : "Off");
      break;
    case 5:
      garage_door = !garage_door;
      printf("Garage Door - %s\n", garage_door ? "Open" : "Closed");
      break;
    default:
      printf("Invalid choice\n");
  }

  // Display a goodbye message
  printf("\nThank you for using your Smart Home Automation System.\n");

  return 0;
}