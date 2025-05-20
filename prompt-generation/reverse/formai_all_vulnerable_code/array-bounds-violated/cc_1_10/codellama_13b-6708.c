//Code Llama-13B DATASET v1.0 Category: Elevator Simulation ; Style: creative
// Elevator Simulation

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MIN_FLOORS 1
#define MAX_ELEVATORS 5
#define MIN_ELEVATORS 1

// Structures
typedef struct {
    int floor;
    int direction; // 0 = up, 1 = down
} request_t;

typedef struct {
    int floor;
    int direction; // 0 = up, 1 = down
    int status; // 0 = idle, 1 = moving
} elevator_t;

// Functions
void simulate_elevator(int num_floors, int num_elevators, request_t *requests, elevator_t *elevators) {
    // Initialize elevators
    for (int i = 0; i < num_elevators; i++) {
        elevators[i].floor = 0;
        elevators[i].direction = 0;
        elevators[i].status = 0;
    }

    // Simulate requests
    for (int i = 0; i < num_floors; i++) {
        for (int j = 0; j < num_elevators; j++) {
            if (requests[i].floor == elevators[j].floor && requests[i].direction == elevators[j].direction) {
                elevators[j].status = 1;
            }
        }
    }

    // Move elevators
    for (int i = 0; i < num_elevators; i++) {
        if (elevators[i].status == 1) {
            if (elevators[i].direction == 0) {
                elevators[i].floor++;
            } else {
                elevators[i].floor--;
            }
        }
    }
}

int main() {
    // Initialize requests
    request_t requests[MAX_FLOORS];
    for (int i = 0; i < MAX_FLOORS; i++) {
        requests[i].floor = rand() % MAX_FLOORS + MIN_FLOORS;
        requests[i].direction = rand() % 2;
    }

    // Initialize elevators
    elevator_t elevators[MAX_ELEVATORS];
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        elevators[i].floor = 0;
        elevators[i].direction = 0;
        elevators[i].status = 0;
    }

    // Simulate elevator
    simulate_elevator(MAX_FLOORS, MAX_ELEVATORS, requests, elevators);

    // Print results
    for (int i = 0; i < MAX_FLOORS; i++) {
        printf("Elevator %d: %d\n", i + 1, elevators[i].floor);
    }

    return 0;
}