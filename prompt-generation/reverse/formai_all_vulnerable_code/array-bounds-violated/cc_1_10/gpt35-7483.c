//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MAX_FLOORS 10        // Maximum number of floors
#define ELEVATOR_CAPACITY 5  // Maximum number of people in elevator

// Structs
typedef struct {
    int floor;        // Elevator's current floor
    int direction;    // Elevator's current direction (1 for up, -1 for down, 0 for stationary)
    int occupancy;    // Current number of people in elevator
    int stops[MAX_FLOORS];  // Each floor the elevator will stop at
} Elevator;

// Global Variables
int numFloors;
int numPeople;
Elevator elevator;

// Function Prototypes
void initializeElevator();
void printElevatorStatus();
void getPassengerInput();
void elevatorMovement();
void printEndSimulation();

int main() {
    printf("Welcome to Elevator Simulator 2021!\n");
    printf("Please enter the number of floors (maximum %d): ", MAX_FLOORS);
    scanf("%d", &numFloors);
    printf("Please enter the number of people (maximum capacity %d): ", ELEVATOR_CAPACITY);
    scanf("%d", &numPeople);

    initializeElevator();
    printElevatorStatus();

    // Keep simulating until elevator has stopped at all floors
    while (elevator.floor != -1) {
        getPassengerInput();
        elevatorMovement();
        printElevatorStatus();
    }

    printEndSimulation();
    return 0;
}

void initializeElevator() {
    srand(time(0));  // Seed random number generator

    elevator.floor = 0;
    elevator.direction = 1;  // Start moving up
    elevator.occupancy = 0;

    // Initialize stops as random floors
    for (int i = 0; i < numFloors; i++) {
        elevator.stops[i] = (rand() % 2 == 0) ? 1 : 0;
    }
}

void printElevatorStatus() {
    printf("\n====== ELEVATOR STATUS ======\n");
    printf("Floor: %d\n", elevator.floor);
    printf("Direction: %s\n", (elevator.direction == 1) ? "UP": "DOWN");
    printf("Occupancy: %d/%d\n", elevator.occupancy, ELEVATOR_CAPACITY);
    printf("Stops: ");
    for (int i = 0; i < numFloors; i++) {
        printf("%d ", elevator.stops[i]);
    }
    printf("\n============================\n");
}

void getPassengerInput() {
    int boarding, goingTo;
    printf("\nPlease enter the floor where you want to board (current floor is %d): ", elevator.floor);
    scanf("%d", &boarding);
    printf("Please enter the floor where you want to go: ");
    scanf("%d", &goingTo);

    if (boarding == elevator.floor && elevator.occupancy < ELEVATOR_CAPACITY) {
        elevator.occupancy++;
        elevator.stops[goingTo] = 1;
    } else {
        printf("Sorry, the elevator is not currently on your floor or is at maximum capacity.\n");
    }
}

void elevatorMovement() {
    // Check if elevator has reached its maximum floor
    if (elevator.floor == numFloors - 1) {
        elevator.direction = -1;  // Change direction to go down
    }

    // Check if elevator has reached ground floor and no more stops are required
    if (elevator.floor == 0 && elevator.stops[0] == 0) {
        elevator.direction = 0;  // Stop elevator
        elevator.floor = -1;     // End simulation
        return;
    }

    // Move elevator up
    if (elevator.direction == 1) {
        elevator.floor++;
        if (elevator.stops[elevator.floor] == 1) {
            elevator.stops[elevator.floor] = 0;
            elevator.occupancy--;
        }
    } else {  // Move elevator down
        elevator.floor--;
        if (elevator.stops[elevator.floor] == 1) {
            elevator.stops[elevator.floor] = 0;
            elevator.occupancy--;
        }
    }
}

void printEndSimulation() {
    printf("\n======== ELEVATOR SIMULATION ENDED ========\n");
    printf("Final floor: %d\n", elevator.floor);
    printf("Final direction: %s\n", (elevator.direction == 0) ? "STATIONARY": ((elevator.direction == 1) ? "UP": "DOWN"));
    printf("Final occupancy: %d/%d\n", elevator.occupancy, ELEVATOR_CAPACITY);
    printf("Final stops: ");
    for (int i = 0; i < numFloors; i++) {
        printf("%d ", elevator.stops[i]);
    }
    printf("\n===========================================\n");
}