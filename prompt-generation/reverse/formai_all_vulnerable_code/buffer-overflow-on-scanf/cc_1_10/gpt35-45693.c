//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Function to simulate elevator movement
void moveElevator(int currentFloor, int destinationFloor) {
    printf("Elevator moving from Floor %d to Floor %d\n", currentFloor, destinationFloor);
    printf("Ding! You have arrived at Floor %d\n", destinationFloor);
}

int main() {
    int currentFloor = 1;
    int destinationFloor;

    // Welcome message
    printf("Welcome to Elevator Simulation!\n");

    // Loop to continuously prompt user for destination floor
    while (1) {
        printf("\nCurrent Floor: %d\n", currentFloor);
        printf("Please enter a destination floor (1-10): ");
        scanf("%d", &destinationFloor);

        // Check for valid input
        if (destinationFloor < 1 || destinationFloor > 10) {
            printf("Invalid floor. Please enter a number between 1 and 10.\n");
            continue; // Restart loop
        }

        // Check if already on destination floor
        if (currentFloor == destinationFloor) {
            printf("You are already on Floor %d.\n", currentFloor);
            continue; // Restart loop
        }

        // Elevator movement simulation
        moveElevator(currentFloor, destinationFloor);

        // Update current floor
        currentFloor = destinationFloor;

        // Prompt user to continue or exit program
        char choice;
        printf("Do you want to go to another floor? (Y/N): ");
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N') {
            printf("Thank you for using Elevator Simulation!\n");
            break; // Exit loop and program
        }
    }

    return 0;
}