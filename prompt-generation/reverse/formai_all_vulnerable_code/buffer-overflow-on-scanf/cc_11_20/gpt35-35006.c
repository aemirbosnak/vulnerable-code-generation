//FormAI DATASET v1.0 Category: Robot movement control ; Style: visionary
#include <stdio.h>

int main() {
  printf("Welcome to Robot Movement Control Program!\n");

  // Initializing default values
  int x = 0, y = 0, facing = 0; // (0: North, 1: East, 2: South, 3: West)

  // Prompting user for input
  printf("Enter command, use 'F' to move forward and 'R' to turn right. Press 'Q' to quit.\n");
  char command;
  scanf("%c", &command);

  // Running program until user quits
  while (command != 'Q') {
    // Handling movement commands
    if (command == 'F') {
      switch (facing) {
        case 0: y++; break;
        case 1: x++; break;
        case 2: y--; break;
        case 3: x--; break;
      }
      printf("Moved forward. Now at position (%d, %d) facing ", x, y);

    // Handling turn commands
    } else if (command == 'R') {
      facing = (facing + 1) % 4;
      printf("Turned right. Now facing ");

    // Handling invalid commands
    } else {
      printf("Invalid command. ");
    }

    // Printing current facing direction
    switch (facing) {
      case 0: printf("North.\n"); break;
      case 1: printf("East.\n"); break;
      case 2: printf("South.\n"); break;
      case 3: printf("West.\n"); break;
    }

    // Prompting user for next command
    scanf(" %c", &command);
  }

  // Exiting program
  printf("Thank you for using Robot Movement Control Program!\n");
  return 0;
}