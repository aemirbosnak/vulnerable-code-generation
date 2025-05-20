//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_FLOORS 5

// Enum to hold the direction of the elevator
typedef enum {
    UP,
    DOWN,
    IDLE
} Directions;

// Struct to hold information about the elevator
typedef struct {
    int currentFloor;
    Directions currentDirection;
    bool doorsOpen;
    int numPassengers;
} Elevator;

// Struct to hold information about a floor
typedef struct {
    bool callUp;
    bool callDown;
} Floor;

// Function to initialize the elevator
void initElevator(Elevator* elevator) {
    elevator->currentFloor = 1;
    elevator->currentDirection = IDLE;
    elevator->doorsOpen = false;
    elevator->numPassengers = 0;
}

// Function to initialize the floors
void initFloors(Floor floors[]) {
    for (int i = 0; i < NUM_FLOORS; i++) {
        floors[i].callUp = false;
        floors[i].callDown = false;
    }
}

// Function to print the current status of the elevator
void printStatus(Elevator* elevator) {
    printf("Floor: %d\n", elevator->currentFloor);
    printf("Direction: %d\n", elevator->currentDirection);
    printf("Doors open: %s\n", elevator->doorsOpen ? "true" : "false");
    printf("Passengers: %d\n", elevator->numPassengers);
}

// Function to check if any floors are calling the elevator
bool checkFloorCalls(Floor floors[]) {
    for (int i = 0; i < NUM_FLOORS; i++) {
        if (floors[i].callUp || floors[i].callDown) {
            return true;
        }
    }
    return false;
}

// Main function
int main() {
    Elevator elevator;
    Floor floors[NUM_FLOORS];
    initElevator(&elevator);
    initFloors(floors);
    
    while (true) {
        // Check for user input
        char input;
        scanf("%c", &input);
        getchar(); // Clear the newline from the input buffer
        
        switch (input) {
            // User wants to call the elevator from the first floor
            case '1':
                if (elevator.currentFloor == 1) {
                    // Elevator is already on the first floor
                    printf("Elevator doors opening...\n");
                    printf("Please enter the elevator.\n");
                } else {
                    printf("Elevator called to first floor.\n");
                    floors[0].callUp = true; // Call the elevator to the first floor
                }
                break;
            // User wants to call the elevator from the second floor
            case '2':
                if (elevator.currentFloor == 2) {
                    // Elevator is already on the second floor
                    printf("Elevator doors opening...\n");
                    printf("Please enter the elevator.\n");
                } else if (elevator.currentFloor > 2) {
                    printf("Elevator called to second floor.\n");
                    floors[1].callUp = true; // Call the elevator to the second floor
                } else {
                    printf("Elevator called to second floor.\n");
                    floors[1].callDown = true; // Call the elevator to the second floor
                }
                break;
            // User wants to call the elevator from the third floor
            case '3':
                if (elevator.currentFloor == 3) {
                    // Elevator is already on the third floor
                    printf("Elevator doors opening...\n");
                    printf("Please enter the elevator.\n");
                } else if (elevator.currentFloor > 3) {
                    printf("Elevator called to third floor.\n");
                    floors[2].callUp = true; // Call the elevator to the third floor
                } else {
                    printf("Elevator called to third floor.\n");
                    floors[2].callDown = true; // Call the elevator to the third floor
                }
                break;
            // User wants to call the elevator from the fourth floor
            case '4':
                if (elevator.currentFloor == 4) {
                    // Elevator is already on the fourth floor
                    printf("Elevator doors opening...\n");
                    printf("Please enter the elevator.\n");
                } else if (elevator.currentFloor > 4) {
                    printf("Elevator called to fourth floor.\n");
                    floors[3].callUp = true; // Call the elevator to the fourth floor
                } else {
                    printf("Elevator called to fourth floor.\n");
                    floors[3].callDown = true; // Call the elevator to the fourth floor
                }
                break;
            // User wants to call the elevator from the fifth floor
            case '5':
                if (elevator.currentFloor == 5) {
                    // Elevator is already on the fifth floor
                    printf("Elevator doors opening...\n");
                    printf("Please enter the elevator.\n");
                } else {
                    printf("Elevator called to fifth floor.\n");
                    floors[4].callDown = true; // Call the elevator to the fifth floor
                }
                break;
            // User wants to go up one floor
            case 'u':
                if (elevator.currentDirection == UP) {
                    printf("Elevator already moving up...\n");
                } else {
                    elevator.currentDirection = UP;
                    printf("Elevator moving up...\n");
                }
                break;
            // User wants to go down one floor
            case 'd':
                if (elevator.currentDirection == DOWN) {
                    printf("Elevator already moving down...\n");
                } else {
                    elevator.currentDirection = DOWN;
                    printf("Elevator moving down...\n");
                }
                break;
            // User wants to stop the elevator
            case 's':
                elevator.currentDirection = IDLE;
                printf("Elevator stopped.\n");
                break;
            // User wants to enter the elevator
            case 'e':
                if (elevator.doorsOpen) {
                    elevator.numPassengers++;
                    printf("Passenger entered elevator. There are now %d passengers.\n", elevator.numPassengers);
                } else {
                    printf("Elevator doors are closed. Please wait for doors to open.\n");
                }
                break;
            // User wants to exit the elevator
            case 'x':
                if (elevator.doorsOpen) {
                    elevator.numPassengers--;
                    printf("Passenger exited elevator. There are now %d passengers.\n", elevator.numPassengers);
                } else {
                    printf("Elevator doors are closed. Please wait for doors to open.\n");
                }
                break;
            // User wants to print the status of the elevator
            case 'p':
                printStatus(&elevator);
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
        
        // Check for floor calls and move the elevator accordingly
        if (checkFloorCalls(floors)) {
            if (elevator.currentFloor == 1) {
                elevator.currentDirection = UP;
            } else if (elevator.currentFloor == NUM_FLOORS) {
                elevator.currentDirection = DOWN;
            }
            
            switch (elevator.currentDirection) {
                case UP:
                    printf("Elevator moving up...\n");
                    elevator.currentFloor++;
                    break;
                case DOWN:
                    printf("Elevator moving down...\n");
                    elevator.currentFloor--;
                    break;
                default:
                    printf("Elevator waiting...\n");
                    break;
            }
            
            // Open the doors if the elevator has arrived at a floor with a call
            if (floors[elevator.currentFloor - 1].callUp || floors[elevator.currentFloor - 1].callDown) {
                printf("Elevator doors opening...\n");
                elevator.doorsOpen = true;
                floors[elevator.currentFloor - 1].callUp = false;
                floors[elevator.currentFloor - 1].callDown = false;
            } else {
                // Close the doors if there are no passengers getting on or off
                printf("Elevator doors closing...\n");
                elevator.doorsOpen = false;
            }
        }
    }
    
    return 0;
}