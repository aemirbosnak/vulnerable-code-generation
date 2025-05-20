//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototype
void printElevator(int currentFloor, int targetFloor, int numFloors);

int main() {
    srand(time(NULL)); // Random seed

    // Number of floors in the building
    int numFloors = 10;

    // Current floor and target floor of elevator
    int currentFloor = 1;
    int targetFloor = currentFloor;

    // Loop until user exits program
    while (1) {
        // Print elevator UI
        printElevator(currentFloor, targetFloor, numFloors);

        // Prompt user for input
        printf("Enter target floor (1-%d): ", numFloors);
        scanf("%d", &targetFloor);

        // Validate input
        if (targetFloor < 1 || targetFloor > numFloors) {
            printf("Invalid target floor! Please try again.\n");
            continue;
        }

        // Move elevator to target floor
        printf("Elevator moving...\n");
        while (currentFloor != targetFloor) {
            // Determine direction of movement
            if (currentFloor < targetFloor) {
                printf("Going up to floor %d\n", ++currentFloor);
            } else {
                printf("Going down to floor %d\n", --currentFloor);
            }

            // Simulate delay between floors
            int delay = rand() % 4 + 1; // Random delay between 1 and 4 seconds
            printf("Delaying for %d seconds...\n", delay);
            sleep(delay); // Pause program execution for specified number of seconds
        }

        // Print success message
        printf("Arrived at floor %d!\n\n", currentFloor);
    }

    return 0;
}

void printElevator(int currentFloor, int targetFloor, int numFloors) {
    // Clear screen
    system("clear");

    // Print title
    printf("ELEVATOR SIMULATION\n");
    printf("===================\n");

    // Print current floor and target floor
    printf("Current Floor: %d\n", currentFloor);
    printf("Target Floor: %d\n", targetFloor);

    // Print floor buttons
    printf("\nFloor Buttons:\n");
    for (int i = numFloors; i >= 1; i--) {
        if (i == currentFloor) {
            printf("[%d*]", i);
        } else if (i == targetFloor) {
            printf("[%d^]", i);
        } else {
            printf("[%d]", i);
        }
    }

    printf("\n\n");
}