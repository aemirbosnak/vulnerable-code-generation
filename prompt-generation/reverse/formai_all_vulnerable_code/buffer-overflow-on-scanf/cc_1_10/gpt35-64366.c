//FormAI DATASET v1.0 Category: Robot movement control ; Style: ultraprecise
#include <stdio.h>

int main() {

  // Set initial position of robot
  int xPos = 0;
  int yPos = 0;

  // Set step size and maximum movement distance
  int stepSize = 1;
  int maxDistance = 10;

  // Set movement direction
  char moveDir = 'F';

  // Loop until maximum distance is reached
  while (xPos < maxDistance && yPos < maxDistance) {

    // Execute movement based on direction
    switch (moveDir) {
      case 'F':
        xPos += stepSize;
        break;
      case 'B':
        xPos -= stepSize;
        break;
      case 'R':
        yPos += stepSize;
        break;
      case 'L':
        yPos -= stepSize;
        break;
      default:
        printf("Invalid direction!");
        break;
    }

    // Print current position
    printf("Current position is (%d, %d)\n", xPos, yPos);

    // Prompt for next movement direction
    printf("Enter next movement direction (F/B/R/L): ");
    scanf(" %c", &moveDir);

  }

  // Print final position
  printf("Final position is (%d, %d)\n", xPos, yPos);

  return 0;

}