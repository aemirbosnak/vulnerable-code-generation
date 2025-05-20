//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define ELEVATOR_CAPACITY 5

typedef struct {
    int current_floor;
    int destination_floor;
    int passengers_count;
} Elevator;

void initializeElevator(Elevator *elevator) {
    elevator->current_floor = 0; // Starting on the ground floor
    elevator->destination_floor = -1; // No destination
    elevator->passengers_count = 0; // No passengers
}

void callElevator(Elevator *elevator, int requested_floor) {
    if (requested_floor < 0 || requested_floor >= MAX_FLOORS) {
        printf("Invalid floor!\n");
        return;
    }
    printf("Elevator called to floor %d.\n", requested_floor);
    elevator->destination_floor = requested_floor;
}

void moveElevator(Elevator *elevator) {
    if (elevator->destination_floor == -1) {
        printf("Please set a destination first.\n");
        return;
    }
    
    while (elevator->current_floor != elevator->destination_floor) {
        if (elevator->current_floor < elevator->destination_floor) {
            elevator->current_floor++;
            printf("Elevator moving up to floor %d...\n", elevator->current_floor);
        } else {
            elevator->current_floor--;
            printf("Elevator moving down to floor %d...\n", elevator->current_floor);
        }
        sleep(1); // Simulate the time taken to move
    }
    printf("Elevator has arrived at floor %d.\n", elevator->current_floor);
    elevator->destination_floor = -1; // Reset destination
}

void boardPassengers(Elevator *elevator, int new_passengers) {
    if (new_passengers + elevator->passengers_count > ELEVATOR_CAPACITY) {
        printf("Elevator full! Cannot board %d new passengers.\n", new_passengers);
    } else {
        elevator->passengers_count += new_passengers;
        printf("%d passengers boarded. Total now: %d.\n", new_passengers, elevator->passengers_count);
    }
}

void disembarkPassengers(Elevator *elevator) {
    printf("%d passengers disembarked at floor %d.\n", elevator->passengers_count, elevator->current_floor);
    elevator->passengers_count = 0; // All passengers leave the elevator
}

int main() {
    Elevator elevator;
    char command[10];
    int floor, passengers;

    initializeElevator(&elevator);
    srand(time(NULL)); // Seed for random generation

    while (1) {
        printf("\nCurrent floor: %d, Passengers: %d\n", elevator.current_floor, elevator.passengers_count);
        printf("Enter command (call/move/board/disembark/exit): ");
        scanf("%s", command);

        if (strcmp(command, "call") == 0) {
            printf("Request elevator to which floor (0-%d): ", MAX_FLOORS - 1);
            scanf("%d", &floor);
            callElevator(&elevator, floor);
        } else if (strcmp(command, "move") == 0) {
            moveElevator(&elevator);
        } else if (strcmp(command, "board") == 0) {
            passengers = rand() % (ELEVATOR_CAPACITY + 2); // Random number of passengers
            boardPassengers(&elevator, passengers);
        } else if (strcmp(command, "disembark") == 0) {
            disembarkPassengers(&elevator);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting simulation.\n");
            break;
        } else {
            printf("Unknown command! Please try again.\n");
        }
    }

    return 0;
}