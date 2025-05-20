//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: energetic
#include <stdio.h>

int main() {

  char user_input;
  int speed = 0;
  int direction = 0;

  printf("Welcome to your C Drone Remote Control!\n");
  printf("Please select your speed and direction:\n");
  printf("Speed options: S (slow), M (medium), F (fast)\n");
  printf("Direction options: L (left), R (right), U (up), D (down)\n");
  printf("Enter your speed (S/M/F): ");
  scanf("%c", &user_input);

  switch (user_input) {
    case 'S':
      printf("You have selected to move at a slow speed.\n");
      speed = 10;
      break;
    case 'M':
      printf("You have selected to move at a medium speed.\n");
      speed = 25;
      break;
    case 'F':
      printf("You have selected to move at a fast speed.\n");
      speed = 50;
      break;
    default:
      printf("Invalid option selected. Please try again.\n");
      return 0;
  }

  printf("Enter your direction (L/R/U/D): ");
  getchar();
  scanf("%c", &user_input);

  switch (user_input) {
    case 'L':
      printf("You have selected to move left.\n");
      direction = -1;
      break;
    case 'R':
      printf("You have selected to move right.\n");
      direction = 1;
      break;
    case 'U':
      printf("You have selected to move upwards.\n");
      direction = 2;
      break;
    case 'D':
      printf("You have selected to move downwards.\n");
      direction = -2;
      break;
    default:
      printf("Invalid option selected. Please try again.\n");
      return 0;
  }

  printf("Moving your C Drone at a speed of %d in direction %d\n", speed, direction);
  
  return 0;
}