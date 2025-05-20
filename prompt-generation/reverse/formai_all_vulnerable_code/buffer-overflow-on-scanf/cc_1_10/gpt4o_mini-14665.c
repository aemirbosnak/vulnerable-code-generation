//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define NUM_ELEVATORS 2

typedef struct {
    int current_floor;
    int destination_floor;
    int is_moving;
} Elevator;

Elevator elevators[NUM_ELEVATORS];

void initialize_elevators() {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].current_floor = 0;
        elevators[i].destination_floor = -1;
        elevators[i].is_moving = 0;
    }
}

void display_elevator_status() {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        printf("Elevator %d: Current Floor: %d, Destination Floor: %d, %s\n",
               i + 1, elevators[i].current_floor, elevators[i].destination_floor,
               elevators[i].is_moving ? "Moving" : "Idle");
    }
}

int choose_elevator(int requested_floor) {
    int closest_elevator = -1;
    int minimum_distance = MAX_FLOORS;

    for (int i = 0; i < NUM_ELEVATORS; i++) {
        if (!elevators[i].is_moving && abs(elevators[i].current_floor - requested_floor) < minimum_distance) {
            minimum_distance = abs(elevators[i].current_floor - requested_floor);
            closest_elevator = i;
        }
    }
    return closest_elevator;
}

void request_elevator(int requested_floor) {
    int elevator_index = choose_elevator(requested_floor);
    if (elevator_index != -1) {
        elevators[elevator_index].destination_floor = requested_floor;
        elevators[elevator_index].is_moving = 1;
        printf("Elevator %d is on the way to floor %d.\n", elevator_index + 1, requested_floor);
    } else {
        printf("All elevators are busy, please wait.\n");
    }
}

void move_elevator(int elevator_index) {
    if (elevators[elevator_index].is_moving) {
        if (elevators[elevator_index].current_floor < elevators[elevator_index].destination_floor) {
            elevators[elevator_index].current_floor++;
        } else if (elevators[elevator_index].current_floor > elevators[elevator_index].destination_floor) {
            elevators[elevator_index].current_floor--;
        }

        if (elevators[elevator_index].current_floor == elevators[elevator_index].destination_floor) {
            elevators[elevator_index].is_moving = 0;
            printf("Elevator %d has arrived at floor %d.\n", elevator_index + 1, elevators[elevator_index].current_floor);
            elevators[elevator_index].destination_floor = -1;
        }
    }
}

void update_elevators() {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        move_elevator(i);
    }
}

void simulate_elevator_system() {
    int requested_floor;

    while (1) {
        printf("\nEnter the floor you want to go to (0-9) or -1 to exit: ");
        scanf("%d", &requested_floor);

        if (requested_floor == -1) {
            printf("Exiting the Elevator Simulation. Goodbye!\n");
            break;
        } else if (requested_floor < 0 || requested_floor >= MAX_FLOORS) {
            printf("Invalid floor, please enter a value between 0 and 9.\n");
            continue;
        }

        request_elevator(requested_floor);
        update_elevators();
        display_elevator_status();
        sleep(1);
    }
}

int main() {
    initialize_elevators();
    printf("Welcome to the Elevator Simulation!\n");
    simulate_elevator_system();
    return 0;
}