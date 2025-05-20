//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define ELEVATOR_CAPACITY 5

typedef struct {
    int current_floor;
    int occupied;
    int destination_floors[ELEVATOR_CAPACITY];
} Elevator;

void initialize_elevator(Elevator* e) {
    e->current_floor = 0;  // Start at ground floor
    e->occupied = 0;
    for (int i = 0; i < ELEVATOR_CAPACITY; i++) {
        e->destination_floors[i] = -1; // No destination set
    }
}

void call_elevator(Elevator* e, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor requested: %d\n", floor);
        return;
    }
    printf("Elevator is called to floor %d\n", floor);
    e->current_floor = floor; // Move to the floor where the elevator is called
}

void enter_elevator(Elevator* e, int destination) {
    if (e->occupied >= ELEVATOR_CAPACITY) {
        printf("Elevator is full! Unable to enter.\n");
        return;
    }
    if (destination < 0 || destination >= MAX_FLOORS) {
        printf("Invalid destination floor: %d\n", destination);
        return;
    }
    e->destination_floors[e->occupied++] = destination;
    printf("Entered elevator - Current: %d, Going to: %d\n", e->current_floor, destination);
}

void move_elevator(Elevator* e) {
    for (int i = 0; i < e->occupied; i++) {
        if (e->destination_floors[i] != -1) {
            while (e->current_floor != e->destination_floors[i]) {
                if (e->current_floor < e->destination_floors[i]) {
                    e->current_floor++;
                } else {
                    e->current_floor--;
                }
                printf("Elevator moving... Current Floor: %d\n", e->current_floor);
                sleep(1);
            }
            printf("Arrived at floor: %d\n", e->current_floor);
            e->destination_floors[i] = -1; // Reset the destination
            e->occupied--; // Decrease occupancy since person exits
            printf("Person exited elevator. Occupancy is now: %d\n", e->occupied);
        }
    }
}

void display_elevator_status(Elevator* e) {
    printf("Current floor: %d\n", e->current_floor);
    printf("Elevator Occupancy: %d/%d\n", e->occupied, ELEVATOR_CAPACITY);
    printf("Destinations: ");
    for (int i = 0; i < ELEVATOR_CAPACITY; i++) {
        if (e->destination_floors[i] != -1) {
            printf("%d ", e->destination_floors[i]);
        }
    }
    printf("\n");
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);

    // Simulation loop
    while (1) {
        int action, floor;
        printf("\nChoose action:\n");
        printf("1. Call elevator to a floor\n");
        printf("2. Enter elevator\n");
        printf("3. Move elevator\n");
        printf("4. Display elevator status\n");
        printf("5. Exit simulation\n");
        printf("Your choice: ");
        scanf("%d", &action);

        switch (action) {
            case 1:
                printf("Enter floor to call elevator (0-%d): ", MAX_FLOORS - 1);
                scanf("%d", &floor);
                call_elevator(&elevator, floor);
                break;
            case 2:
                printf("Enter destination floor (0-%d): ", MAX_FLOORS - 1);
                scanf("%d", &floor);
                enter_elevator(&elevator, floor);
                break;
            case 3:
                move_elevator(&elevator);
                break;
            case 4:
                display_elevator_status(&elevator);
                break;
            case 5:
                printf("Exiting simulation...\n");
                exit(0);
            default:
                printf("Invalid action!\n");
        }
    }

    return 0;
}