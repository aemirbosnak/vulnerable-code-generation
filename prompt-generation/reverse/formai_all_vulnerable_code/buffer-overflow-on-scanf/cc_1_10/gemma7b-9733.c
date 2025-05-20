//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: active
#include <stdio.h>

int main() {
    int floor, currentFloor = 1, direction = 0, floors = 10;

    printf("Welcome to the elevator simulator!\n");

    // Loop until the user chooses to exit
    while (1) {
        // Get the user's desired floor
        printf("Enter your desired floor (1-10): ");
        scanf("%d", &floor);

        // Check if the user's desired floor is valid
        if (floor < 1 || floor > floors) {
            printf("Invalid floor number.\n");
            continue;
        }

        // Calculate the direction of travel
        if (floor > currentFloor) {
            direction = 1;
        } else if (floor < currentFloor) {
            direction = -1;
        } else {
            printf("Already at your desired floor.\n");
            continue;
        }

        // Simulate the elevator moving to the desired floor
        for (int i = 0; i < 5; i++) {
            currentFloor += direction;
            printf("Elevator moving to floor %d...\n", currentFloor);
            sleep(1);
        }

        // Announce arrival at the desired floor
        printf("Arrived at floor %d.\n", floor);

        // Ask the user if they want to exit
        printf("Do you want to exit? (Y/N): ");
        char exitChoice;
        scanf(" %c", &exitChoice);

        // Check if the user wants to exit
        if (exitChoice == 'Y') {
            break;
        }
    }

    return 0;
}