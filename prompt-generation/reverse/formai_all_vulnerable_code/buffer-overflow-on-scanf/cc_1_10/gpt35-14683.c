//FormAI DATASET v1.0 Category: Smart home light control ; Style: mind-bending
#include <stdio.h>

int main(void) {

  // Declare variables
  int lightsOn = 0;
  int userChoice = 0;

  // Welcome message
  printf("Welcome to Smart Light Control!\n");
  printf("-------------------------------\n");

  // Loop until user chooses to quit
  while (userChoice != 3) {
    // Display menu
    printf("MENU:\n");
    printf("1. Turn lights on/off\n");
    printf("2. Dim lights\n");
    printf("3. Quit\n");

    // Get user choice
    printf("Enter your choice: ");
    scanf("%d", &userChoice);

    // Handle user choice
    switch (userChoice) {
      case 1:
        // Turn lights on/off
        if (lightsOn == 0) {
          printf("Lights turned on.\n");
          lightsOn = 1;
        } else {
          printf("Lights turned off.\n");
          lightsOn = 0;
        }
        break;
      case 2:
        // Dim lights
        printf("Enter brightness level (0-100): ");
        int brightness;
        scanf("%d", &brightness);
        printf("Lights dimmed to %d%% brightness.\n", brightness);
        break;
      case 3:
        // Quit
        printf("Goodbye!\n");
        break;
      default:
        // Invalid choice
        printf("Invalid choice. Please try again.\n");
        break;
    }
  }

  return 0;
}