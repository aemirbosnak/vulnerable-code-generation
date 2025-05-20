//FormAI DATASET v1.0 Category: Robot movement control ; Style: innovative
#include <stdio.h>

int main() {
  char direction = 'S'; // Start robot facing south
  int x = 0; // Robot's x-coordinate
  int y = 0; // Robot's y-coordinate
  
  while (1) { // Infinite loop until program is stopped
    printf("Robot is facing %c. Current position: (%d, %d)\n", direction, x, y);
    printf("Enter direction (F=forward, R=right, L=left): ");
    char input;
    scanf(" %c", &input);
    
    if (input == 'F') {
      // Move the robot forward one space in the direction it is facing
      if (direction == 'N')
        y++;
      else if (direction == 'S')
        y--;
      else if (direction == 'E')
        x++;
      else if (direction == 'W')
        x--;
    } else if (input == 'R') {
      // Rotate the robot 90 degrees to the right
      if (direction == 'N')
        direction = 'E';
      else if (direction == 'S')
        direction = 'W';
      else if (direction == 'E')
        direction = 'S';
      else if (direction == 'W')
        direction = 'N';
    } else if (input == 'L') {
      // Rotate the robot 90 degrees to the left
      if (direction == 'N')
        direction = 'W';
      else if (direction == 'S')
        direction = 'E';
      else if (direction == 'E')
        direction = 'N';
      else if (direction == 'W')
        direction = 'S';
    } else {
      printf("Invalid input. Please try again.\n");
      continue; // Go back to the beginning of the loop
    }
  }
  
  return 0;
}