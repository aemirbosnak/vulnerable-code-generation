//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Alan Touring
#include <stdio.h>

int main() {
  // Declare variables
  int speed = 0;
  int direction = 0;

  // Ask for initial speed and direction
  printf("Enter initial speed (integer between 0 and 100): ");
  scanf("%d", &speed);
  printf("Enter initial direction (integer between -180 and 180): ");
  scanf("%d", &direction);

  // Print initial status
  printf("Vehicle started with speed %d and direction %d\n", speed, direction);

  // Ask for commands until user inputs 'q' to quit
  char input;
  do {
    printf("Enter command (f=forward, b=backwards, l=left, r=right, s=speed up, d=slow down, q=quit): ");
    scanf("%c", &input);

    // Choose action based on input command
    switch (input) {
      case 'f':
        printf("Vehicle moving forward\n");
        break;
      case 'b':
        printf("Vehicle moving backwards\n");
        break;
      case 'l':
        printf("Vehicle turning left\n");
        break;
      case 'r':
        printf("Vehicle turning right\n");
        break;
      case 's':
        speed += 10;
        printf("Vehicle speeding up to %d\n", speed);
        break;
      case 'd':
        speed -= 10;
        printf("Vehicle slowing down to %d\n", speed);
        break;
      case 'q':
        printf("Quitting program\n");
        break;
      default:
        printf("Invalid input\n");
        break;
    }
  } while (input != 'q');

  return 0;
}