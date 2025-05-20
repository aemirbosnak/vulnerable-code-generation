//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define MAX_ELEVATORS 5

typedef struct {
    int id;
    int current_floor;
    int destination_floor;
    int direction; // 1 for up, -1 for down
} Elevator;

Elevator elevators[MAX_ELEVATORS];

void initialize_elevators() {
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        elevators[i].id = i;
        elevators[i].current_floor = 1;
        elevators[i].destination_floor = -1;
        elevators[i].direction = 1;
    }
}

void print_elevators() {
    printf("\nCurrent elevator status:\n");
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        printf("Elevator %d: %d/%d (%d)\n", elevators[i].id, elevators[i].current_floor, elevators[i].destination_floor, elevators[i].direction);
    }
}

void move_elevators() {
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        if (elevators[i].destination_floor == -1) {
            continue;
        }

        if (elevators[i].current_floor == elevators[i].destination_floor) {
            elevators[i].destination_floor = -1;
            continue;
        }

        if (elevators[i].direction == 1) {
            elevators[i].current_floor++;
        } else {
            elevators[i].current_floor--;
        }
    }
}

void request_elevator(int floor) {
    int best_elevator = -1;
    int min_distance = MAX_FLOORS;

    for (int i = 0; i < MAX_ELEVATORS; i++) {
        int distance = abs(elevators[i].current_floor - floor);
        if (distance < min_distance) {
            best_elevator = i;
            min_distance = distance;
        }
    }

    if (best_elevator != -1) {
        elevators[best_elevator].destination_floor = floor;
        elevators[best_elevator].direction = elevators[best_elevator].current_floor < floor ? 1 : -1;
    }
}

int main() {
    initialize_elevators();

    while (1) {
        print_elevators();

        printf("Request elevator on which floor? (1-10): ");
        int floor;
        scanf("%d", &floor);

        request_elevator(floor);

        move_elevators();
    }

    return 0;
}