//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: funny
#include <stdio.h>

int main() {
  
  printf("Welcome to the C Drone Remote Control Program!\n\n");

  // Initializing variables for direction and speed
  int direction = 0;
  int speed = 0;

  while (1) {
    // Display the menu options
    printf("Select a direction:\n");
    printf("1 - Up\n");
    printf("2 - Down\n");
    printf("3 - Left\n");
    printf("4 - Right\n");
    printf("5 - Exit\n");

    // Get input from the user
    printf("Enter your choice: ");
    scanf("%d", &direction);
    
    // If the user wants to exit, then return from the program
    if (direction == 5) {
      printf("Goodbye!");
      return 0;
    }

    // Otherwise, ask for the speed
    printf("Enter the speed (0-100): ");
    scanf("%d", &speed);

    // Perform the action based on the direction and speed
    switch (direction) {
      case 1:
        printf("Drone moving up with speed %d%%\n", speed);
        break;
      case 2:
        printf("Drone moving down with speed %d%%\n", speed);
        break;
      case 3:
        printf("Drone moving left with speed %d%%\n", speed);
        break;
      case 4:
        printf("Drone moving right with speed %d%%\n", speed);
        break;
      default:
        printf("Invalid direction. Please try again.\n");
        break;
    }
  }
  return 0;
}