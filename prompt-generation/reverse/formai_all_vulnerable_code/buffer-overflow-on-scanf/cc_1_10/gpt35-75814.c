//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FLOORS 10

struct Elevator {
    int current_floor;
    bool doors_open;
    bool moving_up;
};

struct Elevator elevator = {1, false, true};

// move the elevator up or down a certain number of floors
void move_elevator(int num_floors) {
    for (int i = 0; i < num_floors; i++) {
        elevator.current_floor += (elevator.moving_up ? 1 : -1);
        printf("Elevator moving to floor %d\n", elevator.current_floor);
    }
}

// open the elevator doors
void open_doors() {
    elevator.doors_open = true;
    printf("Elevator doors opening\n");
}

// close the elevator doors
void close_doors() {
    elevator.doors_open = false;
    printf("Elevator doors closing\n");
}

// print the current state of the elevator (floor and door status)
void print_state() {
    printf("Elevator on floor %d with doors %s\n", elevator.current_floor, (elevator.doors_open ? "open" : "closed"));
}

int main() {
    int destination;

    printf("Elevator simulation starting on floor %d\n", elevator.current_floor);

    while (true) {
        // ask user for the desired floor
        printf("Which floor do you want to go to? (1-%d, or 0 to exit)\n", MAX_FLOORS);
        scanf("%d", &destination);

        if (destination == 0) {
            printf("Exiting elevator simulation\n");
            return 0;
        }

        // ensure the selected floor is within the valid range
        if (destination < 1 || destination > MAX_FLOORS) {
            printf("Invalid floor selected\n");
            continue;
        }

        // determine direction to move the elevator
        if (destination > elevator.current_floor) {
            elevator.moving_up = true;
        } else if (destination < elevator.current_floor) {
            elevator.moving_up = false;
        } else {
            printf("Already on floor %d\n", elevator.current_floor);
            open_doors();
            continue;
        }

        // close the elevator doors and move to the desired floor
        close_doors();
        move_elevator(abs(destination - elevator.current_floor));
        open_doors();

        // update the current floor status
        elevator.current_floor = destination;
        print_state();
    }

    return 0;
}