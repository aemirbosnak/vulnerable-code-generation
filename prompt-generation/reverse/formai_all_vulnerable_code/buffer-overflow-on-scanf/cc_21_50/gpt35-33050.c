//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: immersive
#include <stdio.h>

// Elevator simulation variables
int currentFloor = 1;
int destinationFloor = 1;
int elevatorDoor = 0; // 0 for closed, 1 for open
int peopleInElevator = 0;
int elevatorFull = 0; // 0 for not full, 1 for full
int elevatorMoving = 0; // 0 for not moving, 1 for moving
int elevatorDirection = 0; // 0 for stationary, -1 for going down, 1 for going up

int main() {
    // Entrance prompt
    printf("Welcome to the virtual elevator simulation!\n");

    // Main loop
    while(1) {
        // Display current floor and door status
        printf("You are currently on floor %d ", currentFloor);
        if(elevatorDoor == 0) {
            printf("with the elevator door closed.\n");
        }
        else {
            printf("with the elevator door open.\n");
        }

        // Check if elevator is full
        if(peopleInElevator < 10) {
            elevatorFull = 0;
        }
        else {
            elevatorFull = 1;
        }

        // Check if elevator is moving
        if(elevatorDirection != 0) {
            elevatorMoving = 1;
        }
        else {
            elevatorMoving = 0;
        }

        // Display elevator status
        if(elevatorFull == 0 && elevatorMoving == 0) {
            printf("The elevator is currently stationary and not full.\n");
        }
        else if(elevatorFull == 0 && elevatorMoving == 1) {
            printf("The elevator is currently moving %d.\n", elevatorDirection == 1 ? "up" : "down");
        }
        else if(elevatorFull == 1 && elevatorMoving == 0) {
            printf("The elevator is currently stationary and full.\n");
        }
        else {
            printf("The elevator is currently moving %d while full.\n", elevatorDirection == 1 ? "up" : "down");
        }

        // Prompt for elevator destination floor
        while(1) {
            int inputFloor;
            printf("Please enter your destination floor (1-10): ");
            scanf("%d", &inputFloor);

            // Validate input floor
            if(inputFloor < 1 || inputFloor > 10) {
                printf("Invalid floor number. Please enter a number between 1 and 10.\n");
            }
            else if(inputFloor == currentFloor) {
                printf("You are already on that floor. Please enter a different floor number.\n");
            }
            else {
                destinationFloor = inputFloor;
                break;
            }
        }

        // Prompt for number of people in elevator
        while(1) {
            int inputPeople;
            printf("Please enter the number of people in the elevator (0-10): ");
            scanf("%d", &inputPeople);

            // Validate input number of people
            if(inputPeople < 0 || inputPeople > 10) {
                printf("Invalid number of people. Please enter a number between 0 and 10.\n");
            }
            else if(inputPeople + peopleInElevator > 10) {
                printf("There are already %d people in the elevator. Please enter a number less than or equal to %d.\n", peopleInElevator, 10 - peopleInElevator);
            }
            else {
                peopleInElevator += inputPeople;
                break;
            }
        }

        // Close elevator door
        elevatorDoor = 0;

        // Move elevator to destination floor
        while(currentFloor != destinationFloor) {
            if(currentFloor < destinationFloor) {
                elevatorDirection = 1;
                printf("The elevator is going up.\n");
                currentFloor++;
            }
            else {
                elevatorDirection = -1;
                printf("The elevator is going down.\n");
                currentFloor--;
            }
        }

        // Open elevator door
        elevatorDoor = 1;
        printf("The elevator has arrived at floor %d.\n", currentFloor);

        // Prompt for destination floor again
        printf("Thank you for using the virtual elevator simulation!\n");
        printf("Would you like to enter another destination floor (y/n)? ");
        char inputAgain;
        scanf(" %c", &inputAgain);
        if(inputAgain == 'n' || inputAgain == 'N') {
            break;
        }
    }

    return 0;
}