//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int speed = 0;
  char direction = 'N';

  printf("Welcome to the Remote Control Vehicle Simulator!\n");
  printf("To get started, please enter an initial speed for the vehicle (0-100): ");

  // Get the initial speed from the user
  scanf("%d", &speed);

  if (speed < 0 || speed > 100) {
    printf("Invalid speed entered. Exiting.\n");
    exit(0);
  }

  // Print the initial speed
  printf("Initial speed set to %d mph.\n", speed);

  // Get the initial direction from the user
  printf("Please enter an initial direction for the vehicle (N/S/E/W): ");
  scanf(" %c", &direction);

  // Print the initial direction
  printf("Initial direction set to %c.\n", direction);

  // Start the simulation loop
  while (1) {
    printf("Current speed: %d mph | Current direction: %c\n", speed, direction);
    printf("Enter a command (F = increase speed, B = decrease speed, L = turn left, R = turn right, Q = quit): ");
    
    // Get the user's command
    char command;
    scanf(" %c", &command);

    // Handle the user's command
    switch (command) {
      case 'F':
        if (speed < 100) speed++;
        break;
      case 'B':
        if (speed > 0) speed--;
        break;
      case 'L':
        if (direction == 'N') direction = 'W';
        else if (direction == 'W') direction = 'S';
        else if (direction == 'S') direction = 'E';
        else if (direction == 'E') direction = 'N';
        break;
      case 'R':
        if (direction == 'N') direction = 'E';
        else if (direction == 'E') direction = 'S';
        else if (direction == 'S') direction = 'W';
        else if (direction == 'W') direction = 'N';
        break;
      case 'Q':
        printf("Exiting the program...\n");
        exit(0);
      default:
        printf("Invalid command entered. Please try again.\n");
        break;
    }
  }

  return 0;
}