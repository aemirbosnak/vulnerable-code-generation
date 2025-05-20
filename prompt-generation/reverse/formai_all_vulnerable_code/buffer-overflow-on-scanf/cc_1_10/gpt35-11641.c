//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: mind-bending
#include <stdio.h>

#define MAX_FLOORS 20
#define MAX_PEOPLE 10

// Function to check if floor is valid
int isValidFloor(int floor) {
    if (floor < 1 || floor > MAX_FLOORS) {
        return 0;
    }
    return 1;
}

// Function to display welcome message
void displayWelcomeMessage() {
    printf("Welcome to the Mind-Bending Elevator Simulation Program\n");
    printf("This program simulates the movement of an elevator between %d floors\n", MAX_FLOORS);
    printf("Maximum of %d people can be accommodated in the elevator at a time\n", MAX_PEOPLE);
}

// Function to get current floor
int getCurrentFloor() {
    int currentFloor;
    printf("\nEnter current floor (1-20): ");
    scanf("%d", &currentFloor);

    if (!isValidFloor(currentFloor)) {
        printf("\nInvalid floor! Please enter a number between 1 and 20\n");
        return getCurrentFloor();
    }

    return currentFloor;
}

// Function to get destination floor
int getDestinationFloor() {
    int destinationFloor;
    printf("\nEnter destination floor (1-20): ");
    scanf("%d", &destinationFloor);

    if (!isValidFloor(destinationFloor)) {
        printf("\nInvalid floor! Please enter a number between 1 and 20\n");
        return getDestinationFloor();
    }

    return destinationFloor;
}

// Function to get number of people in the elevator
int getNumberOfPeopleInElevator() {
    int numberOfPeople;
    printf("\nEnter number of people in the elevator (1-10): ");
    scanf("%d", &numberOfPeople);

    if (numberOfPeople < 1 || numberOfPeople > MAX_PEOPLE) {
        printf("\nInvalid number of people! Please enter a number between 1 and %d\n", MAX_PEOPLE);
        return getNumberOfPeopleInElevator();
    }

    return numberOfPeople;
}

// Function to simulate elevator movement
void simulateElevatorMovement(int currentFloor, int destinationFloor, int numberOfPeople) {
    printf("\nSimulating elevator movement...\n\n");
    int i;
    for (i = currentFloor; i < destinationFloor; i++) {
        printf("Elevator is currently on floor %d, heading towards floor %d\n", i, i + 1);
    }
    for (i = destinationFloor; i < currentFloor; i++) {
        printf("Elevator is currently on floor %d, heading towards floor %d\n", i, i - 1);
    }
    printf("\nElevator has reached the destination floor %d\n", destinationFloor);
    printf("%d people got off the elevator at floor %d\n", numberOfPeople, destinationFloor);
}

int main() {
    displayWelcomeMessage();

    int currentFloor = getCurrentFloor();
    int destinationFloor = getDestinationFloor();
    int numberOfPeople = getNumberOfPeopleInElevator();

    simulateElevatorMovement(currentFloor, destinationFloor, numberOfPeople);

    printf("\nThank you for using the Mind-Bending Elevator Simulation program!");
    return 0;
}