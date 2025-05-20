//FormAI DATASET v1.0 Category: Robot movement control ; Style: immersive
#include <stdio.h>

int main() {
  // Setting initial position
  int xPos = 0; // Horizontal position
  int yPos = 0; // Vertical position
  
  // Printing initial position
  printf("Current position: (%d, %d)\n", xPos, yPos);
  
  // Movement control
  char direction;
  int steps;
  
  printf("Enter 'f' for forward, 'b' for backward, 'l' for left, 'r' for right.\n");
  printf("Enter number of steps to move.\n");
  printf("To exit program, enter 'q' for direction.\n");
  
  while (1) {
    printf("Enter direction and steps: ");
    scanf("%c %d", &direction, &steps);
    
    if (direction == 'q') {
      printf("Program Exiting...");
      break;
    }
    
    switch(direction) {
      case 'f':
        yPos += steps;
        break;
      case 'b':
        yPos -= steps;
        break;
      case 'l':
        xPos -= steps;
        break;
      case 'r':
        xPos += steps;
        break;
      default:
        printf("Invalid direction. Try again.");
        break;
    }
    
    // Printing updated position
    printf("Current position: (%d, %d)\n", xPos, yPos);
    getchar(); // To handle unwanted input
  }
  
  return 0;
}