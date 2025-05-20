//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define MAX_PEOPLE 5

typedef struct {
    int current_floor;
    int target_floor;
    int people_count;
} Elevator;

void callElevator(Elevator *elevator, int requested_floor) {
    if (requested_floor < 1 || requested_floor > MAX_FLOORS) {
        printf("Invalid floor!\n");
    } else {
        elevator->target_floor = requested_floor;
        printf("Elevator called to floor %d.\n", requested_floor);
    }
}

void moveElevator(Elevator *elevator) {
    while (elevator->current_floor != elevator->target_floor) {
        if (elevator->current_floor < elevator->target_floor) {
            elevator->current_floor++;
        } else {
            elevator->current_floor--;
        }
        printf("Elevator on floor %d...\n", elevator->current_floor);
        sleep(1); // Simulates the time taken for the elevator to move
    }
    printf("Elevator arrived at floor %d.\n", elevator->current_floor);
}

void boardElevator(Elevator *elevator) {
    if (elevator->people_count < MAX_PEOPLE) {
        elevator->people_count++;
        printf("A person boarded the elevator. Total people: %d\n", elevator->people_count);
    } else {
        printf("Elevator is full! No more boarding!\n");
    }
}

void exitElevator(Elevator *elevator) {
    if (elevator->people_count > 0) {
        elevator->people_count--;
        printf("A person exited the elevator. Total people: %d\n", elevator->people_count);
    } else {
        printf("No one is in the elevator to exit!\n");
    }
}

void displayStatus(Elevator *elevator) {
    printf("Elevator current status:\n");
    printf("Current Floor: %d\n", elevator->current_floor);
    printf("Target Floor: %d\n", elevator->target_floor);
    printf("People inside: %d\n", elevator->people_count);
}

int main() {
    Elevator elevator = {1, 1, 0}; // starts on 1st floor
    int command, floor;

    printf("Welcome to the Retro Elevator Simulation!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Call Elevator to a floor\n");
        printf("2. Move Elevator\n");
        printf("3. Board Elevator\n");
        printf("4. Exit Elevator\n");
        printf("5. Display Status\n");
        printf("0. Exit Simulation\n");
        printf("Enter your choice: ");
        scanf("%d", &command);

        switch (command) {
            case 1:
                printf("Enter the floor to call the elevator (1-%d): ", MAX_FLOORS);
                scanf("%d", &floor);
                callElevator(&elevator, floor);
                break;
            case 2:
                moveElevator(&elevator);
                break;
            case 3:
                boardElevator(&elevator);
                break;
            case 4:
                exitElevator(&elevator);
                break;
            case 5:
                displayStatus(&elevator);
                break;
            case 0:
                printf("Exiting Simulation. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid command! Please try again.\n");
        }
    }
    return 0;
}