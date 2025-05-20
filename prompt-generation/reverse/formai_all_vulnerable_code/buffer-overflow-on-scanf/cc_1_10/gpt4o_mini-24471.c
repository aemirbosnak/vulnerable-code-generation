//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define ELEVATOR_CAPACITY 2

typedef struct {
    int current_floor;
    int direction; // 1 for up, -1 for down, 0 for stationary
    int passengers;
} Elevator;

Elevator elevator;

void initialize_elevator() {
    elevator.current_floor = 0;
    elevator.direction = 0;
    elevator.passengers = 0;
}

void print_elevator_status() {
    printf("\nElevator Status:\n");
    printf("Current Floor: %d\n", elevator.current_floor);
    printf("Direction: %s\n", elevator.direction == 1 ? "Up" : (elevator.direction == -1 ? "Down" : "Stationary"));
    printf("Passengers: %d\n", elevator.passengers);
}

void move_elevator() {
    if (elevator.direction == 1) {
        if (elevator.current_floor < MAX_FLOORS - 1) {
            elevator.current_floor++;
        }
    } else if (elevator.direction == -1) {
        if (elevator.current_floor > 0) {
            elevator.current_floor--;
        }
    }
}

void request_elevator(int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor request!\n");
        return;
    }

    // Make the elevator move towards the requested floor
    if (elevator.current_floor < floor) {
        elevator.direction = 1;
    } else if (elevator.current_floor > floor) {
        elevator.direction = -1;
    } else {
        elevator.direction = 0;
    }
}

void load_passenger() {
    if (elevator.passengers < ELEVATOR_CAPACITY) {
        elevator.passengers++;
        printf("Passenger entered. Total Passengers: %d\n", elevator.passengers);
    } else {
        printf("Elevator is full! Cannot load more passengers.\n");
    }
}

void unload_passenger() {
    if (elevator.passengers > 0) {
        elevator.passengers--;
        printf("Passenger exited. Total Passengers: %d\n", elevator.passengers);
    } else {
        printf("No passengers to unload.\n");
    }
}

void operate_elevator() {
    int destination_floor;

    while (1) {
        print_elevator_status();
        move_elevator();
        
        if (elevator.direction != 0) {
            printf("Elevator moving...\n");
            sleep(1);
        } else {
            printf("Elevator is stationary.\n");
        }

        // Check if an update is needed
        if (elevator.direction != 0) {
            printf("You have reached floor %d!\n", elevator.current_floor);
            unload_passenger();
            if (elevator.passengers < ELEVATOR_CAPACITY) {
                printf("Do you want to load a passenger? (1 for Yes, 0 for No): ");
                int choice;
                scanf("%d", &choice);
                if (choice == 1) {
                    load_passenger();
                }
            }

            printf("Where to next? (Enter floor 0-%d, or -1 to exit): ", MAX_FLOORS-1);
            scanf("%d", &destination_floor);
            if (destination_floor == -1) break;
            request_elevator(destination_floor);
        }
    }
}

int main() {
    initialize_elevator();
    
    printf("Welcome to the Artistic Elevator Simulation!\n");
    printf("Experience the beauty of vertical transport!\n");
    
    int initial_request;
    printf("Please request your floor (0-%d): ", MAX_FLOORS-1);
    scanf("%d", &initial_request);
    
    request_elevator(initial_request);
    operate_elevator();

    printf("Thank you for using the Artistic Elevator!\n");
    return 0;
}