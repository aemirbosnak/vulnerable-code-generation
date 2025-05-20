//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 5

typedef struct {
    int current_floor;
    int destination_floor;
    int passengers;
} Elevator;

void init_elevator(Elevator *elevator) {
    elevator->current_floor = 0; // start at ground floor
    elevator->destination_floor = -1; // no destination
    elevator->passengers = 0;
}

void call_elevator(Elevator *elevator, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor: %d\n", floor);
        return;
    }
    printf("Elevator called to floor %d\n", floor);
    elevator->destination_floor = floor;
}

void load_passenger(Elevator *elevator) {
    if (elevator->passengers < MAX_CAPACITY) {
        elevator->passengers++;
        printf("Passenger loaded. Current passengers: %d\n", elevator->passengers);
    } else {
        printf("Elevator is full. Cannot load more passengers.\n");
    }
}

void unload_passenger(Elevator *elevator) {
    if (elevator->passengers > 0) {
        elevator->passengers--;
        printf("Passenger unloaded. Current passengers: %d\n", elevator->passengers);
    } else {
        printf("No passengers to unload.\n");
    }
}

void move_elevator(Elevator *elevator) {
    while (elevator->current_floor != elevator->destination_floor && elevator->destination_floor != -1) {
        if (elevator->current_floor < elevator->destination_floor) {
            elevator->current_floor++;
        } else {
            elevator->current_floor--;
        }
        printf("Elevator is now at floor %d\n", elevator->current_floor);
        sleep(1);
    }
    if(elevator->current_floor == elevator->destination_floor) {
        printf("Elevator arrived at floor %d\n", elevator->destination_floor);
        elevator->destination_floor = -1; // Reset destination after arrival
    }
}

void print_status(Elevator *elevator) {
    printf("Current Floor: %d, Passengers: %d\n", elevator->current_floor, elevator->passengers);
}

int main() {
    Elevator elevator;
    init_elevator(&elevator);
    
    int operation;
    int floor;

    while(1) {
        printf("\nElevator Simulation Menu:\n");
        printf("1. Call Elevator\n");
        printf("2. Load Passenger\n");
        printf("3. Unload Passenger\n");
        printf("4. Move Elevator\n");
        printf("5. Print Status\n");
        printf("0. Exit\n");
        printf("Choose an operation: ");
        scanf("%d", &operation);

        switch(operation) {
            case 1:
                printf("Enter the floor to call the elevator (0-%d): ", MAX_FLOORS-1);
                scanf("%d", &floor);
                call_elevator(&elevator, floor);
                break;
            case 2:
                load_passenger(&elevator);
                break;
            case 3:
                unload_passenger(&elevator);
                break;
            case 4:
                move_elevator(&elevator);
                break;
            case 5:
                print_status(&elevator);
                break;
            case 0:
                printf("Exiting simulation. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid operation! Please try again.\n");
        }
    }

    return 0;
}