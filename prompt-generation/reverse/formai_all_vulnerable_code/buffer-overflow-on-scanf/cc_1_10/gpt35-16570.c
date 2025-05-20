//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>

int main()
{
  int current_floor = 1, destination_floor, direction = 1;
  int i, j;

  printf("Welcome to the Elevator Simulator!\n\n");

  // ask for the user's destination floor
  printf("Please enter your destination floor (1 to 10): ");
  scanf("%d", &destination_floor);

  // check if the destination floor is valid
  if(destination_floor < 1 || destination_floor > 10)
  {
    printf("\nInvalid floor selected. Please try again.\n");
    exit(1);
  }

  // simulate the elevator ride
  printf("\nElevator doors closing...\n");
  printf("Elevator going up...\n\n");

  for(i = 1; i <= 10; i++)
  {
    // print the current floor and direction
    printf("Floor %d - ", current_floor);

    if(direction == 1)
      printf("Going up.\n");
    else
      printf("Going down.\n");

    // change the direction if we reach the top or bottom floor
    if(current_floor == 10)
      direction = -1;
    else if(current_floor == 1)
      direction = 1;

    // move the elevator one floor up or down
    current_floor += direction;

    // stop at the user's destination floor
    if(current_floor == destination_floor)
    {
      printf("\nDing! You have arrived at floor %d.\n", destination_floor);
      break;
    }

    // pause for a moment between floors
    for(j = 0; j < 1000000; j++);
  }

  printf("\nElevator doors opening...\n\n");

  return 0;
}