//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants
#define MAX_FLOORS 20
#define MAX_PEOPLE 10

// Structs
typedef struct {
    int floor;
    int destination;
} Person;

// Function declarations
void initPeople(Person* people, int numPeople);
void printPeople(Person* people, int numPeople);
void moveElevator(int* currentFloor, int destination);
bool isDestinationReached(int currentFloor, int destination);
bool isElevatorFull(bool* seatedPeople, int numPeople);

int main() {
    // Variables
    int elevatorFloor = 1, numPeople = 0, time = 0;
    bool seatedPeople[MAX_PEOPLE] = { false };
    Person people[MAX_PEOPLE];

    // Initial setup
    printf("Welcome to the Elevator Simulator!\n");
    printf("How many people are in the building? ");
    scanf("%d", &numPeople);
    printf("Great! We have %d people in the building.\n", numPeople);

    initPeople(people, numPeople);

    // Main loop
    while (true) {
        // Print current state
        printf("\nTime: %d seconds\n", time);
        printf("Elevator Floor: %d\n", elevatorFloor);
        printf("People in elevator: ");
        for (int i = 0; i < numPeople; i++) {
            if (seatedPeople[i]) {
                printf("%d ", i);
            }
        }
        printf("\nPeople waiting: ");
        printPeople(people, numPeople);

        // Check if there are any people waiting on this floor
        bool waiting = false;
        for (int i = 0; i < numPeople; i++) {
            if (people[i].floor == elevatorFloor && !seatedPeople[i]) {
                waiting = true;
                break;
            }
        }

        if (waiting) {
            // Stop and pick up people
            printf("Stopping at floor %d to pick up passengers.\n", elevatorFloor);

            for (int i = 0; i < numPeople; i++) {
                if (people[i].floor == elevatorFloor && !seatedPeople[i]) {
                    if (!isElevatorFull(seatedPeople, numPeople)) {
                        printf("Person %d got in.\n", i);
                        seatedPeople[i] = true;
                    } else {
                        printf("Elevator is full. Person %d has to wait.\n", i);
                    }
                }
            }
        }

        // Check if there are any passengers in the elevator
        bool passengers = false;
        for (int i = 0; i < numPeople; i++) {
            if (seatedPeople[i]) {
                passengers = true;
                break;
            }
        }

        if (passengers) {
            // Find the destination floor closest to the current floor
            int closest = MAX_FLOORS;
            for (int i = 0; i < numPeople; i++) {
                if (seatedPeople[i]) {
                    if (abs(people[i].destination - elevatorFloor) < closest) {
                        closest = abs(people[i].destination - elevatorFloor);
                    }
                }
            }

            // Move the elevator to the closest destination floor
            for (int i = 0; i < numPeople; i++) {
                if (seatedPeople[i]) {
                    if (abs(people[i].destination - elevatorFloor) == closest) {
                        printf("Person %d is getting off at floor %d.\n", i, people[i].destination);
                        moveElevator(&elevatorFloor, people[i].destination);
                        seatedPeople[i] = false;
                    }
                }
            }
        }

        // Check if all destinations have been reached
        bool allReached = true;
        for (int i = 0; i < numPeople; i++) {
            if (seatedPeople[i]) {
                allReached = false;
                break;
            }
        }

        if (allReached) {
            printf("All destinations have been reached. End of simulation!\n");
            break;
        }

        // Advance time
        time++;
    }

    return 0;
}

void initPeople(Person* people, int numPeople) {
    for (int i = 0; i < numPeople; i++) {
        int floor = rand() % MAX_FLOORS + 1;
        int dest = rand() % MAX_FLOORS + 1;
        while (dest == floor) {
            dest = rand() % MAX_FLOORS + 1;
        }
        people[i].floor = floor;
        people[i].destination = dest;
    }
}

void printPeople(Person* people, int numPeople) {
    for (int i = 0; i < numPeople; i++) {
        if (people[i].floor != -1) {
            printf("(%d, %d) ", people[i].floor, people[i].destination);
        }
    }
    printf("\n");
}

void moveElevator(int* currentFloor, int destination) {
    int direction = destination - *currentFloor > 0 ? 1 : -1;
    while (!isDestinationReached(*currentFloor, destination)) {
        printf("Moving to floor %d...\n", *currentFloor + direction);
        *currentFloor += direction;
    }
}

bool isDestinationReached(int currentFloor, int destination) {
    return currentFloor == destination;
}

bool isElevatorFull(bool* seatedPeople, int numPeople) {
    int count = 0;
    for (int i = 0; i < numPeople; i++) {
        if (seatedPeople[i]) {
            count++;
        }
    }
    return count >= 5;
}