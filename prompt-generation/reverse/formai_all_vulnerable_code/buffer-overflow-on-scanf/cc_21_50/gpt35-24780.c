//FormAI DATASET v1.0 Category: Robot movement control ; Style: standalone
#include <stdio.h>

#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

int main() {
  
  int direction = FORWARD; // Set initial direction to forward
  int x = 0, y = 0; // Start at position (0,0)
  
  while (1) { // Infinite loop to keep robot moving
    
    // Get the next command from user
    printf("Enter next direction: ");
    int input;
    scanf("%d", &input);
    
    // Update direction based on user input
    if (input == LEFT) {
      if (direction == FORWARD) {
        direction = LEFT;
      } else if (direction == BACKWARD) {
        direction = RIGHT;
      } else if (direction == LEFT) {
        direction = BACKWARD;
      } else if (direction == RIGHT) {
        direction = FORWARD;
      }
    } else if (input == RIGHT) {
      if (direction == FORWARD) {
        direction = RIGHT;
      } else if (direction == BACKWARD) {
        direction = LEFT;
      } else if (direction == LEFT) {
        direction = FORWARD;
      } else if (direction == RIGHT) {
        direction = BACKWARD;
      }
    } else if (input == BACKWARD) {
      if (direction == FORWARD) {
        direction = BACKWARD;
      } else if (direction == BACKWARD) {
        direction = FORWARD;
      } else if (direction == LEFT) {
        direction = RIGHT;
      } else if (direction == RIGHT) {
        direction = LEFT;
      }
    }
    
    // Move robot based on direction
    if (direction == FORWARD) {
      y++;
    } else if (direction == BACKWARD) {
      y--;
    } else if (direction == LEFT) {
      x--;
    } else if (direction == RIGHT) {
      x++;
    }
    
    // Print current position
    printf("Robot is at position (%d,%d)\n", x, y);
  }
  
  return 0;
}