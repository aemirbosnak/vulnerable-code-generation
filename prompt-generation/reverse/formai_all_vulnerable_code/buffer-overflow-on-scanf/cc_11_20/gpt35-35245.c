//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Shape shifting variables
  int shape = 1;  // default: car
  int wings_retracted = 1;  // default: wings retracted
  
  // Remote control variables
  char direction;  // stores direction input from user
  int speed;  // stores speed input from user
  
  // Program loop
  while(1) {
    printf("-----------------------------------\n");
    printf("Current shape: ");
    
    if(shape == 1) {
      printf("car\n");
    } else {
      printf("plane\n");
      
      if(wings_retracted) {
        printf("Wings retracted.\n");
      } else {
        printf("Wings extended.\n");
      }
    }
    
    printf("Enter direction (f, b, l, r, u, d) and speed (1-5): ");
    scanf("%c %d", &direction, &speed);
    getchar();  // remove newline from input buffer
    
    // Remote control actions
    switch(direction) {
      case 'f':
        printf("Moving forward at speed %d.\n", speed);
        break;
      case 'b':
        printf("Moving backward at speed %d.\n", speed);
        break;
      case 'l':
        printf("Turning left.\n");
        break;
      case 'r':
        printf("Turning right.\n");
        break;
      case 'u':
        if(shape == 2) {  // plane only
          wings_retracted = 0;
          printf("Wings extended.\n");
        } else {
          printf("Invalid input.\n");
        }
        break;
      case 'd':
        if(shape == 2) {  // plane only
          wings_retracted = 1;
          printf("Wings retracted.\n");
        } else {
          printf("Invalid input.\n");
        }
        break;
      default:
        printf("Invalid input.\n");
    }
    
    // Shape shifting actions
    if(direction == 'f' && shape == 2 && !wings_retracted) {
      printf("Flying forward at speed %d.\n", speed);  // plane only
    } else if (direction == 'b' && shape == 2 && !wings_retracted) {
      printf("Flying backward at speed %d.\n", speed);  // plane only
    }
    
    if(direction == 'h') {  // shape shift to car
      shape = 1;
      printf("Shape shifted to car.\n");
    } else if (direction == 'p') {  // shape shift to plane
      shape = 2;
      wings_retracted = 1;  // reset wings to retracted
      printf("Shape shifted to plane.\n");
    }
  }
  
  return 0;
}