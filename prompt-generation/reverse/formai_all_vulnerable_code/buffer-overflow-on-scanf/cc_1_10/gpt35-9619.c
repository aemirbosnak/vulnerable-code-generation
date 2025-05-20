//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: minimalist
#include <stdio.h>

int main() {
  char command;
  int altitude = 0, speed = 0;

  printf("Welcome to the C Drone Remote Control!\n");
  printf("Please use the following commands to control the drone:\n");
  printf("u - Increase altitude\n");
  printf("d - Decrease altitude\n");
  printf("f - Increase speed\n");
  printf("s - Decrease speed\n");
  printf("q - Quit program\n");

  while (1) {
    printf("Current altitude: %d meters\n", altitude);
    printf("Current speed: %d km/h\n", speed);
    printf("Enter command: ");
    scanf(" %c", &command);

    switch(command) {
      case 'u':
        altitude += 10;
        printf("Increased altitude by 10 meters.\n");
        break;

      case 'd':
        altitude -= 10;
        printf("Decreased altitude by 10 meters.\n");
        break;

      case 'f':
        speed += 10;
        printf("Increased speed by 10 km/h.\n");
        break;

      case 's':
        speed -= 10;
        printf("Decreased speed by 10 km/h.\n");
        break;

      case 'q':
        printf("Exiting program.\n");
        return 0;

      default:
        printf("Invalid command!\n");
    }
  }
}