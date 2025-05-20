//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: recursive
#include <stdio.h>

// Function prototypes
void callElevator(int currentFloor, int targetFloor);
void moveElevator(int currentFloor, int targetFloor);

int main() {
    int totalFloors, targetFloor;

    printf("Welcome to the Elevator Simulation!\n");
    printf("Enter the total number of floors in the building: ");
    scanf("%d", &totalFloors);

    // Ensure the number of floors is positive
    if (totalFloors <= 0) {
        printf("The number of floors must be positive.\n");
        return 1;
    }

    // Ask user for the starting floor
    int currentFloor = 0;

    while (1) {
        printf("\nYou are currently on floor %d.\n", currentFloor);
        printf("Enter the target floor (0 to %d) or -1 to exit: ", totalFloors - 1);
        scanf("%d", &targetFloor);

        if (targetFloor == -1) {
            printf("Exiting the elevator simulation. Goodbye!\n");
            break;
        }

        // Check if target floor is valid
        if (targetFloor < 0 || targetFloor >= totalFloors) {
            printf("Invalid floor. Please enter a floor between 0 and %d.\n", totalFloors - 1);
            continue;
        }

        // Call the elevator to the target floor
        callElevator(currentFloor, targetFloor);
        currentFloor = targetFloor; // Update current floor after reaching target
    }

    return 0;
}

// Recursive function to simulate calling the elevator
void callElevator(int currentFloor, int targetFloor) {
    if (currentFloor == targetFloor) {
        printf("The elevator has arrived at floor %d.\n", targetFloor);
        return;
    }

    // Move the elevator
    moveElevator(currentFloor, targetFloor);
}

// Function to move the elevator in recursive style
void moveElevator(int currentFloor, int targetFloor) {
    if (currentFloor < targetFloor) {
        printf("Moving up from floor %d to floor %d...\n", currentFloor, currentFloor + 1);
        moveElevator(currentFloor + 1, targetFloor);
    } else {
        printf("Moving down from floor %d to floor %d...\n", currentFloor, currentFloor - 1);
        moveElevator(currentFloor - 1, targetFloor);
    }
}