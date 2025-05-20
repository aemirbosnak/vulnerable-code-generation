//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define MAX_ELEVATORS 2

// Elevator structure
typedef struct {
    int floor;
    int destination;
    int direction;
} Elevator;

// Elevator functions
void elevator_init(Elevator* e, int floor);
void elevator_move(Elevator* e);
void elevator_request(Elevator* e, int destination, int direction);

// Elevator system
Elevator elevators[MAX_ELEVATORS];
int num_elevators = 0;
int num_requests = 0;

// Main function
int main() {
    // Initialize elevators
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        elevator_init(&elevators[i], 0);
    }
    num_elevators = MAX_ELEVATORS;

    // Simulate elevator requests
    int floor = 0;
    while (1) {
        printf("Enter floor number (0 to %d): ", MAX_FLOORS - 1);
        scanf("%d", &floor);
        if (floor >= 0 && floor < MAX_FLOORS) {
            break;
        }
        printf("Invalid input. Please try again.\n");
    }
    elevator_request(&elevators[0], floor, 1);

    // Simulate elevator movements
    while (num_requests > 0) {
        for (int i = 0; i < num_elevators; i++) {
            elevator_move(&elevators[i]);
        }
    }

    return 0;
}

// Elevator functions
void elevator_init(Elevator* e, int floor) {
    e->floor = floor;
    e->destination = -1;
    e->direction = 0;
}

void elevator_move(Elevator* e) {
    if (e->destination!= -1) {
        if (e->floor < e->destination) {
            e->floor++;
            e->direction = 1;
        } else if (e->floor > e->destination) {
            e->floor--;
            e->direction = -1;
        } else {
            e->destination = -1;
            e->direction = 0;
        }
    } else {
        if (e->direction == 1) {
            e->floor++;
        } else if (e->direction == -1) {
            e->floor--;
        }
    }
}

void elevator_request(Elevator* e, int destination, int direction) {
    if (destination >= 0 && destination < MAX_FLOORS &&
        direction == 1 || direction == -1) {
        e->destination = destination;
        e->direction = direction;
        num_requests++;
    } else {
        printf("Invalid request. Please try again.\n");
    }
}