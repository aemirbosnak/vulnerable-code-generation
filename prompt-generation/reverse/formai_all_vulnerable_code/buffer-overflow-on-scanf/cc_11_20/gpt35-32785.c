//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: thoughtful
#include <stdio.h>

int main() {
  int distance = 0;
  int speed = 0;
  int direction = 0;
  
  // Welcome message
  printf("Welcome to Remote Control Vehicle Simulation!\n");
  
  // Prompt for initial distance
  printf("Please enter the initial distance from the starting point: ");
  scanf("%d", &distance);
  
  // Prompt for initial speed
  printf("Please enter the initial speed in miles per hour: ");
  scanf("%d", &speed);
  
  // Prompt for initial direction
  printf("Please enter the initial direction (0 for North, 1 for East, 2 for South, 3 for West): ");
  scanf("%d", &direction);
  
  while (1) {
    // Print current status
    printf("Current distance: %d miles.\n", distance);
    printf("Current speed: %d miles per hour.\n", speed);
    printf("Current direction: %d.\n", direction);
    
    // Prompt for next move
    printf("What do you want the remote control vehicle to do?\n");
    printf("Enter 1 to accelerate, 2 to decelerate, 3 to change direction, or 4 to exit: ");
    int move = 0;
    scanf("%d", &move);
    
    // Handle the move
    switch (move) {
      case 1:
        speed += 5;
        break;
      case 2:
        speed -= 5;
        if (speed < 0) {
          speed = 0;
        }
        break;
      case 3:
        direction = (direction + 1) % 4;
        break;
      case 4:
        printf("Thank you for using Remote Control Vehicle Simulation!\n");
        return 0;
      default:
        printf("Invalid move, please try again.\n");
    }
    
    // Update the distance based on the current speed and direction
    switch (direction) {
      case 0:
        distance += speed;
        break;
      case 1:
        distance += speed;
        break;
      case 2:
        distance -= speed;
        break;
      case 3:
        distance -= speed;
        break;
    }
  }
}