//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep function
#include <stdbool.h>

#define MAX_FLOORS 10

typedef struct {
    int current_floor;
    bool doors_open;
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0; // Start at ground floor
    elevator->doors_open = false;
}

void open_doors() {
    printf("Opening doors...\n");
    sleep(2); // Simulate time taken to open doors
}

void close_doors() {
    printf("Closing doors...\n");
    sleep(2); // Simulate time taken to close doors
}

void move_elevator(Elevator *elevator, int target_floor) {
    if(target_floor < 0 || target_floor >= MAX_FLOORS) {
        printf("Invalid floor selection!\n");
        return;
    }

    printf("Moving from floor %d to floor %d...\n", elevator->current_floor, target_floor);
    if (elevator->current_floor < target_floor) {
        // Ascend
        while (elevator->current_floor < target_floor) {
            sleep(1); // Simulate the time taken to move to the next floor
            elevator->current_floor++;
            printf("Elevator at floor %d...\n", elevator->current_floor);
        }
    } else if (elevator->current_floor > target_floor) {
        // Descend
        while (elevator->current_floor > target_floor) {
            sleep(1); // Simulate the time taken to move to the next floor
            elevator->current_floor--;
            printf("Elevator at floor %d...\n", elevator->current_floor);
        }
    }
}

void request_floor(Elevator *elevator) {
    int target_floor = -1;
    while (target_floor < 0 || target_floor >= MAX_FLOORS) {
        printf("Please enter the floor number (0-%d): ", MAX_FLOORS - 1);
        scanf("%d", &target_floor);
        if (target_floor < 0 || target_floor >= MAX_FLOORS) {
            printf("Invalid floor. Try again.\n");
        }
    }
    
    close_doors();
    move_elevator(elevator, target_floor);
    open_doors();
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);
    
    printf("Welcome to the Elevator Simulation!\n");

    while (true) {
        request_floor(&elevator);
        char continue_choice;
        printf("Do you want to request another floor? (y/n): ");
        scanf(" %c", &continue_choice); // Space before %c to ignore previous new line
        if (continue_choice == 'n' || continue_choice == 'N') {
            printf("Exiting the elevator simulation. Thank you!\n");
            break;
        }
    }

    return 0;
}