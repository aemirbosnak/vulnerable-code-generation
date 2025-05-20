//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Welcome message
  printf("Welcome to the C Drone Remote Control Program!\n");
  
  // Initialize variables
  int droneHeight = 0;
  int droneSpeed = 0;
  char droneDirection = 'S';
  
  // Start drone
  printf("Drone starting...\n");
  
  // Main loop
  while(1) {
    // Display status
    printf("Current drone height: %d\n", droneHeight);
    printf("Current drone speed: %d\n", droneSpeed);
    printf("Current drone direction: %c\n", droneDirection);
    
    // User input
    char input;
    printf("Enter command ('w' for up, 's' for down, 'a' for left, 'd' for right, 'q' to quit): ");
    scanf(" %c", &input);
    
    // Process input
    switch(input) {
      case 'w':
        droneHeight += 10;
        droneSpeed += 5;
        printf("Drone going up!\n");
        break;
      case 's':
        droneHeight -= 10;
        droneSpeed -= 5;
        printf("Drone going down!\n");
        break;
      case 'a':
        droneDirection = 'W';
        printf("Drone turning left!\n");
        break;
      case 'd':
        droneDirection = 'E';
        printf("Drone turning right!\n");
        break;
      case 'q':
        printf("Quitting program...\n");
        exit(0);
      default:
        printf("Invalid input! Please try again.\n");
    }
    
    // Check if drone has gone too high
    if (droneHeight > 100) {
      printf("Drone has gone too high! Reducing height...\n");
      droneHeight = 100;
    }
    // Check if drone has gone too low
    if (droneHeight < 0) {
      printf("Drone has crashed! Game over.\n");
      exit(0);
    }
  }
  
  // End program
  return 0;
}