//FormAI DATASET v1.0 Category: Robot movement control ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int robot_x = 0; // sets the initial x position of the robot to 0
  int robot_y = 0; // sets the initial y position of the robot to 0
  char direction; // declares the variable to store the direction of movement

  printf("Welcome to the Robot Movement Control Program\n");
  printf("---------------------------------------------\n");
  printf("Enter a direction for the robot to move (u for up, d for down, l for left, r for right):\n");

  srand(time(0)); // seeds the random number generator with the current time

  while (1) { // loops until user enters the letter 'q' to quit the program
    scanf("%c", &direction); // reads the direction from the user

    if (direction == 'q') { // when 'q' is entered, exits the program
      printf("Quitting program...\n");
      break;
    }

    int random_distance = rand() % 10 + 1; // generates a random distance for the robot to move between 1 and 10

    switch (direction) {
      case 'u':
        robot_y += random_distance; // moves the robot up by the random distance
        printf("Moved robot up by %d units\n", random_distance);
        break;
      case 'd':
        robot_y -= random_distance; // moves the robot down by the random distance
        printf("Moved robot down by %d units\n", random_distance);
        break;
      case 'l':
        robot_x -= random_distance; // moves the robot left by the random distance
        printf("Moved robot left by %d units\n", random_distance);
        break;
      case 'r':
        robot_x += random_distance; // moves the robot right by the random distance
        printf("Moved robot right by %d units\n", random_distance);
        break;
      default:
        printf("Invalid direction, please try again.\n");
        break;
    }

    printf("Robot's current position: (%d, %d)\n", robot_x, robot_y);
    printf("---------------------------------------------\n");
  }

  return 0;
}