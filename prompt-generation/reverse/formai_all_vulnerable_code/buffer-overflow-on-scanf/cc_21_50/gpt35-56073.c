//FormAI DATASET v1.0 Category: Robot movement control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
  int x = 0, y = 0;
  char direction = 'N';
  int steps;

  printf("Welcome to Robot Movement Control!\n");
  printf("Your robot is currently at position (%d, %d) facing %c.\n", x, y, direction);
  printf("Enter the number of steps you want the robot to take: ");
  scanf("%d", &steps);

  for(int i=0; i<steps; i++) {
    char move;
    printf("Step %d. Enter move L/R/F/B: ", i+1);
    scanf(" %c", &move);

    switch(move) {
      case 'L':
        switch(direction) {
          case 'N': direction = 'W'; break;
          case 'W': direction = 'S'; break;
          case 'S': direction = 'E'; break;
          case 'E': direction = 'N'; break;
        }
        break;

      case 'R':
        switch(direction) {
          case 'N': direction = 'E'; break;
          case 'E': direction = 'S'; break;
          case 'S': direction = 'W'; break;
          case 'W': direction = 'N'; break;
        }
        break;

      case 'F':
        switch(direction) {
          case 'N': y++; break;
          case 'E': x++; break;
          case 'S': y--; break;
          case 'W': x--; break;
        }
        break;

      case 'B':
        switch(direction) {
          case 'N': y--; break;
          case 'E': x--; break;
          case 'S': y++; break;
          case 'W': x++; break;
        }
        break;
    }
    printf("Moved %c. Robot is now at (%d, %d) facing %c.\n", move, x, y, direction);
  }

  printf("Robot has completed its movement.\n");
  return 0;
}