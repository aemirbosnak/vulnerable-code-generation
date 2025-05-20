//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
  // Initialization
  srand(time(0)); // Initialize random seed
  int gpsCoord[2] = {rand() % 101, rand() % 101}; // Generate random GPS coordinates
  int userCoord[2] = {0, 0}; // User's starting coordinates
  int distance = abs(userCoord[0] - gpsCoord[0]) + abs(userCoord[1] - gpsCoord[1]); // Calculate initial distance

  // GPS navigation simulation
  printf("Welcome to the GPS navigation simulation. Your starting coordinates are (%d, %d).\n", userCoord[0], userCoord[1]);
  while (distance > 0) {
    // Prompt user input
    printf("Enter a direction to move (N/S/E/W): ");
    char direction;
    scanf("%c", &direction);

    // Move user and update distance
    switch (direction) {
      case 'N':
        userCoord[0]++;
        break;
      case 'S':
        userCoord[0]--;
        break;
      case 'E':
        userCoord[1]++;
        break;
      case 'W':
        userCoord[1]--;
        break;
      default:
        printf("Invalid direction. Try again.\n");
        continue;
    }
    distance = abs(userCoord[0] - gpsCoord[0]) + abs(userCoord[1] - gpsCoord[1]);

    // Display distance and prompt user to continue or end simulation
    printf("Distance remaining: %d. Continue (Y/N)? ", distance);
    char continueSim;
    scanf(" %c", &continueSim);
    if (continueSim == 'N') {
      printf("Simulation ended. GPS coordinates were (%d, %d).\n", gpsCoord[0], gpsCoord[1]);
      break;
    }
  }

  return 0;
}