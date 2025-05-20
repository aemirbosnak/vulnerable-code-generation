//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int floor;
    bool open;
} Floor;

int main() {
    // Initialize the elevator floor and open status
    Floor floors[4] = { {0, false}, {1, false}, {2, false}, {3, false} };
    int currentFloor = 0;
    int targetFloor = 0;

    // Simulate the elevator
    while (1) {
        // Prompt the user to input a floor number
        printf("Enter a floor number (0-3): ");
        scanf("%d", &targetFloor);

        // Check if the target floor is within the elevator's range
        if (targetFloor < 0 || targetFloor > 3) {
            printf("Invalid floor number, please try again.\n");
            continue;
        }

        // Move the elevator to the target floor
        if (currentFloor == targetFloor) {
            printf("Already at floor %d.\n", targetFloor);
            continue;
        }
        if (currentFloor > targetFloor) {
            printf("Moving from floor %d to floor %d.\n", currentFloor, targetFloor);
            currentFloor = targetFloor;
        } else {
            printf("Moving from floor %d to floor %d.\n", targetFloor, currentFloor);
            currentFloor = targetFloor;
        }

        // Update the floor's open status
        for (int i = 0; i < 4; i++) {
            if (floors[i].floor == targetFloor) {
                floors[i].open = true;
            }
        }

        // Print the updated floor status
        printf("Current floor: %d\n", currentFloor);
        printf("Open floors: ");
        for (int i = 0; i < 4; i++) {
            if (floors[i].open) {
                printf("(%d) ", floors[i].floor);
            }
        }
        printf("\n");
    }

    return 0;
}