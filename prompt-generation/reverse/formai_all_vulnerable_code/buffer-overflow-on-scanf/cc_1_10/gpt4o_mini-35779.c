//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 5

typedef struct {
    int current_floor;
    int capacity;
    int passenger_count;
    bool doors_open;
} Elevator;

void initialize_elevator(Elevator* elevator) {
    elevator->current_floor = 0; // Start at ground floor
    elevator->capacity = MAX_CAPACITY;
    elevator->passenger_count = 0;
    elevator->doors_open = false;
}

void call_elevator(Elevator* elevator, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor number!\n");
        return;
    }
    printf("Elevator called to floor %d.\n", floor);
    elevator->current_floor = floor;
    elevator->doors_open = true;
    printf("Elevator doors are now open at floor %d.\n", floor);
}

void board_passenger(Elevator* elevator) {
    if (elevator->doors_open) {
        if (elevator->passenger_count < elevator->capacity) {
            elevator->passenger_count++;
            printf("A passenger has boarded. Current passenger count: %d\n", elevator->passenger_count);
        } else {
            printf("Elevator is full. Can't board more passengers.\n");
        }
    } else {
        printf("Elevator doors are closed. Passengers can't board.\n");
    }
}

void alight_passenger(Elevator* elevator) {
    if (elevator->doors_open) {
        if (elevator->passenger_count > 0) {
            elevator->passenger_count--;
            printf("A passenger has alighted. Current passenger count: %d\n", elevator->passenger_count);
        } else {
            printf("No passengers to alight.\n");
        }
    } else {
        printf("Elevator doors are closed. Passengers can't alight.\n");
    }
}

void operate_elevator(Elevator* elevator, int destination_floor) {
    if (!elevator->doors_open) {
        printf("Elevator doors must be open to operate!\n");
        return;
    }
    if (destination_floor < 0 || destination_floor >= MAX_FLOORS) {
        printf("Invalid destination floor!\n");
        return;
    }
    elevator->doors_open = false; // Close the doors before moving
    printf("Moving from floor %d to floor %d...\n", elevator->current_floor, destination_floor);
    
    // Simulate moving
    sleep(2); 
    elevator->current_floor = destination_floor;
    
    // Doors open upon reaching the destination
    printf("Arrived at floor %d. Elevator doors are now open.\n", elevator->current_floor);
    elevator->doors_open = true;
}

int main() {
    Elevator elevator;
    int action, floor;

    initialize_elevator(&elevator);
    
    while (true) {
        printf("\nElevator Simulation Menu:\n");
        printf("1. Call Elevator\n");
        printf("2. Board Passenger\n");
        printf("3. Alight Passenger\n");
        printf("4. Operate Elevator\n");
        printf("5. Exit\n");
        printf("Choose an action (1-5): ");
        scanf("%d", &action);

        switch (action) {
            case 1:
                printf("Enter floor (0-%d): ", MAX_FLOORS - 1);
                scanf("%d", &floor);
                call_elevator(&elevator, floor);
                break;
            case 2:
                board_passenger(&elevator);
                break;
            case 3:
                alight_passenger(&elevator);
                break;
            case 4:
                if (elevator.passenger_count == 0) {
                    printf("No passengers in the elevator!\n");
                    break;
                }
                printf("Enter destination floor (0-%d): ", MAX_FLOORS - 1);
                scanf("%d", &floor);
                operate_elevator(&elevator, floor);
                break;
            case 5:
                printf("Exiting the elevator simulation. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid action.\n");
        }
    }

    return 0;
}