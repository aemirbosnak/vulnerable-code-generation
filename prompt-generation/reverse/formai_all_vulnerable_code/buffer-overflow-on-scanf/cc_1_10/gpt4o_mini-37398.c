//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define ELEVATOR_CAPACITY 5

typedef struct {
    int current_floor;
    int destination_floor;
    int passengers[ELEVATOR_CAPACITY];
    int passenger_count;
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0;
    elevator->destination_floor = -1;
    elevator->passenger_count = 0;
}

void call_elevator(Elevator *elevator, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor: %d\n", floor);
        return;
    }
    printf("Calling elevator to floor %d...\n", floor);
    elevator->destination_floor = floor;
}

void board_passenger(Elevator *elevator, int passenger_id) {
    if (elevator->passenger_count < ELEVATOR_CAPACITY) {
        elevator->passengers[elevator->passenger_count] = passenger_id;
        elevator->passenger_count++;
        printf("Passenger %d boarded. Total passengers: %d\n", passenger_id, elevator->passenger_count);
    } else {
        printf("Elevator is full! Passenger %d cannot board.\n", passenger_id);
    }
}

void disembark_passenger(Elevator *elevator, int passenger_id) {
    bool found = false;
    for (int i = 0; i < elevator->passenger_count; i++) {
        if (elevator->passengers[i] == passenger_id) {
            found = true;
            printf("Passenger %d has disembarked.\n", passenger_id);
            elevator->passengers[i] = elevator->passengers[elevator->passenger_count - 1]; // remove passenger
            elevator->passenger_count--;
            break;
        }
    }
    if (!found) {
        printf("Passenger %d not found in elevator!\n", passenger_id);
    }
}

void move_elevator(Elevator *elevator) {
    if (elevator->destination_floor == -1) {
        printf("Elevator is idle, no destination set.\n");
        return;
    }
    
    while (elevator->current_floor != elevator->destination_floor) {
        if (elevator->current_floor < elevator->destination_floor) {
            elevator->current_floor++;
        } else {
            elevator->current_floor--;
        }
        printf("Elevator moving to floor %d...\n", elevator->current_floor);
        sleep(1); // simulating elevator movement time
    }
    printf("Elevator arrived at floor %d.\n", elevator->current_floor);
    elevator->destination_floor = -1; // reset destination after arrival
}

void simulate_elevator_system() {
    Elevator elevator;
    initialize_elevator(&elevator);

    int commands;
    while (true) {
        printf("\n1. Call Elevator\n");
        printf("2. Board Passenger\n");
        printf("3. Disembark Passenger\n");
        printf("4. Move Elevator\n");
        printf("5. Exit Simulation\n");
        printf("Select a command: ");
        scanf("%d", &commands);

        switch (commands) {
            case 1: {
                int floor;
                printf("Enter floor to call elevator (0-%d): ", MAX_FLOORS - 1);
                scanf("%d", &floor);
                call_elevator(&elevator, floor);
                break;
            }
            case 2: {
                int passenger_id;
                printf("Enter passenger ID to board: ");
                scanf("%d", &passenger_id);
                board_passenger(&elevator, passenger_id);
                break;
            }
            case 3: {
                int passenger_id;
                printf("Enter passenger ID to disembark: ");
                scanf("%d", &passenger_id);
                disembark_passenger(&elevator, passenger_id);
                break;
            } 
            case 4: {
                move_elevator(&elevator);
                break;
            } 
            case 5: {
                printf("Exiting simulation...\n");
                exit(0);
            } 
            default: {
                printf("Invalid command!\n");
            }
        }
    }
}

int main() {
    simulate_elevator_system();
    return 0;
}