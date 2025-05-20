//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 4

// Global variables
int currentFloor = 1;
int numPassengers = 0;
bool goingUp = true;
bool doorsOpen = false;
bool emergencyStop = false;

// Function prototypes
void printStatus();
int getRandomFloor();
void generatePassengers();
void moveElevator();
void openDoors();
void closeDoors();
void addPassenger();
void removePassenger();
void emergency();

int main() {
    srand(time(NULL));  // Seed random number generator

    printf("Welcome to the Post-Apocalyptic Elevator Simulation!\n\n");

    while (true) {
        printStatus();
        generatePassengers();
        moveElevator();

        char command;

        printf("Enter command (o for doors, p for passenger, e for emergency stop, q to quit): ");
        scanf(" %c", &command);

        switch (command) {
            case 'o':
                if (!emergencyStop) {
                    if (doorsOpen) {
                        closeDoors();
                    } else {
                        openDoors();
                    }
                } else {
                    printf("Cannot operate doors in emergency mode.\n\n");
                }
                break;

            case 'p':
                if (!emergencyStop) {
                    if (numPassengers < MAX_CAPACITY) {
                        addPassenger();
                    } else {
                        printf("Elevator is at maximum capacity.\n\n");
                    }
                } else {
                    printf("Cannot add passenger in emergency mode.\n\n");
                }
                break;

            case 'e':
                emergency();
                break;

            case 'q':
                printf("Exiting program.\n");
                exit(0);
                break;

            default:
                printf("Invalid command. Please try again.\n\n");
        }
    }

    return 0;
}

void printStatus() {
    printf("Current floor: %d\n", currentFloor);
    printf("Number of passengers: %d\n", numPassengers);
    printf("Direction: %s\n", (goingUp ? "Up" : "Down"));
    printf("Doors: %s\n", (doorsOpen ? "Open" : "Closed"));
    printf("Emergency stop: %s\n\n", (emergencyStop ? "On" : "Off"));
}

int getRandomFloor() {
    int randomFloor = (rand() % MAX_FLOORS) + 1;

    while (randomFloor == currentFloor) {
        randomFloor = (rand() % MAX_FLOORS) + 1;
    }

    return randomFloor;
}

void generatePassengers() {
    int probability = rand() % 101;

    if (probability < 25) {
        int numNewPassengers = rand() % (MAX_CAPACITY - numPassengers) + 1;

        for (int i = 0; i < numNewPassengers; i++) {
            addPassenger();
        }
    }
}

void moveElevator() {
    if (!emergencyStop) {
        if (doorsOpen) {
            closeDoors();
        } else {
            if (goingUp) {
                if (currentFloor == MAX_FLOORS) {
                    goingUp = false;
                } else {
                    currentFloor++;
                }
            } else {
                if (currentFloor == 1) {
                    goingUp = true;
                } else {
                    currentFloor--;
                }
            }

            // Check if any passengers need to get off at current floor
            for (int i = 0; i < numPassengers; i++) {
                if (currentFloor == getRandomFloor()) {
                    removePassenger();
                }
            }
        }
    } else {
        printf("Emergency stop activated. Elevator is not moving.\n\n");
    }
}

void openDoors() {
    printf("Doors opening.\n\n");
    doorsOpen = true;
}

void closeDoors() {
    printf("Doors closing.\n\n");
    doorsOpen = false;
}

void addPassenger() {
    printf("Passenger boarding.\n");
    numPassengers++;
}

void removePassenger() {
    printf("Passenger departing.\n");
    numPassengers--;
}

void emergency() {
    if (emergencyStop) {
        emergencyStop = false;
        printf("Emergency mode deactivated.\n\n");
    } else {
        emergencyStop = true;
        closeDoors();
        printf("Emergency mode activated.\n\n");
    }
}