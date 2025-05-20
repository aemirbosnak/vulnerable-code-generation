//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL)); // Initialize random number generator

    // Define elevator properties
    int numFloors = 5;
    int floor1 = 1;
    int floor2 = 2;
    int floor3 = 3;
    int floor4 = 4;
    int floor5 = 5;
    int elevatorMaxSpeed = 5; // Maximum speed of elevator in floors/second
    int elevatorStartFloor = 2; // Starting floor of the elevator

    // Create elevators
    int numElevators = 3;
    int elevators[3][4] = {{floor1, floor2, floor3, floor4},
                         {floor1, floor2, floor3, floor4},
                         {floor1, floor2, floor3, floor4}};
    int elevatorPositions[3] = {elevatorStartFloor, elevatorStartFloor, elevatorStartFloor};

    // Define user inputs
    int userInput;
    int currentFloor;

    // Start simulation loop
    while (1) {
        // Print elevator positions
        printf("Elevator Positions:\n");
        for (int i = 0; i < numElevators; i++) {
            printf("Elevator %d: ", i+1);
            for (int j = 0; j < 4; j++) {
                printf("%d ", elevators[i][j]);
            }
            printf("\n");
        }

        // Print current floor
        printf("Current Floor: %d\n", currentFloor);

        // Get user input
        printf("Enter 1 to go up\n");
        printf("Enter 2 to go down\n");
        printf("Enter 3 to stop\n");
        scanf("%d", &userInput);

        // Handle user input
        if (userInput == 1) {
            // Go up
            currentFloor++;
            if (currentFloor > floor5) {
                currentFloor = floor1;
            }
        } else if (userInput == 2) {
            // Go down
            currentFloor--;
            if (currentFloor < floor1) {
                currentFloor = floor5;
            }
        } else if (userInput == 3) {
            // Stop
            break;
        } else {
            printf("Invalid input!\n");
        }

        // Update elevator positions
        for (int i = 0; i < numElevators; i++) {
            elevators[i][currentFloor] = elevatorPositions[i];
            elevatorPositions[i]++;

            if (elevatorPositions[i] > floor5) {
                elevatorPositions[i] = floor1;
            }
        }

        // Update floor
        currentFloor = elevators[0][currentFloor];
    }

    return 0;
}