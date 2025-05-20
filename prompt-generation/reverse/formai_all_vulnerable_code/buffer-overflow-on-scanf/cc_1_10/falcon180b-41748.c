//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 20
#define MAX_ELEVATORS 4

typedef struct {
    int current_floor;
    int direction;
    int target_floor;
    int waiting_time;
} elevator;

void initialize_elevator(elevator *elevator) {
    elevator->current_floor = 0;
    elevator->direction = 1;
    elevator->target_floor = 0;
    elevator->waiting_time = 0;
}

void move_elevator(elevator *elevator, int floors) {
    elevator->current_floor += elevator->direction;
    elevator->waiting_time += 2;

    if (elevator->current_floor == elevator->target_floor) {
        elevator->direction = -1 * elevator->direction;
        elevator->waiting_time = 0;
    }

    if (elevator->current_floor > floors - 1) {
        elevator->current_floor = 0;
    } else if (elevator->current_floor < 0) {
        elevator->current_floor = floors - 1;
    }
}

int main() {
    srand(time(NULL));
    int floors = rand() % MAX_FLOORS + 1;
    elevator elevators[MAX_ELEVATORS];

    printf("Welcome to the Elevator Simulator!\n");
    printf("The building has %d floors.\n", floors);

    for (int i = 0; i < MAX_ELEVATORS; i++) {
        initialize_elevator(&elevators[i]);
    }

    int requests[MAX_ELEVATORS];

    while (1) {
        printf("\nEnter floor requests for each elevator (0 to stop):\n");

        for (int i = 0; i < MAX_ELEVATORS; i++) {
            scanf("%d", &requests[i]);

            if (requests[i] == 0) {
                elevators[i].current_floor = 0;
                elevators[i].direction = 1;
                elevators[i].target_floor = 0;
                elevators[i].waiting_time = 0;
            } else {
                elevators[i].target_floor = requests[i];
            }
        }

        for (int i = 0; i < MAX_ELEVATORS; i++) {
            move_elevator(&elevators[i], floors);
        }

        printf("\nCurrent positions of elevators:\n");

        for (int i = 0; i < MAX_ELEVATORS; i++) {
            printf("Elevator %d is on floor %d\n", i + 1, elevators[i].current_floor);
        }

        printf("\n");
    }

    return 0;
}