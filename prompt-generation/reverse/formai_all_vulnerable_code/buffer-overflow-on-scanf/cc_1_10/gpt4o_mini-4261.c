//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: imaginative
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

void print_elevator_status(Elevator* elevator) {
    printf("Elevator is currently on floor %d with %d passengers.\n",
           elevator->current_floor, elevator->passengers);
}

void request_elevator(Elevator* elevator, int destination) {
    if (elevator->passengers < MAX_CAPACITY) {
        elevator->destination_floor = destination;
        printf("Elevator requested to floor %d.\n", elevator->destination_floor);
    } else {
        printf("Elevator is at full capacity! Please wait.\n");
    }
}

void load_passenger(Elevator* elevator) {
    if (elevator->passengers < MAX_CAPACITY) {
        elevator->passengers++;
        printf("A passenger has entered the elevator. Total passengers: %d\n", elevator->passengers);
    } else {
        printf("Can't load more passengers, elevator is full.\n");
    }
}

void unload_passenger(Elevator* elevator) {
    if (elevator->passengers > 0) {
        elevator->passengers--;
        printf("A passenger has exited the elevator. Remaining passengers: %d\n", elevator->passengers);
    } else {
        printf("No passengers to unload.\n");
    }
}

void move_elevator(Elevator* elevator) {
    while (elevator->current_floor != elevator->destination_floor) {
        if (elevator->current_floor < elevator->destination_floor) {
            elevator->current_floor++;
        } else {
            elevator->current_floor--;
        }
        print_elevator_status(elevator);
        sleep(1);  // Simulate travel time
    }
    printf("Elevator has arrived at floor %d.\n", elevator->current_floor);
}

int main() {
    Elevator elevator = {0, 0, 0}; // Start at ground floor with no passengers

    printf("Welcome to the Magical Elevator!\n");
    
    int choice;
    
    while (1) {
        printf("\nElevator Control Panel:\n");
        printf("1. Request Elevator to a Floor (1 - %d)\n", MAX_FLOORS);
        printf("2. Load Passenger\n");
        printf("3. Unload Passenger\n");
        printf("4. Move Elevator\n");
        printf("5. Check Elevator Status\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                int floor;
                printf("Enter the floor to request (1 - %d): ", MAX_FLOORS);
                scanf("%d", &floor);
                if (floor >= 1 && floor <= MAX_FLOORS) {
                    request_elevator(&elevator, floor);
                } else {
                    printf("Invalid floor number. Please enter a number between 1 and %d.\n", MAX_FLOORS);
                }
                break;
            }
            case 2:
                load_passenger(&elevator);
                break;
            case 3:
                unload_passenger(&elevator);
                break;
            case 4:
                move_elevator(&elevator);
                elevator.destination_floor = 0; // Reset destination after reaching
                break;
            case 5:
                print_elevator_status(&elevator);
                break;
            case 6:
                printf("Exiting the elevator simulation. Have a nice day!\n");
                exit(0);
            default:
                printf("Invalid option! Please choose a valid action.\n");
        }
    }

    return 0;
}