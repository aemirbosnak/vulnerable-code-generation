//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

// Struct for Elevator
struct Elevator {
    int currentFloor;
    int destinationFloor;
    int direction; // -1: down, 0: stopped, 1: up
    int capacity;
    int passengers;
    int isMoving;
};

// Main Program
int main() {
    struct Elevator elevators[NUM_ELEVATORS];
    int floors[NUM_FLOORS] = {0}; // Array to track if floor has requested elevator
    
    // Initialize elevators
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].currentFloor = 1;
        elevators[i].direction = 0;
        elevators[i].capacity = 8;
        elevators[i].passengers = 0;
        elevators[i].isMoving = 0;
    }
    
    // Loop until user exits
    while (1) {
        // Print state of each elevator
        printf("Elevator Status:\n");
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            printf("Elevator %d: ", i+1);
            if (elevators[i].isMoving) {
                printf("Moving %s from floor %d to floor %d with %d passengers\n", elevators[i].direction == 1 ? "up" : "down", elevators[i].currentFloor, elevators[i].destinationFloor, elevators[i].passengers);
            }
            else {
                printf("Stopped at floor %d with %d passengers\n", elevators[i].currentFloor, elevators[i].passengers);
            }
        }
        
        // Check for user input
        printf("Enter a floor number to request an elevator (1-10), or type 'exit' to quit: ");
        char input[10];
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        int floor = atoi(input);
        
        // Check if floor is valid
        if (floor < 1 || floor > 10) {
            printf("Invalid floor number. Please try again.\n");
            continue;
        }
        
        // Check if elevator is already at requested floor
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            if (elevators[i].isMoving == 0 && elevators[i].currentFloor == floor) {
                printf("Elevator %d is already at floor %d. Please enter.\n", i+1, floor);
                elevators[i].passengers++;
                floors[floor-1] = 0; // Reset floor request
                break;
            }
        }
        
        // Check for available elevator to request
        int availableElevator = -1; // No available elevators
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            if (elevators[i].isMoving == 0 && elevators[i].passengers < elevators[i].capacity) { // Elevator is stopped and has space for passengers
                if (availableElevator == -1 || abs(floor-elevators[i].currentFloor) < abs(floor-elevators[availableElevator].currentFloor)) { // Elevator is closer to requested floor than previously found available elevator
                    availableElevator = i;
                }
            }
        }
        
        // If available elevator found, add floor request and set destination
        if (availableElevator != -1) {
            elevators[availableElevator].destinationFloor = floor;
            elevators[availableElevator].direction = floor > elevators[availableElevator].currentFloor ? 1 : -1; // Set direction based on requested floor
            elevators[availableElevator].isMoving = 1;
            floors[floor-1] = 1; // Set floor request
        }
        else {
            printf("All elevators are currently in use. Please wait for one to become available.\n");
        }
    }
    
    return 0;
}