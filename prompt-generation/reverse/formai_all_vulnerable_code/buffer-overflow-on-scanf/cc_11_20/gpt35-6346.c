//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {

  int floor = 1;
  int direction = 0;
  int destination;
  int passengers = 0; 
  int elevator = 0; 
  time_t t;

  srand((unsigned) time(&t)); //Seed random number generator

  printf("Welcome to the most unreliable elevator in the world!\n");

  while(1) { //Infinite loop for elevator simulation

    printf("\nCurrent Floor: %d\n", floor); //Display current floor

    if(elevator == 0) { //If elevator is on current floor

      if(passengers > 0) { //If there are passengers in the elevator
        printf("Doors Open! Please exit the elevator.\n");
        passengers = 0; //Remove all passengers
        direction = 0; //Reset direction
      }

      printf("Doors Open! Press 'Enter' to call elevator to another floor.\n");
      getchar(); //Wait for user to press enter

      printf("Which floor would you like to go to? (1-5): ");
      scanf("%d", &destination); //Get destination floor from user

      if(destination < 1 || destination > 5) { //If floor is out of range
        printf("Invalid floor!\n");
      } else {
        direction = (destination > floor) ? 1 : -1; //Set direction based on destination floor
        elevator = 1; //Elevator is called to another floor
      }

    } else { //If elevator is not on current floor

      if(floor == destination) { //If elevator has reached destination
        printf("Doors Open! Please exit the elevator.\n");
        passengers = 0; //Remove all passengers
        elevator = 0; //Elevator is available on this floor
        direction = 0; //Reset direction
      } else {
        printf("Elevator moving %s.\n", (direction > 0) ? "up" : "down"); //Display direction elevator is moving
        floor += direction; //Update floor
      }

    }

    if(elevator == 1 && floor == destination) { //If elevator has reached destination
      printf("Doors Open! Please enter the elevator.\n");
      passengers = rand() % 10; //Generate random number of passengers between 0-9
      printf("Closing doors!\n");
      sleep(2); //Sleep for 2 seconds to simulate doors closing
    }

  }

  return 0;
}