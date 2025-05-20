//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: all-encompassing
#include <stdio.h>

// Constants
#define MAX_FLOORS 10
#define MAX_CAPACITY 10

// Enumerations
typedef enum {
    IDLE,
    MOVING_UP,
    MOVING_DOWN
} ElevatorState;

// Structures
typedef struct {
    int currentFloor;       // Current floor of the elevator
    int targetFloor;        // Target floor of the elevator
    int capacity;           // Current capacity of the elevator
    int passengers[MAX_CAPACITY];  // Array of passengers in the elevator
    ElevatorState state;    // Current state of the elevator
} Elevator;

// Function prototypes
void printElevatorStatus(Elevator e);
void moveElevatorUp(Elevator *e);
void moveElevatorDown(Elevator *e);
void addPassenger(Elevator *e, int floor);
void removePassenger(Elevator *e, int floor);

int main() {
    Elevator e = {0, 0, 0, {0}, IDLE};   // Create new elevator object
    int input;

    printf("Elevator Simulation\n\n");
    printf("Select an option:\n");

    do {
        printf("\n1. Send elevator to floor\n");
        printf("2. Add passenger to elevator\n");
        printf("3. Remove passenger from elevator\n");
        printf("4. Quit\n\n");
        printf("Enter option: ");
        scanf("%d", &input);

        switch (input) {
            case 1:
                printf("\nEnter floor: ");
                scanf("%d", &e.targetFloor);

                if (e.currentFloor < e.targetFloor) {
                    e.state = MOVING_UP;
                } else if (e.currentFloor > e.targetFloor) {
                    e.state = MOVING_DOWN;
                } else {
                    e.state = IDLE;
                }

                while (e.currentFloor != e.targetFloor) {
                    printElevatorStatus(e);

                    if (e.state == MOVING_UP) {
                        moveElevatorUp(&e);
                    } else if (e.state == MOVING_DOWN) {
                        moveElevatorDown(&e);
                    }
                }

                e.state = IDLE;
                break;

            case 2:
                printf("\nEnter floor: ");
                scanf("%d", &input);

                if (e.state == IDLE || e.currentFloor == input) {
                    addPassenger(&e, input);
                } else {
                    printf("\nCannot add passenger while elevator is in motion.\n");
                }

                break;

            case 3:
                printf("\nEnter floor: ");
                scanf("%d", &input);

                if (e.state == IDLE || e.currentFloor == input) {
                    removePassenger(&e, input);
                } else {
                    printf("\nCannot remove passenger while elevator is in motion.\n");
                }

                break;

            case 4:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    } while (input != 4);

    return 0;
}

void printElevatorStatus(Elevator e) {
    printf("\n--------------------------------------------------\n");
    printf("Current Floor: %d\n", e.currentFloor);
    printf("Target Floor: %d\n", e.targetFloor);
    printf("Capacity: %d/%d\n", e.capacity, MAX_CAPACITY);

    printf("Passengers: ");
    for (int i = 0; i < e.capacity; i++) {
        printf("%d ", e.passengers[i]);
    }
    printf("\n");

    printf("State: ");
    switch (e.state) {
        case IDLE:
            printf("IDLE");
            break;

        case MOVING_UP:
            printf("MOVING UP");
            break;

        case MOVING_DOWN:
            printf("MOVING DOWN");
            break;
    }
    printf("\n");
}

void moveElevatorUp(Elevator *e) {
    e->currentFloor++;
}

void moveElevatorDown(Elevator *e) {
    e->currentFloor--;
}

void addPassenger(Elevator *e, int floor) {
    if (e->capacity < MAX_CAPACITY) {
        e->passengers[e->capacity] = floor;
        e->capacity++;
    } else {
        printf("\nElevator is at full capacity.\n");
    }
}

void removePassenger(Elevator *e, int floor) {
    for (int i = 0; i < e->capacity; i++) {
        if (e->passengers[i] == floor) {
            // Move all passengers after the removed passenger one space back
            for (int j = i; j < e->capacity - 1; j++) {
                e->passengers[j] = e->passengers[j + 1];
            }

            e->capacity--;
            break;
        }
    }
}