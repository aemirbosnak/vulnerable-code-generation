//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: accurate
//This program is an example of an elevator simulation
#include <stdio.h>
#include <stdlib.h>

#define NUM_FLOORS 10
#define ELEVATOR_CAPACITY 10

//Function to simulate elevator movement from current floor to destination floor
void moveElevator(int currentFloor, int destinationFloor) {
    printf("Elevator moving from floor %d to floor %d...\n", currentFloor, destinationFloor);
}

int main() {
    //Initial elevator state at floor 1
    int currentFloor = 1;
    int passengersCount = 0;

    printf("Elevator at floor %d\n", currentFloor);

    //Loop to simulate elevator movement and passenger loading/unloading
    while (1) {
        int destinationFloor, passengersEntered, passengersExited;

        printf("Enter destination floor:\n");

        //Read the input from user for destination floor
        if (!scanf("%d", &destinationFloor)) {
            printf("Invalid input. Please enter a valid floor number.\n");
            continue;
        }

        //Check if input is within valid limits
        if (destinationFloor < 1 || destinationFloor > NUM_FLOORS) {
            printf("Invalid floor number. Please enter a valid floor number.\n");
            continue;
        }

        //Calculate the number of passengers entering the elevator
        passengersEntered = rand() % (ELEVATOR_CAPACITY - passengersCount + 1);

        //Calculate the number of passengers exiting the elevator
        passengersExited = rand() % (passengersCount + 1);

        //Load passengers into the elevator
        passengersCount += passengersEntered;

        //Unload passengers from the elevator
        passengersCount -= passengersExited;

        //Move the elevator to the destination floor
        moveElevator(currentFloor, destinationFloor);

        //Update current floor of elevator
        currentFloor = destinationFloor;

        printf("Elevator at floor %d. Passengers in elevator: %d\n", currentFloor, passengersCount);
    }

    return 0;
}