//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define MAX_ELEVATORS 4

typedef struct {
    int current_floor;
    int destination_floor;
    bool is_moving;
} Elevator;

Elevator elevators[MAX_ELEVATORS];

void initialize_elevators() {
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        elevators[i].current_floor = 0;
        elevators[i].destination_floor = 0;
        elevators[i].is_moving = false;
    }
}

void move_elevator(int elevator_number, int direction) {
    if (direction == 1) {
        elevators[elevator_number].current_floor++;
    } else {
        elevators[elevator_number].current_floor--;
    }
}

void simulate_elevator_movement() {
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        if (elevators[i].is_moving) {
            move_elevator(i, elevators[i].destination_floor > elevators[i].current_floor? 1 : -1);
        }
    }
}

void print_elevator_status() {
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        printf("Elevator %d: ", i + 1);
        if (elevators[i].is_moving) {
            printf("Moving to floor %d\n", elevators[i].destination_floor);
        } else {
            printf("Idle on floor %d\n", elevators[i].current_floor);
        }
    }
}

int main() {
    initialize_elevators();

    while (true) {
        int user_input;
        printf("Enter elevator number: ");
        scanf("%d", &user_input);

        if (user_input >= 1 && user_input <= MAX_ELEVATORS) {
            printf("Enter destination floor: ");
            scanf("%d", &elevators[user_input - 1].destination_floor);
            elevators[user_input - 1].is_moving = true;
        } else {
            printf("Invalid elevator number.\n");
        }

        simulate_elevator_movement();
        print_elevator_status();

        if (elevators[user_input - 1].current_floor == elevators[user_input - 1].destination_floor) {
            elevators[user_input - 1].is_moving = false;
        }
    }

    return 0;
}