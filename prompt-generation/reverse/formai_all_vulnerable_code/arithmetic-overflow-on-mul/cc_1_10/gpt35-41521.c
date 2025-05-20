//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: random
#include <stdio.h>

int main() {
  int hours, minutes, seconds, total_seconds;

  printf("Welcome to the drone remote control program!\n");

  printf("Please enter the hours: ");
  scanf("%d", &hours);
  printf("Please enter the minutes: ");
  scanf("%d", &minutes);
  printf("Please enter the seconds: ");
  scanf("%d", &seconds);

  total_seconds = hours * 3600 + minutes * 60 + seconds;

  printf("\nYour input of %d hours, %d minutes, and %d seconds is equivalent to %d total seconds.\n", hours, minutes, seconds, total_seconds);

  printf("\nNow let's adjust the remote control for the drone.\n");

  int adjusting = 1;
  while (adjusting) {
    printf("\nPress 'F' to move the drone forward.\nPress 'B' to move the drone backward.\nPress 'L' to move the drone left.\nPress 'R' to move the drone right.\nPress 'U' to move the drone up.\nPress 'D' to move the drone down.\nPress 'S' to stop the drone.\nPress 'Q' to quit the program.\n\n");
    char input;
    scanf(" %c", &input);

    switch(input) {
      case 'F':
        printf("Moving the drone forward.\n");
        break;
      case 'B':
        printf("Moving the drone backward.\n");
        break;
      case 'L':
        printf("Moving the drone left.\n");
        break;
      case 'R':
        printf("Moving the drone right.\n");
        break;
      case 'U':
        printf("Moving the drone up.\n");
        break;
      case 'D':
        printf("Moving the drone down.\n");
        break;
      case 'S':
        printf("Stopping the drone.\n");
        break;
      case 'Q':
        printf("Quitting the program.\n");
        adjusting = 0;
        break;
      default:
        printf("Invalid input. Please try again.\n");
        break;
    }
  }

  printf("\nThank you for using the drone remote control program!\n");

  return 0;
}