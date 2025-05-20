//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of floors
#define MAX_FLOORS 10

// Define the elevator structure
typedef struct {
    int current_floor;
    int destination_floor;
    int direction;
} Elevator;

// Function to initialize the elevator
void init_elevator(Elevator* elevator) {
    elevator->current_floor = 0;
    elevator->destination_floor = 0;
    elevator->direction = 0;
}

// Function to move the elevator
void move_elevator(Elevator* elevator, int floors_to_move) {
    elevator->current_floor += floors_to_move * elevator->direction;
    if (elevator->current_floor < 0) {
        elevator->current_floor = 0;
    } else if (elevator->current_floor > MAX_FLOORS - 1) {
        elevator->current_floor = MAX_FLOORS - 1;
    }
}

// Function to request the elevator
void request_elevator(Elevator* elevator, int floor, int direction) {
    elevator->destination_floor = floor;
    elevator->direction = direction;
}

// Function to simulate the elevator
void simulate_elevator(Elevator* elevator, int num_requests) {
    int i;
    for (i = 0; i < num_requests; i++) {
        request_elevator(elevator, rand() % MAX_FLOORS, rand() % 2? 1 : -1);
        move_elevator(elevator, abs(elevator->destination_floor - elevator->current_floor));
        printf("Elevator at floor %d moving to floor %d\n", elevator->current_floor, elevator->destination_floor);
    }
}

int main() {
    Elevator elevator;
    init_elevator(&elevator);
    int num_requests;
    printf("Enter the number of elevator requests: ");
    scanf("%d", &num_requests);
    simulate_elevator(&elevator, num_requests);
    return 0;
}