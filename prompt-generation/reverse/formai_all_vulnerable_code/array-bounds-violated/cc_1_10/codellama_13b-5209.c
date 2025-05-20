//Code Llama-13B DATASET v1.0 Category: Elevator Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10
#define MAX_PASSENGERS 5
#define MIN_PASSENGERS 1
#define MAX_WAIT_TIME 10
#define MIN_WAIT_TIME 5

typedef struct {
    int floor;
    int direction;
} Passenger;

Passenger passengers[MAX_PASSENGERS];

void printPassengers(Passenger *passengers, int numPassengers) {
    printf("Passengers: ");
    for (int i = 0; i < numPassengers; i++) {
        printf("%d ", passengers[i].floor);
    }
    printf("\n");
}

void simulateElevator() {
    int currentFloor = 0;
    int numPassengers = 0;
    int waitingTime = 0;
    int passengerDirection = 0;

    srand(time(NULL));

    while (1) {
        // Simulate passenger arrival
        if (rand() % 2 == 0) {
            // Check if there is enough space for a new passenger
            if (numPassengers < MAX_PASSENGERS) {
                Passenger newPassenger;
                newPassenger.floor = rand() % NUM_FLOORS;
                newPassenger.direction = rand() % 2 == 0 ? 1 : -1;
                passengers[numPassengers++] = newPassenger;
            }
        }

        // Simulate elevator movement
        if (passengers[0].floor == currentFloor) {
            // Open doors
            printf("Doors opened on floor %d\n", currentFloor);
            printPassengers(passengers, numPassengers);

            // Simulate passenger departure
            if (passengers[0].direction == -1) {
                // Check if there are more passengers to be dropped off
                if (passengers[0].floor == 0) {
                    // Drop off passenger
                    printf("Passenger dropped off on floor 0\n");
                    passengers[0] = passengers[--numPassengers];
                }
            } else {
                // Check if there is space for a new passenger
                if (numPassengers < MAX_PASSENGERS) {
                    // Pick up passenger
                    printf("Passenger picked up on floor %d\n", currentFloor);
                    passengers[numPassengers++] = passengers[0];
                }
            }

            // Close doors
            printf("Doors closed on floor %d\n", currentFloor);
        }

        // Simulate waiting time
        waitingTime = rand() % (MAX_WAIT_TIME - MIN_WAIT_TIME) + MIN_WAIT_TIME;
        printf("Waiting for %d seconds...\n", waitingTime);
        sleep(waitingTime);

        // Simulate floor change
        currentFloor = (currentFloor + passengers[0].direction) % NUM_FLOORS;
        printf("Moved to floor %d\n", currentFloor);
    }
}

int main() {
    simulateElevator();
    return 0;
}