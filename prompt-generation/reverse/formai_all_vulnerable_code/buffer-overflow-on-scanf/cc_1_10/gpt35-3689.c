//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: puzzling
#include <stdio.h>

int main() {
  char input;
  int drone_x = 0;
  int drone_y = 0;
  int distance = 0;

  printf("Welcome to the C Drone Remote Control!\n");
  printf("Press w, a, s, or d to move the drone.\n");
  printf("The drone starts at coordinates (0,0).\n");
  printf("Enter 'q' to quit the program.\n");

  while (1) {
    printf("Drone is at (%d,%d)\n", drone_x, drone_y);
    printf("Enter a command: ");
    scanf("%c", &input);

    switch (input) {
      case 'w':
        drone_y += 1;
        distance += 1;
        break;
      case 'a':
        drone_x -= 1;
        distance += 1;
        break;
      case 's':
        drone_y -= 1;
        distance += 1;
        break;
      case 'd':
        drone_x += 1;
        distance += 1;
        break;
      case 'q':
        printf("Goodbye!\n");
        return 0;
      default:
        printf("Invalid command. Try again.\n");
        break;
    }

    if (distance % 10 == 0) {
      printf("Congratulations! You have flown the drone %d meters.\n", distance);
      distance += 1;
    }

    getchar(); // Use getchar() to clear the input buffer
  }
}