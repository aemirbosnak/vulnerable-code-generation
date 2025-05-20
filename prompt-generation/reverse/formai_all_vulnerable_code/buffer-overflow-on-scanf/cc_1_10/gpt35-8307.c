//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 2

typedef enum {
    DIR_STOP = 0,
    DIR_UP,
    DIR_DOWN
} direction_t;

typedef struct {
    int curr_floor;
    int dest_floor;
    direction_t direction;
    bool is_busy;
    bool is_moving;
    bool is_door_open;
} elevator_t;

void move_elevator(elevator_t *elevator, int dest_floor);
void open_door(elevator_t *elevator);
void close_door(elevator_t *elevator);
void print_status(elevator_t elevators[]);

int main(void) {
    elevator_t elevators[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].curr_floor = 0;
        elevators[i].is_busy = false;
        elevators[i].is_moving = false;
        elevators[i].is_door_open = false;
        elevators[i].direction = DIR_STOP;
    }

    printf("Welcome to the Elevator Simulation\n");

    while (true) {
        print_status(elevators);

        // Take input from user
        int elevator_index, dest_floor;
        printf("Enter elevator number and destination floor: ");
        scanf("%d %d", &elevator_index, &dest_floor);

        if (elevator_index >= NUM_ELEVATORS) {
            printf("Invalid elevator number\n");
            continue;
        }

        if (dest_floor < 0 || dest_floor >= NUM_FLOORS) {
            printf("Invalid destination floor\n");
            continue;
        }

        elevator_t *elevator = &elevators[elevator_index];
        if (elevator->is_busy) {
            printf("Elevator is already busy\n");
            continue;
        }

        move_elevator(elevator, dest_floor);
    }

    return EXIT_SUCCESS;
}

/**
 * Move the elevator to the destination floor
 */
void move_elevator(elevator_t *elevator, int dest_floor) {
    elevator->dest_floor = dest_floor;
    elevator->is_busy = true;

    if (elevator->curr_floor > dest_floor) {
        elevator->direction = DIR_DOWN;
    } else if (elevator->curr_floor < dest_floor) {
        elevator->direction = DIR_UP;
    } else {
        elevator->direction = DIR_STOP;
    }

    elevator->is_moving = true;

    printf("Elevator is moving from floor %d to floor %d\n", elevator->curr_floor, dest_floor);

    while (elevator->curr_floor != dest_floor) {
        if (elevator->direction == DIR_UP) {
            elevator->curr_floor++;
        } else if (elevator->direction == DIR_DOWN) {
            elevator->curr_floor--;
        }

        printf("Elevator is now on floor %d\n", elevator->curr_floor);

        // Pause the program for some time to simulate elevator movement
        for (int i = 0; i < 100000000; i++);
    }

    elevator->is_moving = false;
    elevator->is_door_open = true;

    open_door(elevator);

    printf("Elevator has reached destination floor %d\n", dest_floor);

    close_door(elevator);

    elevator->is_busy = false;
}

/**
 * Open the elevator door
 */
void open_door(elevator_t *elevator) {
    printf("Elevator door is opening...\n");

    // Pause the program to simulate opening the door
    for (int i = 0; i < 50000000; i++);

    elevator->is_door_open = true;

    printf("Elevator door is open\n");
}

/**
 * Close the elevator door
 */
void close_door(elevator_t *elevator) {
    printf("Elevator door is closing...\n");

    // Pause the program to simulate closing the door
    for (int i = 0; i < 50000000; i++);

    elevator->is_door_open = false;

    printf("Elevator door is closed\n");
}

/**
 * Print the status of each elevator
 */
void print_status(elevator_t elevators[]) {
    printf("\n");
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevator_t elevator = elevators[i];
        printf("Elevator %d:\n", i);
        printf("\tCurrent Floor: %d\n", elevator.curr_floor);
        printf("\tDestination Floor: %d\n", elevator.dest_floor);
        printf("\tDirection: %s\n", elevator.direction == DIR_UP ? "UP" : elevator.direction == DIR_DOWN ? "DOWN" : "STOP");
        printf("\tIs Busy: %s\n", elevator.is_busy ? "YES" : "NO");
        printf("\tIs Moving: %s\n", elevator.is_moving ? "YES" : "NO");
        printf("\tIs Door Open: %s\n", elevator.is_door_open ? "YES" : "NO");
    }
    printf("\n");
}