//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define ELEVATOR_CAPACITY 4

typedef struct {
    int current_floor;
    int direction; // 1 for up, -1 for down
    int passengers_count;
    int passengers[ELEVATOR_CAPACITY];
} Elevator;

void init_elevator(Elevator *elevator) {
    elevator->current_floor = 0;
    elevator->direction = 0; // No direction
    elevator->passengers_count = 0;
}

void request_floor(Elevator *elevator, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor requested: %d\n", floor);
        return;
    }

    if (elevator->passengers_count < ELEVATOR_CAPACITY) {
        elevator->passengers[elevator->passengers_count++] = floor;
        printf("Floor %d requested, added to elevator.\n", floor);
        if (elevator->direction == 0) {
            elevator->direction = (floor > elevator->current_floor) ? 1 : -1;
        }
    } else {
        printf("Elevator is full! Cannot add request for floor %d.\n", floor);
    }
}

void move_elevator(Elevator *elevator) {
    if (elevator->direction == 0) {
        printf("Elevator is idle at floor %d.\n", elevator->current_floor);
        return;
    }

    int next_floor = elevator->current_floor + elevator->direction;

    if (next_floor < 0 || next_floor >= MAX_FLOORS) {
        printf("Elevator cannot go outside limits, reversing direction.\n");
        elevator->direction *= -1;
        next_floor = elevator->current_floor + elevator->direction;
    }

    printf("Elevator moving from floor %d to floor %d.\n", elevator->current_floor, next_floor);
    elevator->current_floor = next_floor;
}

void unload_passengers(Elevator *elevator) {
    for (int i = 0; i < elevator->passengers_count; i++) {
        if (elevator->passengers[i] == elevator->current_floor) {
            printf("Passenger is exiting on floor %d.\n", elevator->current_floor);
            for (int j = i; j < elevator->passengers_count - 1; j++) {
                elevator->passengers[j] = elevator->passengers[j + 1];
            }
            elevator->passengers_count--;
            i--; // Adjust index after removal
        }
    }

    if (elevator->passengers_count == 0) {
        printf("No more passengers, elevator is idle.\n");
        elevator->direction = 0;
    }
}

void display_status(Elevator *elevator) {
    printf("Elevator status: on floor %d, %d passengers, direction %d.\n",
           elevator->current_floor, elevator->passengers_count,
           elevator->direction);
}

int main() {
    Elevator elevator;
    init_elevator(&elevator);

    while (1) {
        int command, floor;

        display_status(&elevator);
        printf("Enter command (1: Request floor, 2: Move elevator, 0: Exit): ");
        scanf("%d", &command);

        if (command == 0) {
            printf("Exiting simulation.\n");
            break;
        } else if (command == 1) {
            printf("Enter floor to request (0-%d): ", MAX_FLOORS - 1);
            scanf("%d", &floor);
            request_floor(&elevator, floor);
        } else if (command == 2) {
            move_elevator(&elevator);
            unload_passengers(&elevator);
        } else {
            printf("Invalid command.\n");
        }

        sleep(1); // Simulate time passage for elevator movement
    }

    return 0;
}