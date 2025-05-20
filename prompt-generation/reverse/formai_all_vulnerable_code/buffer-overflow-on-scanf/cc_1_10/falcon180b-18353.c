//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3
#define MAX_PASSENGERS 10
#define MAX_WAIT_TIME 5

typedef struct {
    int floor;
    int direction;
    int passengers;
} Elevator;

Elevator elevators[NUM_ELEVATORS];

void initializeElevators() {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].floor = rand() % NUM_FLOORS;
        elevators[i].direction = rand() % 2;
        elevators[i].passengers = 0;
    }
}

void printElevatorStatus() {
    printf("Elevator Status:\n");
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        printf("Elevator %d: Floor %d, Direction %d, Passengers %d\n", i + 1, elevators[i].floor, elevators[i].direction, elevators[i].passengers);
    }
}

void moveElevator(Elevator *elevator, int floor) {
    if (elevator->direction == 1 && elevator->floor > floor) {
        elevator->floor--;
        if (elevator->floor == floor) {
            elevator->direction = 0;
        }
    } else if (elevator->direction == 0 && elevator->floor < floor) {
        elevator->floor++;
        if (elevator->floor == floor) {
            elevator->direction = 1;
        }
    }
}

int main() {
    srand(time(NULL));
    initializeElevators();

    while (1) {
        printf("Press 1 to call an elevator\n");
        printf("Press 2 to see elevator status\n");
        printf("Press 3 to exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            // Call an elevator
            break;
        case 2:
            // Display elevator status
            printElevatorStatus();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}