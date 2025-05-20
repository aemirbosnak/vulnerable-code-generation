//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: all-encompassing
#include <stdio.h>

#define NUM_FLOORS 10
#define ELEVATOR_CAPACITY 10

void display_current_status(int current_floor, int destination_floor, int num_people) {
    printf("Elevator is currently at floor %d and going to floor %d. Number of people in the elevator: %d.\n", current_floor, destination_floor, num_people);
}

void move_to_floor(int current_floor, int destination_floor) {
    if (current_floor < destination_floor) {
        printf("Going up...\n");
        while (current_floor < destination_floor) {
            printf("Floor %d...\n", ++current_floor);
        }
    } else if (current_floor > destination_floor) {
        printf("Going down...\n");
        while (current_floor > destination_floor) {
            printf("Floor %d...\n", --current_floor);
        }
    }
}

int main() {
    int current_floor = 1;
    int destination_floor = 1;
    int num_people = 0;
    int request_floor = -1;

    printf("Welcome to the Elevator Simulator!\n");

    while (1) {
        printf("Enter the floor number you are at (1-10): ");
        fflush(stdout);
        scanf("%d", &current_floor);

        if (current_floor < 1 || current_floor > NUM_FLOORS) {
            printf("Invalid floor number\n");
            continue;
        }

        printf("Enter the floor number you want to go to (1-10): ");
        fflush(stdout);
        scanf("%d", &destination_floor);

        if (destination_floor < 1 || destination_floor > NUM_FLOORS) {
            printf("Invalid floor number\n");
            continue;
        }

        if (current_floor == destination_floor) {
            printf("You are already at floor %d.\n", current_floor);
            continue;
        }

        printf("Enter the number of people in the elevator (0-%d): ", ELEVATOR_CAPACITY);
        fflush(stdout);
        scanf("%d", &num_people);

        if (num_people < 0 || num_people > ELEVATOR_CAPACITY) {
            printf("Invalid number of people\n");
            continue;
        }

        display_current_status(current_floor, destination_floor, num_people);

        printf("Enter the floor number where someone wants to get in (-1 if nobody): ");
        fflush(stdout);
        scanf("%d", &request_floor);

        if (request_floor < -1 || request_floor > NUM_FLOORS || request_floor == current_floor) {
            printf("Invalid floor number\n");
            continue;
        }

        if (request_floor != -1 && num_people == ELEVATOR_CAPACITY) {
            printf("Elevator is full\n");
            continue;
        }

        if (request_floor != -1 && ((destination_floor > current_floor && request_floor > destination_floor) 
                                    || (destination_floor < current_floor && request_floor < destination_floor))) {
            printf("Elevator cannot stop at floor %d because it is on the opposite direction\n", request_floor);
            continue;
        }

        if (request_floor != -1) {
            printf("Someone entered the elevator at floor %d\n", request_floor);
            num_people++;
        }

        move_to_floor(current_floor, destination_floor);

        if (request_floor != -1 && current_floor == request_floor) {
            printf("Someone got off the elevator at floor %d\n", current_floor);
            num_people--;
        }

        display_current_status(current_floor, destination_floor, num_people);

        if (num_people == 0) {
            printf("Elevator is empty. Returning to floor 1.\n");
            current_floor = destination_floor = 1;
        }
    }

    return 0;
}