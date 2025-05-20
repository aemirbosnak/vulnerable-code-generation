//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Define the main function
int main() {
  // Define the smart home devices
  int lights = 0;
  int thermostat = 0;
  int security = 0;

  // Define the user input
  int choice = 0;

  // Display the menu
  printf("Smart Home Automation System\n");
  printf("===========================\n");
  printf("1. Turn on lights\n");
  printf("2. Turn off lights\n");
  printf("3. Set thermostat\n");
  printf("4. Arm security system\n");
  printf("5. Disarm security system\n");
  printf("6. Exit\n");

  // Get the user input
  printf("Enter your choice: ");
  scanf("%d", &choice);

  // Switch on the user input
  switch (choice) {
    case 1:
      lights = 1;
      printf("Lights turned on.\n");
      break;
    case 2:
      lights = 0;
      printf("Lights turned off.\n");
      break;
    case 3:
      printf("Enter the desired temperature: ");
      scanf("%d", &thermostat);
      printf("Thermostat set to %d degrees.\n", thermostat);
      break;
    case 4:
      security = 1;
      printf("Security system armed.\n");
      break;
    case 5:
      security = 0;
      printf("Security system disarmed.\n");
      break;
    case 6:
      printf("Exiting the program.\n");
      break;
    default:
      printf("Invalid choice.\n");
  }

  // Return 0 to indicate successful execution
  return 0;
}