//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int floor;
    int status;
} elevator_state;

void initialize_elevator(elevator_state *elevator) {
    elevator->floor = 0;
    elevator->status = 0;
}

void print_status(elevator_state *elevator) {
    printf("Elevator status: %d\n", elevator->status);
}

void move_up(elevator_state *elevator) {
    elevator->floor++;
    elevator->status = 1;
}

void move_down(elevator_state *elevator) {
    elevator->floor--;
    elevator->status = 2;
}

void service_call(elevator_state *elevator, int floor) {
    if (elevator->floor == floor) {
        elevator->status = 3;
    } else if (elevator->floor < floor) {
        move_up(elevator);
        service_call(elevator, floor);
    } else {
        move_down(elevator);
        service_call(elevator, floor);
    }
}

int main() {
    srand(time(NULL));
    elevator_state elevator;
    initialize_elevator(&elevator);
    int floor;

    while (1) {
        print_status(&elevator);
        printf("Enter floor: ");
        scanf("%d", &floor);

        if (floor == 0) {
            printf("No service required.\n");
        } else if (elevator.status == 1 || elevator.status == 2) {
            printf("Elevator is busy. Please wait.\n");
        } else if (floor > elevator.floor) {
            printf("Elevator is already at %d.\n", elevator.floor);
        } else {
            service_call(&elevator, floor);
        }
    }

    return 0;
}