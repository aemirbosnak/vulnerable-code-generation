//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  //Initialize random seed
  srand(time(0));
  
  //Initialize variables
  int speed = 0, direction = 0;
  
  //Display welcome message and instructions
  printf("Welcome to the Remote Control Vehicle Simulation!\n");
  printf("Use the arrow keys to control the vehicle.\n");
  printf("Press 'q' to quit.\n");
  
  //Loop until user quits
  while(1) {
    //Get user input
    char input;
    printf("Enter a command: ");
    scanf("%c", &input);
    
    //Handle user input
    switch(input) {
      case 'q':
        printf("Goodbye!\n");
        return 0;
      case 'w':
        speed++;
        break;
      case 's':
        speed--;
        break;
      case 'a':
        direction--;
        break;
      case 'd':
        direction++;
        break;
      default:
        printf("Invalid command. Try again.\n");
    }
    
    //Limit speed to 10
    if(speed > 10) {
      speed = 10;
      printf("Maximum speed reached.\n");
    }
    else if(speed < 0) {
      speed = 0;
      printf("Vehicle stopped.\n");
    }
    
    //Limit direction to 360 degrees
    if(direction > 360) {
      direction -= 360;
    }
    else if(direction < 0) {
      direction += 360;
    }
    
    //Simulate vehicle movement
    int distance = speed * 10;
    int time = distance / (rand() % 10 + 1);
    printf("Vehicle moving %d meters at %d kph in direction %d degrees...\n", distance, speed, direction);
    printf("Estimated time of arrival: %d seconds\n", time);
  }
}