//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: detailed
#include <stdio.h>

int main() {
  // Define the variables for the simulation
  int speed = 0;  
  int angle = 0;
  int direction = 0;
  
  // Display initial settings to user
  printf("Welcome to the Remote Control Vehicle Simulation!\n\n");
  printf("Current settings:\n");
  printf("Speed: %d\n", speed);
  printf("Angle: %d\n", angle);
  printf("Direction: %d\n\n", direction);
  
  // Allow user to input commands
  char input;
  
  do {
    printf("Please enter a command (w=accelerate, s=decelerate, a=turn left, d=turn right, x=exit): ");
    scanf(" %c", &input);
    
    switch(input) {
      case 'w':
        speed = speed + 1;  // Increase speed by 1
        printf("Accelerating...\n");
        break;
      case 's':
        if (speed > 0) {
          speed = speed - 1;  // Decrease speed by 1
          printf("Decelerating...\n");
        } else {
          printf("Vehicle is already stopped.\n");
        }
        break;
      case 'a':
        if (angle > -90) {
          angle = angle - 10;  // Decrease angle by 10 degrees
          printf("Turning left...\n");
        } else {
          printf("Cannot turn left any further.\n");
        }
        break;
      case 'd':
        if (angle < 90) {
          angle = angle + 10;  // Increase angle by 10 degrees
          printf("Turning right...\n");
        } else {
          printf("Cannot turn right any further.\n");
        }
        break;
      case 'x':
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid command.\n");
        break;
    }
    
    if (input != 'x') {
      // Determine the direction based on the angle
      if (angle == 0) {
        direction = 0;  // Straight ahead
      } else if (angle < 0) {
        direction = -1;  // Turned left
      } else {
        direction = 1;  // Turned right
      }
      
      // Display the updated settings to the user
      printf("\nCurrent settings:\n");
      printf("Speed: %d\n", speed);
      printf("Angle: %d\n", angle);
      printf("Direction: %d\n\n", direction);
    }
  } while (input != 'x');
  
  return 0;
}