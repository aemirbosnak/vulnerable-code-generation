//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 4
#define WAIT_TIME 500

int main() {
    int i, j, k, floor, elev_num, wait_time, start_time;
    char choice;

    srand(time(NULL));

    // Initialize elevator positions
    for (i = 0; i < NUM_ELEVATORS; i++) {
        printf("Elevator %d is at floor %d\n", i + 1, rand() % NUM_FLOORS + 1);
    }

    // Main loop
    while (1) {
        // Display current elevator positions
        printf("\nCurrent elevator positions:\n");
        for (i = 0; i < NUM_ELEVATORS; i++) {
            printf("Elevator %d is at floor %d\n", i + 1, rand() % NUM_FLOORS + 1);
        }

        // Ask user for input
        printf("\nEnter your choice:\n");
        printf("1. Call elevator\n2. Exit\n");
        scanf("%c", &choice);

        // User wants to call elevator
        if (choice == '1') {
            printf("Enter floor number: ");
            scanf("%d", &floor);

            // Find an available elevator
            for (i = 0; i < NUM_ELEVATORS; i++) {
                if (rand() % 2 == 0) {
                    printf("Elevator %d is available.\n", i + 1);
                    elev_num = i + 1;
                    break;
                }
            }

            // Elevator is not available, try again later
            if (i == NUM_ELEVATORS) {
                printf("All elevators are busy. Please try again later.\n");
                continue;
            }

            // Elevator is available, assign it to the user
            printf("Elevator %d has been assigned to you.\n", elev_num);

            // Simulate elevator movement
            start_time = clock();
            while (clock() - start_time < WAIT_TIME) {
                for (j = 0; j < NUM_FLOORS; j++) {
                    if (j == floor) {
                        printf("Elevator %d is at floor %d.\n", elev_num, j + 1);
                    }
                }
            }

            // Elevator has reached the destination floor
            printf("\nElevator %d has reached floor %d.\n", elev_num, floor);

            // Update elevator position
            printf("Elevator %d is now at floor %d.\n", elev_num, floor);
        }

        // User wants to exit
        else if (choice == '2') {
            break;
        }

        // Invalid input
        else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}