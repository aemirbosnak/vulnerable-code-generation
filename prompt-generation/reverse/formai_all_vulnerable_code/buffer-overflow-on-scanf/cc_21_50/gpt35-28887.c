//FormAI DATASET v1.0 Category: Robot movement control ; Style: visionary
#include <stdio.h>

/*
Visionary Robot Movement Control Program
By: [Your Name Here]
*/

int main() {
  int x_position = 0;
  int y_position = 0;
  int facing_direction = 0; // 0 for North, 1 for East, 2 for South, 3 for West
  
  // Prompt user for the number of movements
  int num_movements;
  printf("Enter the number of movements: ");
  scanf("%d", &num_movements);
  
  // Prompt user for the movements
  char movements[num_movements];
  printf("Enter the movements (U for up, D for down, L for left, R for right): ");
  for (int i = 0; i < num_movements; i++) {
    scanf(" %c", &movements[i]);
  }
  
  // Execute movements
  for (int i = 0; i < num_movements; i++) {
    if (movements[i] == 'U') {
      y_position++;
    }
    else if (movements[i] == 'D') {
      y_position--;
    }
    else if (movements[i] == 'L') {
      x_position--;
    }
    else if (movements[i] == 'R') {
      x_position++;
    }
    
    if (x_position > 10 || x_position < -10 || y_position > 10 || y_position < -10) {
      printf("Error: Robot has gone out of bounds.\n");
      break;
    }
    
    // Update facing direction based on movements
    // 0 - North, 1 - East, 2 - South, 3 - West
    if (movements[i] == 'U' && facing_direction != 2) {
      facing_direction = 0;
    }
    else if (movements[i] == 'D' && facing_direction != 0) {
      facing_direction = 2;
    }
    else if (movements[i] == 'L' && facing_direction != 1) {
      facing_direction = 3;
    }
    else if (movements[i] == 'R' && facing_direction != 3) {
      facing_direction = 1;
    }
  }
  
  // Output final position
  printf("Robot's final position: (%d, %d)\n", x_position, y_position);
  
  // Output facing direction
  printf("Robot is facing ");
  switch (facing_direction) {
    case 0: printf("North"); break;
    case 1: printf("East"); break;
    case 2: printf("South"); break;
    case 3: printf("West"); break;
    default: printf("an unknown direction"); break;
  }
  printf(".\n");
  
  return 0;
}