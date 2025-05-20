//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: peaceful
#include <stdio.h>
#include <stdbool.h>

// Function to print the current state of the elevator
void printElevator(int currentFloor, int destinationFloor, bool isMovingUp) {
    printf("ELEVATOR: Current Floor - %d | Destination Floor - %d | isMovingUp - %d\n", currentFloor, destinationFloor, isMovingUp);
}

// Function to simulate the elevator moving up
void moveUp(int *currentFloor) {
    (*currentFloor)++;
    printf("ELEVATOR: Moving Up! Current Floor - %d\n", *currentFloor);
}

// Function to simulate the elevator moving down
void moveDown(int *currentFloor) {
    (*currentFloor)--;
    printf("ELEVATOR: Moving Down! Current Floor - %d\n", *currentFloor);
}

int main() {
    int currentFloor = 1; // Starting floor of the elevator
    int destinationFloor; // Floor entered by the user
    bool isMovingUp = true; // Direction in which the elevator is moving

    printf("Welcome to the Elevator Simulation Program!\n");

    // Loop to take input from the user and move the elevator accordingly
    while (true) {
        printf("Enter the floor you want to go to (0 to exit): ");
        scanf("%d", &destinationFloor);

        // Checking if the user wants to exit the program
        if (destinationFloor == 0) {
            printf("Thank you for using the Elevator Simulation Program!\n");
            break;
        }

        // Checking if the user has entered a valid floor number
        if (destinationFloor < 1 || destinationFloor > 10) {
            printf("Invalid floor number! Please enter a number between 1 and 10.\n");
            continue;
        }

        // Checking if the elevator is already on the destination floor
        if (destinationFloor == currentFloor) {
            printf("You are already on floor %d!\n", currentFloor);
            continue;
        }

        // Checking if the elevator needs to move up or down
        if (destinationFloor > currentFloor) {
            isMovingUp = true;
        } else {
            isMovingUp = false;
        }

        // Moving the elevator to the destination floor
        while (currentFloor != destinationFloor) {
            printElevator(currentFloor, destinationFloor, isMovingUp);

            if (isMovingUp) {
                moveUp(&currentFloor);
            } else {
                moveDown(&currentFloor);
            }
        }

        printf("ELEVATOR: You have reached floor %d.\n", currentFloor);
    }

    return 0;
}