//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct Elevator {
    int current_floor;
    int target_floor;
} Elevator;

void display_status(Elevator* elevator) {
    system("clear"); // Clear the screen
    printf("===================================\n");
    printf("         Elevator Simulation        \n");
    printf("===================================\n");
    printf("Current Floor: %d\n", elevator->current_floor);
    printf("Target Floor: %d\n", elevator->target_floor);
    printf("===================================\n");
}

void move_elevator(Elevator* elevator) {
    while (elevator->current_floor != elevator->target_floor) {
        if (elevator->current_floor < elevator->target_floor) {
            elevator->current_floor++;
        } else {
            elevator->current_floor--;
        }
        display_status(elevator);
        usleep(1000000); // Simulate the time taken to move
    }
    printf("Ding! You've reached floor %d.\n", elevator->current_floor);
}

void request_floor(Elevator* elevator) {
    int floor;
    printf("Enter the target floor (0 to %d): ", MAX_FLOORS - 1);
    scanf("%d", &floor);
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor. Please try again.\n");
        request_floor(elevator);
    } else {
        elevator->target_floor = floor;
    }
}

int main() {
    Elevator elevator = {0, 0}; // Initialize elevator at ground floor
    int option;

    printf("Welcome to the Shape-Shifting Elevator!\n");

    while (1) {
        display_status(&elevator);
        printf("1. Request Floor\n");
        printf("2. Move Elevator\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                request_floor(&elevator);
                break;

            case 2:
                if (elevator.target_floor == elevator.current_floor) {
                    printf("You are already at the target floor.\n");
                } else {
                    move_elevator(&elevator);
                }
                break;

            case 3:
                printf("Exiting the elevator simulation. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }
    }

    return 0;
}