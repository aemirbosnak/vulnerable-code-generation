//FormAI DATASET v1.0 Category: Robot movement control ; Style: careful
#include <stdio.h>

int main() {
  int position = 0;
  int command;
  
  while (1) {
    printf("Current position: %d\n", position);
    printf("Enter a command: ");
    scanf("%d", &command);
  
    switch(command) {
      case 1:
        printf("Moving forward\n");
        position++;
        break;
      
      case 2:
        printf("Moving backward\n");
        position--;
        break;

      case 3:
        printf("Turning left\n");
        break;

      case 4:
        printf("Turning right\n");
        break;

      case 5:
        printf("Jumping\n");
        break;

      case 6:
        printf("Dancing\n");
        break;
        
      case 7:
        printf("Shaking\n");
        break;
        
      case 8:
        printf("Resetting position\n");
        position = 0;
        break;

      case 9:
        printf("Exiting...\n");
        return 0;
      
      default:
        printf("Invalid command\n");
        break;
    }
  }
  return 0;
}