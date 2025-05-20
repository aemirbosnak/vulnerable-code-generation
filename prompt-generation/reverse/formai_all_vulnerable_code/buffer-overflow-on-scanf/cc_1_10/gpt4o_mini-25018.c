//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define MAX_USERS 5

typedef struct {
    int currentFloor;
    int direction; // -1 for down, 1 for up, 0 for idle
} Elevator;

typedef struct {
    int id;
    int requestedFloor;
} User;

void initializeElevator(Elevator* elevator) {
    elevator->currentFloor = 0;
    elevator->direction = 0;
}

void requestElevator(User users[], int userId, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("User %d: Invalid floor request. Please request a floor between 0 and %d.\n", userId, MAX_FLOORS - 1);
        return;
    }
    users[userId].requestedFloor = floor;
    printf("User %d: Requested elevator to floor %d.\n", userId, floor);
}

void moveElevator(Elevator* elevator, int targetFloor) {
    if (elevator->currentFloor < targetFloor) {
        elevator->direction = 1;
    } else if (elevator->currentFloor > targetFloor) {
        elevator->direction = -1;
    } else {
        elevator->direction = 0;
        return;
    }

    while (elevator->currentFloor != targetFloor) {
        sleep(1); // Simulate the time taken to move between floors
        elevator->currentFloor += elevator->direction;
        printf("Elevator: Current floor is %d.\n", elevator->currentFloor);
    }

    elevator->direction = 0;
    printf("Elevator has arrived at floor %d.\n", targetFloor);
}

void elevatorSimulation(User users[], int userCount) {
    Elevator elevator;
    initializeElevator(&elevator);
    
    for (int i = 0; i < userCount; i++) {
        moveElevator(&elevator, users[i].requestedFloor);
        // Reset user's request
        users[i].requestedFloor = -1; 
    }
}

int main() {
    User users[MAX_USERS];
    int numUsers;

    printf("Enter the number of users (max %d): ", MAX_USERS);
    scanf("%d", &numUsers);

    if (numUsers < 1 || numUsers > MAX_USERS) {
        printf("Invalid number of users. Please enter a number between 1 and %d.\n", MAX_USERS);
        return 1;
    }

    for (int i = 0; i < numUsers; i++) {
        users[i].id = i + 1;
        users[i].requestedFloor = -1; // Initialize to no requests
        int floor;

        printf("User %d, enter your requested floor (0 to %d): ", users[i].id, MAX_FLOORS - 1);
        scanf("%d", &floor);
        requestElevator(users, i, floor);
    }

    elevatorSimulation(users, numUsers);

    return 0;
}