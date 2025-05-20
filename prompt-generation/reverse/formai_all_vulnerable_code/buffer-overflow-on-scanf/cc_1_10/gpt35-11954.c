//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define ELEVATOR_CAPACITY 10
#define NUM_FLOORS 20

struct elevator {
    int current_floor;
    int num_passengers;
    int max_floor;
    int min_floor;
    int direction; // 1 is going up, -1 is going down, 0 is not moving
    int passengers[ELEVATOR_CAPACITY];
};

void initialize_elevator(struct elevator *e) {
    printf("Enter the starting floor: ");
    scanf("%d", &e->current_floor);
    printf("Enter the max floor: ");
    scanf("%d", &e->max_floor);
    printf("Enter the min floor: ");
    scanf("%d", &e->min_floor);
    e->num_passengers = 0;
    e->direction = 0;
}

void board_passenger(struct elevator *e, int floor) {
    if (e->num_passengers < ELEVATOR_CAPACITY) {
        e->passengers[e->num_passengers] = floor;
        e->num_passengers++;
        printf("Passenger boarded at floor %d\n", floor);
        if (e->direction == 0) {
            e->direction = floor > e->current_floor ? 1 : -1;
        }
    } else {
        printf("Elevator is full!\n");
    }
}

void discharge_passengers(struct elevator *e) {
    int i, count = 0;
    for (i = 0; i < e->num_passengers; i++) {
        if (e->passengers[i] == e->current_floor) {
            count++;
        } else {
            e->passengers[i - count] = e->passengers[i];
        }
    }
    e->num_passengers -= count;
    printf("%d passengers discharged at floor %d\n", count, e->current_floor);
    if (e->num_passengers == 0) {
        e->direction = 0;
    }
}

void move_elevator(struct elevator *e) {
    if (e->direction == 0) {
        return;
    }
    e->current_floor += e->direction;
    printf("Elevator moved to floor %d\n", e->current_floor);
    if (e->current_floor == e->max_floor || e->current_floor == e->min_floor) {
        e->direction = 0;
    } else {
        int i;
        for (i = 0; i < e->num_passengers; i++) {
            if (e->passengers[i] > e->current_floor && e->direction == 1) {
                e->direction = 1;
                return;
            } else if (e->passengers[i] < e->current_floor && e->direction == -1) {
                e->direction = -1;
                return;
            }
        }
        e->direction = 0;
    }
}

int main() {
    struct elevator elevator;
    initialize_elevator(&elevator);
    int passenger_floors[] = {5, 3, 8, 2, 10, 15};

    for (int i = 0; i < 6; i++) {
        board_passenger(&elevator, passenger_floors[i]);
    }
    while (elevator.num_passengers > 0) {
        move_elevator(&elevator);
        discharge_passengers(&elevator);
    }
    return 0;
}