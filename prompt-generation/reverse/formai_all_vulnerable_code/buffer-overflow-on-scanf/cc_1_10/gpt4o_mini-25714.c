//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 5

typedef struct {
    int current_floor;
    int destination_floor;
    int passengers[MAX_CAPACITY];
    int passenger_count;
    bool doors_open;
} Elevator;

void initialize_elevator(Elevator* elevator) {
    elevator->current_floor = 0;
    elevator->destination_floor = -1; // No destination
    elevator->passenger_count = 0;
    elevator->doors_open = true;
}

void open_doors(Elevator* elevator) {
    elevator->doors_open = true;
    printf("Doors are now open at floor %d.\n", elevator->current_floor);
}

void close_doors(Elevator* elevator) {
    elevator->doors_open = false;
    printf("Doors are now closed.\n");
}

void pick_up_passenger(Elevator* elevator, int passenger_id, int destination_floor) {
    if (elevator->passenger_count < MAX_CAPACITY) {
        elevator->passengers[elevator->passenger_count++] = passenger_id;
        elevator->destination_floor = destination_floor;
        printf("Passenger %d picked up. Destination: Floor %d\n", passenger_id, destination_floor);
    } else {
        printf("Elevator is full! Passenger %d cannot board.\n", passenger_id);
    }
}

void drop_off_passenger(Elevator* elevator, int passenger_id) {
    printf("Passenger %d has exited at floor %d.\n", passenger_id, elevator->current_floor);
}

void move_elevator(Elevator* elevator) {
    close_doors(elevator);
    while (elevator->current_floor != elevator->destination_floor) {
        if (elevator->current_floor < elevator->destination_floor) {
            elevator->current_floor++;
            printf("Moving up to floor %d...\n", elevator->current_floor);
        } else {
            elevator->current_floor--;
            printf("Moving down to floor %d...\n", elevator->current_floor);
        }
        sleep(1); // Simulate time taken to move between floors
    }
    open_doors(elevator);
    // Drop off passengers here
    for (int i = 0; i < elevator->passenger_count; i++) {
        int passenger_id = elevator->passengers[i];
        drop_off_passenger(elevator, passenger_id);
    }
    elevator->passenger_count = 0; // reset passengers
    elevator->destination_floor = -1; // reset destination
}

bool is_valid_floor(int floor) {
    return floor >= 0 && floor < MAX_FLOORS;
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);
    
    while (true) {
        int action;
        printf("\nElevator Simulation\n");
        printf("1. Pick up passenger\n");
        printf("2. Move elevator\n");
        printf("3. Exit\n");
        printf("Select action: ");
        scanf("%d", &action);

        if (action == 1) {
            int passenger_id, destination_floor;
            printf("Enter passenger ID: ");
            scanf("%d", &passenger_id);
            printf("Enter destination floor: ");
            scanf("%d", &destination_floor);
            
            if (is_valid_floor(destination_floor)) {
                pick_up_passenger(&elevator, passenger_id, destination_floor);
            } else {
                printf("Invalid floor number! Please enter a number between 0 and %d.\n", MAX_FLOORS - 1);
            }
        } else if (action == 2) {
            if (elevator.passenger_count > 0 && elevator.destination_floor != -1) {
                move_elevator(&elevator);
            } else {
                printf("No passengers to move.\n");
            }
        } else if (action == 3) {
            printf("Exiting simulation.\n");
            break;
        } else {
            printf("Invalid action! Please try again.\n");
        }
    }
    return 0;
}