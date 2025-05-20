//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // for sleep function
#include <stdbool.h>

#define MAX_FLOORS 10
#define ELEVATOR_DELAY 2

typedef struct {
    int current_floor;
    bool going_up;
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0;  // Start at Ground floor
    elevator->going_up = true;
}

void display_floor(int floor) {
    printf("\n\n=== Welcome to the Fantastical Elevator ===\n");
    printf("   You are currently at Floor %d\n", floor);
    printf("==========================================\n");
}

void move_elevator(Elevator *elevator, int target_floor) {
    while (elevator->current_floor != target_floor) {
        display_floor(elevator->current_floor);
        if (elevator->current_floor < target_floor) {
            elevator->going_up = true;
            elevator->current_floor++;
            printf("Elevator is going up...\n");
        }
        else {
            elevator->going_up = false;
            elevator->current_floor--;
            printf("Elevator is going down...\n");
        }
        sleep(ELEVATOR_DELAY);  // Simulate time taken to move
    }
    display_floor(elevator->current_floor);
    printf("Elevator has arrived at Floor %d. Welcome!\n", elevator->current_floor);
}

int main() {
    int target_floor;
    Elevator elevator;
    
    initialize_elevator(&elevator);
    
    while (true) {
        printf("Which floor would you like to go to? (0 to %d) or -1 to exit: ", MAX_FLOORS - 1);
        scanf("%d", &target_floor);

        if (target_floor == -1) {
            printf("Thank you for using the Fantastical Elevator. Have a great day!\n");
            break;
        }

        if (target_floor < 0 || target_floor >= MAX_FLOORS) {
            printf("Invalid floor! Please select a floor between 0 and %d.\n", MAX_FLOORS - 1);
            continue;
        }

        move_elevator(&elevator, target_floor);
    }
    
    return 0;
}