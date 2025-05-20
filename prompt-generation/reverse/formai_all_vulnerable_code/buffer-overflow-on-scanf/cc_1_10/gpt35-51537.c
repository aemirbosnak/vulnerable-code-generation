//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 100 // maximum number of floors in the building

int main() {
    srand(time(NULL)); // initialize random number generator

    int currentFloor = 1; // elevator is initially on the first floor
    int destinationFloor;
    int numPassengers = 0; // elevator initially has no passengers

    // welcome message
    printf("Welcome to the Cyberpunk Elevator Simulation!\n");
    printf("This building has %d floors.\n", MAX_FLOORS);

    // main loop for elevator simulation
    while (1) {
        // prompt for elevator destination floor
        printf("Elevator is currently on floor %d.\n", currentFloor);
        printf("Please enter destination floor (1-%d): ", MAX_FLOORS);
        scanf("%d", &destinationFloor);

        // validate destination floor
        if (destinationFloor < 1 || destinationFloor > MAX_FLOORS) {
            printf("Error: Invalid destination floor!\n");
            continue;
        }

        // calculate number of floors passed
        int floorsPassed = abs(destinationFloor - currentFloor);

        // simulate elevator movement and display progress
        printf("Elevator is moving...\n");
        for (int i = 0; i < floorsPassed; i++) {
            if (destinationFloor > currentFloor) {
                printf("    Passing floor %d.\n", currentFloor);
                currentFloor++;
            } else {
                printf("    Passing floor %d.\n", currentFloor);
                currentFloor--;
            }
        }

        // display arrival message and update number of passengers
        printf("Elevator has arrived at floor %d.\n", destinationFloor);
        if (rand() % 2 == 0) {
            printf("    No passengers boarded the elevator.\n");
        } else {
            int numNewPassengers = rand() % 10 + 1; // generate random number of passengers
            numPassengers += numNewPassengers;
            printf("    %d passengers boarded the elevator.\n", numNewPassengers);
        }

        // display number of passengers and current floor
        printf("Elevator now has %d passengers and is on floor %d.\n", numPassengers, destinationFloor);
    }

    return 0;
}