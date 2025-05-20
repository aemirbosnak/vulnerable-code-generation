//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: happy
#include <stdio.h>

// Function to display a happy message
void happy_message() {
  printf("Great Job!\n");
  printf("You are controlling the drone with ease!\n");
  printf("Keep it up!\n\n");
}

int main() {
  int altitude = 0;
  int speed = 0;
  printf("Initializing the drone...\n");
  printf("The drone is ready to take off!\n");

  while (1) {
    // Get user's input for controlling the drone
    char c;
    printf("Enter your command (a - increase altitude, z - decrease altitude, s - increase speed, x - decrease speed, q - quit): ");
    scanf("%c", &c);

    // Determine what action to take based on the command
    switch (c) {
      case 'a':
        altitude++;
        printf("The drone has increased its altitude by 1.\n");
        happy_message();
        break;
      case 'z':
        altitude--;
        printf("The drone has decreased its altitude by 1.\n");
        happy_message();
        break;
      case 's':
        speed++;
        printf("The drone has increased its speed by 1.\n");
        happy_message();
        break;
      case 'x':
        speed--;
        printf("The drone has decreased its speed by 1.\n");
        happy_message();
        break;
      case 'q':
        printf("Shutting down the drone...\n");
        printf("Goodbye!\n");
        return 0;
      default:
        printf("Invalid command entered. Please try again.\n");
        break;
    }

    // Display the drone's current status
    printf("The drone's altitude is %d.\n", altitude);
    printf("The drone's speed is %d.\n", speed);
    printf("\n");
  }

  return 0;
}