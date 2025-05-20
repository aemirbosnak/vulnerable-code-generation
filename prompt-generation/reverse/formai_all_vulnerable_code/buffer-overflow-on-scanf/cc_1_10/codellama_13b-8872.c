//Code Llama-13B DATASET v1.0 Category: Elevator Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 10

typedef struct {
    int floor;
    int direction;
} Passenger;

int main() {
    Passenger passengers[MAX_PASSENGERS];
    int num_passengers = 0;

    // Initialize passengers
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        passengers[i].floor = 0;
        passengers[i].direction = 0;
    }

    // Simulate elevator
    while (1) {
        // Get current floor
        int current_floor = 0;
        scanf("%d", &current_floor);

        // Check if there are any passengers
        if (num_passengers == 0) {
            // If no passengers, wait for one
            printf("No passengers, waiting for one...\n");
            continue;
        }

        // Check if there is a passenger on the current floor
        for (int i = 0; i < num_passengers; i++) {
            if (passengers[i].floor == current_floor) {
                // If there is a passenger on the current floor, move to the next floor
                printf("Moving to next floor...\n");
                current_floor++;

                // Remove passenger from list
                for (int j = i; j < num_passengers - 1; j++) {
                    passengers[j] = passengers[j + 1];
                }
                num_passengers--;

                // Break to avoid duplicate passengers
                break;
            }
        }

        // Check if the elevator is on the top floor
        if (current_floor == MAX_FLOORS) {
            // If the elevator is on the top floor, move to the first floor
            printf("Moving to first floor...\n");
            current_floor = 0;
        }

        // Print current floor
        printf("Current floor: %d\n", current_floor);
    }

    return 0;
}