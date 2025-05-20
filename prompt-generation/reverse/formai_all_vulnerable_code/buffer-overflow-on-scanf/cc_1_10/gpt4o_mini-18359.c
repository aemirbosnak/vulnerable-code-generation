//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 5

typedef struct {
    int current_floor;
    int destination_floor;
    int passengers;
} Elevator;

void init_elevator(Elevator* elevator) {
    elevator->current_floor = 0;
    elevator->destination_floor = -1;
    elevator->passengers = 0;
}

void display_status(Elevator* elevator) {
    printf("Elevator is currently on floor: %d\n", elevator->current_floor);
    printf("Destination: %s\n", elevator->destination_floor == -1 ? "None" : "Floor");
    printf("Passengers: %d\n\n", elevator->passengers);
}

bool add_passenger(Elevator* elevator) {
    if (elevator->passengers < MAX_CAPACITY) {
        elevator->passengers++;
        printf("A passenger entered the elevator. Total passengers: %d\n", elevator->passengers);
        return true;
    } else {
        printf("The elevator is at full capacity!\n");
        return false;
    }
}

bool remove_passenger(Elevator* elevator) {
    if (elevator->passengers > 0) {
        elevator->passengers--;
        printf("A passenger exited the elevator. Total passengers: %d\n", elevator->passengers);
        return true;
    } else {
        printf("No passengers to remove!\n");
        return false;
    }
}

void move_elevator(Elevator* elevator) {
    if (elevator->destination_floor == -1) {
        printf("No destination set. Cannot move elevator.\n");
        return;
    }
    
    printf("Moving the elevator...\n");
    
    while (elevator->current_floor != elevator->destination_floor) {
        if (elevator->current_floor < elevator->destination_floor) {
            elevator->current_floor++;
        } else {
            elevator->current_floor--;
        }

        printf("Elevator is now at floor: %d\n", elevator->current_floor);
        sleep(1);
    }
    
    printf("Arrived at floor %d!\n", elevator->current_floor);
    elevator->destination_floor = -1; // Reset after arrival
}

int main() {
    Elevator elevator;
    int choice, floor;

    init_elevator(&elevator);
    
    printf("********** Elevator Simulation **********\n");
    
    while (true) {
        display_status(&elevator);
        
        printf("1. Set Destination\n");
        printf("2. Add Passenger\n");
        printf("3. Remove Passenger\n");
        printf("4. Move Elevator\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter destination floor (0-%d): ", MAX_FLOORS - 1);
                scanf("%d", &floor);
                if (floor < 0 || floor >= MAX_FLOORS) {
                    printf("Invalid floor!\n");
                } else {
                    elevator.destination_floor = floor;
                    printf("Destination set to floor %d.\n", elevator.destination_floor);
                }
                break;
                
            case 2:
                add_passenger(&elevator);
                break;
                
            case 3:
                remove_passenger(&elevator);
                break;
                
            case 4:
                move_elevator(&elevator);
                break;

            case 5:
                printf("Exiting the elevator simulation. Goodbye!\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}