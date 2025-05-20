//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int x = 0, y = 0; // coordinates of the vehicle
  
  // randomly generate starting point
  srand(time(NULL));
  x = rand() % 10;
  y = rand() % 10;

  printf("Starting point of the vehicle: (%d, %d)\n", x, y);
  printf("You can move the vehicle using the following commands:\n");
  printf("1. Press 'U' to move up\n");
  printf("2. Press 'D' to move down\n");
  printf("3. Press 'L' to move left\n");
  printf("4. Press 'R' to move right\n");
  
  char input;
  while (1) {
    printf("Enter your command: ");
    scanf(" %c", &input);
    
    // update coordinates based on user input
    switch (input) {
      case 'U':
        y++;
        break;
      case 'D':
        y--;
        break;
      case 'L':
        x--;
        break;
      case 'R':
        x++;
        break;
      default:
        printf("Invalid command. Please try again.\n");
    }
    
    // check if vehicle goes out of bounds
    if (x < 0 || x > 9 || y < 0 || y > 9) {
      printf("Vehicle went out of bounds. Game over!\n");
      break;
    }
    
    // print updated coordinates
    printf("Current position of the vehicle: (%d, %d)\n", x, y);
  }
  
  return 0;
}