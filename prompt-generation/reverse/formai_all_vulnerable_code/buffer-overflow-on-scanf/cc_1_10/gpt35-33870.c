//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: cheerful
#include <stdio.h>
#include <stdbool.h>

#define MAX_FLOOR 10

int main() {
  int currentFloor = 1;
  int destination = 0;
  bool isGoingUp = true;

  printf("Welcome to the Happy Elevator!\n");
  while(true) {
    printf("Current floor: %d\n", currentFloor);
    printf("Select your destination floor (1-%d): ", MAX_FLOOR);
    scanf("%d", &destination);

    if (destination < 1 || destination > MAX_FLOOR) {
      printf("Invalid floor selected, please try again.\n");
    } else if (destination == currentFloor) {
      printf("You are already on that floor.\n");
    } else {
      printf("Going ");
      if (destination > currentFloor) {
        printf("up ");
        isGoingUp = true;
      } else {
        printf("down ");
        isGoingUp = false;
      }
      printf("to floor %d\n", destination);

      while (currentFloor != destination) {
        if (isGoingUp) {
          currentFloor++;
        } else {
          currentFloor--;
        }
        printf("Currently on floor %d\n", currentFloor);
      }

      printf("You have reached your destination on floor %d!\n", currentFloor);
    }

    printf("Would you like to go to another floor? (y/n): ");
    char userInput;
    scanf(" %c", &userInput);

    if (userInput == 'n' || userInput == 'N') {
      printf("Thank you for using the Happy Elevator, have a great day!\n");
      break;
    }
  }

  return 0;
}