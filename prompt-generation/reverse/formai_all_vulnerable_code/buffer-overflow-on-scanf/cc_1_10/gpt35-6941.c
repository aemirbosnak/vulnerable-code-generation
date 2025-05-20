//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define FLOOR_MIN 1
#define FLOOR_MAX 8
#define ELEVATOR_DELAY 1

typedef struct {
    int current_floor;
    bool is_moving;
    int destination_floor;
    int direction; // 1 for up, -1 for down
} Elevator;

void init_elevator(Elevator* e) {
    e->current_floor = 1;
    e->is_moving = false;
    e->destination_floor = -1;
    e->direction = 0;
}

void print_elevator_state(const Elevator* e) {
    printf("\nCurrent floor: %d\n", e->current_floor);
    if (e->is_moving) {
        printf("Elevator is moving towards floor %d\n\n", e->destination_floor);
    } else {
        printf("Elevator is idle\n\n");
    }
}

void move_elevator(Elevator* e) {
    if (!e->is_moving || e->current_floor == e->destination_floor) {
        return;
    }
    printf("Moving elevator from floor %d to floor %d\n", e->current_floor, e->destination_floor);
    e->current_floor += e->direction;
    printf("Arrived at floor %d\n", e->current_floor);
    if (e->current_floor == e->destination_floor) {
        e->is_moving = false;
        e->destination_floor = -1;
        e->direction = 0;
        printf("Elevator has arrived at its destination\n\n");
    }
}

int main() {
    srand(time(0));
    Elevator e1;
    init_elevator(&e1);
    printf("Welcome to the Brave Elevator Simulator!\n\n");
    while (true) {
        print_elevator_state(&e1);
        printf("Please choose a floor between %d and %d or enter -1 to exit: ", FLOOR_MIN, FLOOR_MAX);
        int floor_choice;
        scanf("%d", &floor_choice);
        if (floor_choice == -1) {
            break;
        }
        if (floor_choice < FLOOR_MIN || floor_choice > FLOOR_MAX) {
            printf("Invalid floor choice!\n");
            continue;
        }
        if (e1.current_floor == floor_choice) {
            printf("The elevator is already on floor %d\n", e1.current_floor);
        } else if (e1.is_moving) {
            printf("Sorry, the elevator is currently moving towards floor %d\n", e1.destination_floor);
        } else {
            printf("Sending elevator to floor %d\n", floor_choice);
            e1.destination_floor = floor_choice;
            if (e1.current_floor < e1.destination_floor) {
                e1.direction = 1;
            } else {
                e1.direction = -1;
            }
            e1.is_moving = true;
            usleep(ELEVATOR_DELAY * 1000);
            move_elevator(&e1);
        }
    }
    printf("Exiting elevator simulation\n");
    return 0;
}