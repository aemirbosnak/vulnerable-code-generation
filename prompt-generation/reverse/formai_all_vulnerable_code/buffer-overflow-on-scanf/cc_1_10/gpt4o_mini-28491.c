//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_RIDERS 5

typedef struct {
    int currentFloor;
    int destinationFloor;
} Rider;

typedef struct {
    int currentFloor;
    int targetFloor;
    int ridersCount;
    Rider riders[MAX_RIDERS];
} Elevator;

void initializeElevator(Elevator *elevator) {
    elevator->currentFloor = 0; // Start at ground floor
    elevator->ridersCount = 0;

    // Randomly set target floor
    elevator->targetFloor = rand() % MAX_FLOORS;
}

void addRider(Elevator *elevator) {
    if (elevator->ridersCount >= MAX_RIDERS) {
        printf("Elevator is full! No more riders can join the party.\n");
        return;
    }

    Rider newRider;
    newRider.currentFloor = rand() % MAX_FLOORS;
    newRider.destinationFloor = rand() % MAX_FLOORS;

    // Make sure rider doesn't choose their starting floor as their destination
    while (newRider.destinationFloor == newRider.currentFloor) {
        newRider.destinationFloor = rand() % MAX_FLOORS;
    }

    elevator->riders[elevator->ridersCount] = newRider;
    elevator->ridersCount++;

    printf("Rider added! Current Floor: %d, Destination Floor: %d\n",
           newRider.currentFloor, newRider.destinationFloor);
}

void updateElevator(Elevator *elevator) {
    printf("\nElevator is currently at floor %d.\n", elevator->currentFloor);
    
    // Move towards the target floor
    if (elevator->currentFloor < elevator->targetFloor) {
        elevator->currentFloor++;
        printf("Going up to floor %d...\n", elevator->currentFloor);
    } else if (elevator->currentFloor > elevator->targetFloor) {
        elevator->currentFloor--;
        printf("Going down to floor %d...\n", elevator->currentFloor);
    } else {
        printf("Arrived at floor %d. Let's see who's getting out!\n", elevator->currentFloor);
        for (int i = 0; i < elevator->ridersCount; i++) {
            if (elevator->riders[i].destinationFloor == elevator->currentFloor) {
                printf("Rider leaving the elevator to go to floor %d!\n",
                       elevator->riders[i].destinationFloor);
            }
        }
        // Remove any riders who reached their destination
        for (int i = 0; i < elevator->ridersCount; i++) {
            if (elevator->riders[i].destinationFloor == elevator->currentFloor) {
                // Shift down riders array
                for (int j = i; j < elevator->ridersCount - 1; j++) {
                    elevator->riders[j] = elevator->riders[j + 1];
                }
                elevator->ridersCount--;
                i--; // Check this index again now that the array is shifted
            }
        }
        // If no riders left, set target floor to random
        if (elevator->ridersCount == 0) {
            printf("No riders left. Going to a random floor for fun!\n");
            elevator->targetFloor = rand() % MAX_FLOORS;
        }
    }

    // Generate a new random target for the elevator
    if (elevator->ridersCount > 0) {
        elevator->targetFloor = elevator->riders[0].currentFloor; // Next rider's floor
    }
}

int main() {
    srand(time(NULL));
    Elevator elevator;
    initializeElevator(&elevator);

    printf("Welcome to the Elevator of Destiny! Prepare for nonsensical adventures!\n");

    // Main simulation loop
    while (1) {
        char input;
        printf("\nPress 'a' to add a new rider, 'u' to update the elevator, and 'q' to quit: ");
        scanf(" %c", &input);

        if (input == 'a') {
            addRider(&elevator);
        } else if (input == 'u') {
            updateElevator(&elevator);
        } else if (input == 'q') {
            printf("Exiting the Elevator of Destiny. May your floors be ever in your favor!\n");
            break;
        } else {
            printf("Oops! That's not a valid command. Try again, floor explorer!\n");
        }
    }

    return 0;
}