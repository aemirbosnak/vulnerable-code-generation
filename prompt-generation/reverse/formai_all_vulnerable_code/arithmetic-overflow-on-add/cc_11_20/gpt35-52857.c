//FormAI DATASET v1.0 Category: Robot movement control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Hi there! Let's make this robot dance! \n");

  int x_position = 0;
  int y_position = 0;
  int direction = 0;

  printf("Enter the starting X position: ");
  scanf("%d", &x_position);
  printf("Enter the starting Y position: ");
  scanf("%d", &y_position);

  printf("Great! Now let's get this robot moving! \n");

  printf("Press 'w' to move forward, 'a' to turn left, 'd' to turn right, and 'q' to quit. \n");

  while (1) {
    char movement;
    scanf(" %c", &movement);

    if (movement == 'q') {
      printf("Goodbye! \n");
      break;
    } else if (movement == 'w') {
      int distance;
      printf("Enter the distance to move forward: ");
      scanf("%d", &distance);

      if (direction == 0) {
        y_position += distance;
      } else if (direction == 90) {
        x_position += distance;
      } else if (direction == 180) {
        y_position -= distance;
      } else if (direction == 270) {
        x_position -= distance;
      }

      printf("New position: (%d,%d) \n", x_position, y_position);
    } else if (movement == 'a') {
      direction -= 90;
      if (direction < 0) {
        direction += 360;
      }

      printf("New direction: %d \n", direction);
    } else if (movement == 'd') {
      direction += 90;
      if (direction >= 360) {
        direction -= 360;
      }

      printf("New direction: %d \n", direction);
    } else {
      printf("Invalid input. Please try again. \n");
    }
  }

  return 0;
}