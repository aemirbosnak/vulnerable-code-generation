//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Remote Control Vehicle Simulation!\n");
  srand(time(NULL));
  
  int battery = 100, distance = 0, speed = 0;
  char command;
  
  while (1) {
    printf("---------------------------------------------\n");
    printf("Battery: %d%%\nDistance: %d meters\nSpeed: %d m/s\n\n", battery, distance, speed);
    printf("Instructions:\nF - Increase speed\nS - Decrease speed\nL - Turn left\nR - Turn right\nX - Exit simulation\n");

    printf("Enter command: ");
    scanf(" %c", &command);

    switch (command) {
      case 'F':
        speed++;
        battery -= rand() % 10 + 5;
        distance += speed;
        break;

      case 'S':
        speed--;
        battery -= rand() % 5 + 2;
        distance += speed;
        break;

      case 'L':
        printf("Turning left...\n");
        distance -= rand() % 2 + 1;
        break;

      case 'R':
        printf("Turning right...\n");
        distance -= rand() % 2 + 1;
        break;

      case 'X':
        printf("Exiting simulation...\n");
        exit(0);

      default:
        printf("Invalid command. Try again.\n");
        break;
    }

    // Check battery level
    if (battery <= 0) {
      printf("Out of battery! Mission failed.\n");
      exit(0);
    }

    // Check distance reached
    if (distance >= 1000) {
      printf("Congratulations! You have reached your destination.\n");
      exit(0);
    }
  }

  return 0;
}