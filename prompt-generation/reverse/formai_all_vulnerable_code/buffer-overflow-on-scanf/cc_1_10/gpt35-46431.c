//FormAI DATASET v1.0 Category: Smart home light control ; Style: all-encompassing
#include <stdio.h>
#include <stdbool.h>

int main() {
  // Declare variables
  bool isLightOn = false;
  char choice;

  // Start the program
  printf("Welcome to Smart Home Light Control\n");

  while (true) { // Infinite loop until user chooses to exit

    // Display menu options
    printf("\nWhat would you like to do?\n");
    printf("1. Turn the light ON\n");
    printf("2. Turn the light OFF\n");
    printf("3. Exit\n");

    // Get user choice
    printf("\nEnter your choice: ");
    scanf(" %c", &choice);

    switch (choice) {
      case '1':
        if (!isLightOn) { // If the light is not already on
          printf("Turning on the light...\n");
          // Code to turn the light on
          isLightOn = true; // Update light status
        } else {
          printf("The light is already on!\n");
        }
        break;

      case '2':
        if (isLightOn) { // If the light is not already off
          printf("Turning off the light...\n");
          // Code to turn the light off
          isLightOn = false; // Update light status
        } else {
          printf("The light is already off!\n");
        }
        break;

      case '3': // Exit the program
        printf("Goodbye!\n");
        return 0;

      default: // Invalid choice
        printf("Invalid choice! Please try again.\n");
        break;
    }
  }

  return 0;
}