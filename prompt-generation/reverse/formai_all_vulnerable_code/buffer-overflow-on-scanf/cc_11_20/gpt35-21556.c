//FormAI DATASET v1.0 Category: Robot movement control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

/* This program controls the movement of a happy little robot! */

int main()
{
  int direction = 0;  // 0 = forward, 1 = right, 2 = back, 3 = left
  int current_x = 0;  // x-axis position
  int current_y = 0;  // y-axis position
  
  printf("Hello! I'm your happy little robot friend. Let's get moving!\n");
  
  /* Some sample movements to get us started */
  
  printf("Moving forward...\n");
  current_x++;
  
  printf("Turning right...\n");
  direction = (direction + 1) % 4;
  
  printf("Moving forward...\n");
  current_y++;
  
  printf("Turning left...\n");
  direction = (direction + 3) % 4;
  
  printf("Moving back...\n");
  current_x--;
  
  /* Now let's get some user input and start moving! */
  
  char input;
  
  do {
    printf("\nWhat would you like me to do?\n");
    printf("Enter 'w' to move forward.\n");
    printf("Enter 'a' to turn left.\n");
    printf("Enter 's' to move backward.\n");
    printf("Enter 'd' to turn right.\n");
    printf("Enter 'q' to quit.\n");
    
    scanf(" %c", &input);
    
    switch(input) {
      case 'w':
        printf("Moving forward...\n");
        if(direction == 0) {
          current_y++;
        } else if(direction == 1) {
          current_x++;
        } else if(direction == 2) {
          current_y--;
        } else {
          current_x--;
        }
        break;
      case 'a':
        printf("Turning left...\n");
        direction = (direction + 3) % 4;
        break;
      case 's':
        printf("Moving backward...\n");
        if(direction == 0) {
          current_y--;
        } else if(direction == 1) {
          current_x--;
        } else if(direction == 2) {
          current_y++;
        } else {
          current_x++;
        }
        break;
      case 'd':
        printf("Turning right...\n");
        direction = (direction + 1) % 4;
        break;
      case 'q':
        printf("Goodbye!\n");
        break;
      default:
        printf("Oops! I don't know that command. Please try again.\n");
    }
    
    printf("Current position: (%d,%d)\n", current_x, current_y);
    
  } while(input != 'q');
  
  return 0;
}