//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: standalone
#include <stdio.h>

// Elevator constants
#define FLOOR_COUNT 10
#define MAX_CAPACITY 15

// Elevator status
int currentFloor = 0;
int currentCapacity = 0;
int passengersDestination[FLOOR_COUNT] = {0};
int passengersCount[FLOOR_COUNT] = {0};

// Functions to simulate elevator operation

// Function to move elevator to a specified floor
void goToFloor(int floor) {
    int direction = 1;
    if (floor < currentFloor) {
        direction = -1;
    }
    while (currentFloor != floor) {
        currentFloor += direction;
        printf("Elevator moving to floor %d\n", currentFloor);
    }
    printf("The elevator has reached your destination floor %d\n", currentFloor);
}

// Function to add a passenger to elevator
int addPassenger(int destinationFloor) {
    if (currentCapacity == MAX_CAPACITY) {
        printf("Sorry, the elevator is full\n");
        return 0;
    }
    if (destinationFloor == currentFloor) {
        printf("Sorry, you are already at your destination floor\n");
        return 0;
    }
    passengersDestination[destinationFloor]++;
    passengersCount[currentFloor]++;
    currentCapacity++;
    printf("Added a passenger to the elevator\n");
    return 1;
}

// Function to remove passengers who have reached their destination floor
void removePassengers() {
    if (passengersCount[currentFloor] > 0) {
        currentCapacity -= passengersCount[currentFloor];
        passengersCount[currentFloor] = 0;
        printf("Removed %d passengers from the elevator\n", passengersCount[currentFloor]);
    }
}

int main() {
    int destinationFloor, done = 0;
    while (!done) {
        printf("Enter destination floor (0 to exit): ");
        scanf("%d", &destinationFloor);
        if (destinationFloor == 0) {
            done = 1;
            continue;
        }
        goToFloor(destinationFloor);
        if (addPassenger(destinationFloor) == 0) {
            continue;
        }
        printf("Enter passenger destination floor: ");
        scanf("%d", &destinationFloor);
        addPassenger(destinationFloor);
        removePassengers();
    }
    return 0;
}