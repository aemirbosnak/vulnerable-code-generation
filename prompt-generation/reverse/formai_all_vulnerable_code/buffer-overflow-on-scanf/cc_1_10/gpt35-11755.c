//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: brave
#include <stdio.h>

int main() {
  printf("Welcome to C Drone Remote Control Program!\n");
  
  // Declare and initialize variables
  int direction, altitude, speed;
  direction = 0;
  altitude = 0;
  speed = 0;

  // Display menu options to user
  printf("\nMenu Options:\n");
  printf("1. Change Direction\n");
  printf("2. Change Altitude\n");
  printf("3. Change Speed\n");
  printf("4. Exit the Program\n");

  // Loop until user decides to exit
  while(1) {
    // Get user input for menu option
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    // Execute corresponding function based on user choice
    switch(choice) {
      case 1:
        printf("Current direction: %d\n", direction);
        printf("Enter new direction (0-360 degrees): ");
        scanf("%d", &direction);
        printf("New direction set to %d degrees\n", direction);
        break;
      case 2:
        printf("Current altitude: %d feet\n", altitude);
        printf("Enter new altitude (0-500 feet): ");
        scanf("%d", &altitude);
        printf("New altitude set to %d feet\n", altitude);
        break;
      case 3:
        printf("Current speed: %d mph\n", speed);
        printf("Enter new speed (0-100 mph): ");
        scanf("%d", &speed);
        printf("New speed set to %d mph\n", speed);
        break;
      case 4:
        printf("Exiting C Drone Remote Control Program... Goodbye!\n");
        return 0;
      default:
        printf("Invalid choice. Please choose again.\n");
        break;
    }
  }
  return 0;
}