//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Struct to represent a person
struct Person {
    char name[50];
    int floor;
    int elevator;
};

// Struct to represent an elevator
struct Elevator {
    int floor;
    int capacity;
};

// Function to display the state of the elevator
void displayState(struct Elevator elevator) {
    printf("Current floor: %d\n", elevator.floor);
    printf("Current capacity: %d\n", elevator.capacity);
}

// Function to display the state of the person
void displayPerson(struct Person person) {
    printf("Name: %s\n", person.name);
    printf("Floor: %d\n", person.floor);
    printf("Elevator: %d\n", person.elevator);
}

// Function to simulate the elevator
void simulateElevator(struct Elevator elevator) {
    struct Person people[10];
    int numPeople = 0;

    // Add people to the elevator
    for (int i = 0; i < 10; i++) {
        people[i].name[i] = 'A';
        people[i].floor = rand() % 10;
        people[i].elevator = rand() % 10;
        numPeople++;
    }

    // Display initial state of the elevator
    printf("Initial state of the elevator:\n");
    displayState(elevator);

    // Simulate elevator operation
    while (numPeople > 0) {
        // Move elevator up or down
        if (numPeople > 0) {
            if (numPeople >= elevator.capacity) {
                elevator.floor++;
                printf("Moving elevator up: %d -> %d\n", elevator.floor, elevator.floor);
                displayState(elevator);
            } else {
                elevator.floor--;
                printf("Moving elevator down: %d -> %d\n", elevator.floor, elevator.floor);
                displayState(elevator);
            }
        }

        // Move people in and out of the elevator
        for (int i = 0; i < numPeople; i++) {
            if (people[i].floor == elevator.floor) {
                people[i].elevator = -1;
                numPeople--;
            } else {
                people[i].elevator = elevator.floor;
            }
        }
    }

    // Display final state of the elevator
    printf("Final state of the elevator:\n");
    displayState(elevator);
}

// Function to simulate the elevator with input from the user
void simulateElevatorUserInput() {
    struct Elevator elevator;
    elevator.floor = 0;
    elevator.capacity = 5;

    struct Person people[10];
    int numPeople = 0;

    printf("Enter the number of people to simulate: ");
    scanf("%d", &numPeople);

    printf("Enter the floors for the people (enter 0 to stop): ");
    for (int i = 0; i < numPeople; i++) {
        int floor;
        scanf("%d", &floor);
        people[i].name[i] = 'A';
        people[i].floor = floor;
        people[i].elevator = -1;
        numPeople++;
    }

    printf("Enter the floors for the elevator (enter 0 to stop): ");
    for (int i = 0; i < 10; i++) {
        int floor;
        scanf("%d", &floor);
        elevator.floor = floor;
        numPeople++;
    }

    printf("Enter the capacity of the elevator: ");
    scanf("%d", &elevator.capacity);

    printf("Initial state of the elevator:\n");
    displayState(elevator);

    simulateElevator(elevator);

    printf("Final state of the elevator:\n");
    displayState(elevator);
}

int main() {
    simulateElevatorUserInput();
    return 0;
}