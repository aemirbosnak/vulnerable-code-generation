//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: sophisticated
#include <stdio.h>

int main()
{
  int currentFloor = 0;
  int requestedFloor;
  int direction = 0; // 0 = stationary, 1 = up, 2 = down

  printf("Welcome to the elevator!\n");

  while(1)
  {
    printf("You are currently on floor %d.\n", currentFloor);
    printf("Which floor would you like to go to? (Enter -1 to exit)\n");
    scanf("%d", &requestedFloor);

    if(requestedFloor == -1)
      break;

    if(requestedFloor == currentFloor)
      printf("You are already on that floor.\n");

    else if(requestedFloor > currentFloor)
    {
      direction = 1;
      printf("Going up...\n");

      // Travel up to requested floor
      while(currentFloor != requestedFloor)
      {
        currentFloor++;
        printf("Floor %d...\n", currentFloor);
      }

      printf("You have arrived at floor %d.\n", currentFloor);
      direction = 0;
    }

    else if(requestedFloor < currentFloor)
    {
      direction = 2;
      printf("Going down...\n");

      // Travel down to requested floor
      while(currentFloor != requestedFloor)
      {
        currentFloor--;
        printf("Floor %d...\n", currentFloor);
      }

      printf("You have arrived at floor %d.\n", currentFloor);
      direction = 0;
    }

    else // Invalid input
      printf("Invalid input.\n");
  }

  printf("Thank you for using the elevator.");
  return 0;
}