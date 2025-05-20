//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEVATOR_TOTAL_FLOORS 10 // Total floors in the building
#define ELEVATOR_MAX_CAPACITY 8 // Maximum capacity of the elevator

typedef enum {
    IDLE, // The elevator is not moving
    UP, // The elevator is moving up
    DOWN // The elevator is moving down
} Elevator_Status;

typedef struct {
    int current_floor;
    int destination_floor;
    Elevator_Status status;
    int capacity;
} Elevator;

void activate_elevator(Elevator* elevator) {
    // Generate a random destination floor
    srand(time(NULL));
    int destination = rand() % ELEVATOR_TOTAL_FLOORS + 1;

    // Check if the destination is above or below the current floor
    if(destination > elevator->current_floor)
        elevator->status = UP;
    else if(destination < elevator->current_floor)
        elevator->status = DOWN;

    // Update the elevator destination floor
    elevator->destination_floor = destination;

    printf("Elevator activated. Destination floor: %d\n\n", destination);
}

void move_elevator(Elevator* elevator) {
    switch(elevator->status) {
        case UP:
            elevator->current_floor++;
            printf("Elevator is now on floor %d\n", elevator->current_floor);
            break;
        case DOWN:
            elevator->current_floor--;
            printf("Elevator is now on floor %d\n", elevator->current_floor);
            break;
        default:
            break;
    }
}

void simulate_elevator() {
    // Initialize the elevator
    Elevator elevator = {1, 1, IDLE, 0};

    printf("Welcome to the Elevator Simulation.\n");

    // Loop until user exits
    while(1) {
        // Display the current status of the elevator
        printf("Current Status:\n");
        printf("---------------\n");
        printf("Current Floor: %d\n", elevator.current_floor);
        printf("Dest. Floor: %d\n", elevator.destination_floor);
        printf("Capacity: %d\n", elevator.capacity);
        switch(elevator.status) {
            case IDLE:
                printf("Status: Idle\n");
                break;
            case UP:
                printf("Status: Moving Up\n");
                break;
            case DOWN:
                printf("Status: Moving Down\n");
                break;
            default:
                break;
        }
        printf("\n");

        // Ask the user for input
        printf("What would you like to do?\n");
        printf("1. Activate Elevator\n");
        printf("2. Move Elevator\n");
        printf("3. Exit\n");
        int option;
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                // Check if elevator is already active
                if(elevator.destination_floor != elevator.current_floor) {
                    printf("Elevator is already active.\n\n");
                    break;
                }
                
                // Activate the elevator
                activate_elevator(&elevator);
                break;
            case 2:
                // Check if elevator is already at destination
                if(elevator.current_floor == elevator.destination_floor) {
                    printf("Elevator is already at destination floor.\n\n");
                    break;
                }

                // Move the elevator
                move_elevator(&elevator);

                // Check if elevator has reached the destination floor
                if(elevator.current_floor == elevator.destination_floor)
                    printf("Elevator has reached the destination floor.\n\n");
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n\n");
                break;
        }
    }
}

int main() {
    simulate_elevator();
    return 0;
}