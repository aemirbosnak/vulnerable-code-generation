//MISTRAL-7B DATASET v1.0 Category: Elevator Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 10

typedef struct {
    int floor;
    int is_occupied;
} ElevatorFloor;

typedef struct {
    int current_floor;
    ElevatorFloor floors[MAX_FLOORS];
    int capacity;
    int number_of_passengers;
} Elevator;

void simulate_elevator(Elevator *elevator) {
    int destination_floor, direction;
    while (1) {
        printf("Current floor: %d\n", elevator->current_floor);
        // Get user input for destination floor and direction
        scanf("%d%d", &destination_floor, &direction);

        // Move elevator to the next floor
        elevator->current_floor += direction;

        // Update the state of the elevator's floors
        for (int i = 0; i < MAX_FLOORS; ++i) {
            if (i == elevator->current_floor) {
                elevator->floors[i].is_occupied = 1;
            } else {
                elevator->floors[i].is_occupied = 0;
            }
        }

        // Pick up or drop off passengers
        if (elevator->number_of_passengers < MAX_CAPACITY) {
            if (elevator->floors[destination_floor].is_occupied == 0) {
                elevator->floors[destination_floor].is_occupied = 1;
                elevator->number_of_passengers++;
                printf("Passenger picked up on floor %d\n", destination_floor);
            } else {
                printf("Elevator is already full\n");
            }
        } else {
            printf("Elevator is already full. Please wait for the next one.\n");
        }

        // Wait for the door to close
        sleep(2);
    }
}

int main() {
    Elevator elevator = {.current_floor = 0, .capacity = MAX_CAPACITY};
    simulate_elevator(&elevator);
    return 0;
}