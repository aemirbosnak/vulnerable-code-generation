//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_FLOORS 10 // Number of Floors in the Building
#define NUM_ELEVATORS 3 // Number of Elevators in the Building

// Enum for Direction
typedef enum {
    UP,
    DOWN
} Direction;

// Struct for Request
typedef struct {
    int floorNumber;
    Direction direction;
} Request;

// Struct for Elevator
typedef struct {
    int id;
    int currentFloor;
    Direction direction;
    bool isOccupied;
    Request currentRequest;
} Elevator;

Elevator elevators[NUM_ELEVATORS];
pthread_mutex_t mutexLock; // Mutex Lock for Thread Synchronization
pthread_cond_t conditionVariable = PTHREAD_COND_INITIALIZER; // Condition Variable for Thread Synchronization

void *elevatorController(void *elevatorID) {
    int id = *(int *) elevatorID;
    Elevator *currentElevator = &elevators[id];

    while (true) {
        // Wait for Signal from External Request
        pthread_mutex_lock(&mutexLock);
        while (currentElevator->currentRequest.floorNumber == -1) {
            pthread_cond_wait(&conditionVariable, &mutexLock);
        }

        printf("Elevator %d Received Request from Floor %d for Direction %d\n", id, currentElevator->currentRequest.floorNumber, currentElevator->currentRequest.direction);

        // Go to Requested Floor
        while (currentElevator->currentFloor != currentElevator->currentRequest.floorNumber) {
            if (currentElevator->currentFloor < currentElevator->currentRequest.floorNumber) {
                currentElevator->currentFloor++;
                currentElevator->direction = UP;
            } else {
                currentElevator->currentFloor--;
                currentElevator->direction = DOWN;
            }

            printf("Elevator %d is now at Floor %d\n", id, currentElevator->currentFloor);
            sleep(1);
        }

        printf("Elevator %d has arrived at Floor %d\n", id, currentElevator->currentRequest.floorNumber);

        // Update Elevator Status
        currentElevator->isOccupied = true;
        currentElevator->currentRequest.floorNumber = -1;

        // Release Mutex Lock
        pthread_mutex_unlock(&mutexLock);
    }

    pthread_exit(NULL);
}

int getDirection(int currentFloor, int requestedFloor) {
    if (requestedFloor > currentFloor) {
        return UP;
    } else if (requestedFloor < currentFloor) {
        return DOWN;
    }
    return -1;
}

int main() {
    // Initialize Elevators
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        Elevator elevator = {
            .id = i,
            .currentFloor = 0,
            .direction = UP,
            .isOccupied = false,
            .currentRequest = { -1, UP }
        };
        elevators[i] = elevator;
    }

    // Start Elevator Threads
    pthread_t elevatorThreads[NUM_ELEVATORS];
    int elevatorIDs[NUM_ELEVATORS];

    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevatorIDs[i] = i;
        pthread_create(&elevatorThreads[i], NULL, elevatorController, &elevatorIDs[i]);
    }

    // Simulation Loop
    while (true) {
        // Get External Requests
        int floorNumber;
        int directionInt;
        Direction direction;

        printf("Enter Floor Number and Direction (0 for DOWN, 1 for UP): ");
        scanf("%d %d", &floorNumber, &directionInt);
        direction = (directionInt == 0) ? DOWN : UP;

        // Find Nearest Available Elevator
        int minDistance = abs(elevators[0].currentFloor - floorNumber);
        int closestElevator = 0;

        for (int i = 1; i < NUM_ELEVATORS; i++) {
            int distance = abs(elevators[i].currentFloor - floorNumber);
            if (!elevators[i].isOccupied && distance < minDistance) {
                minDistance = distance;
                closestElevator = i;
            }
        }

        // Update Elevator Status
        elevators[closestElevator].currentRequest.floorNumber = floorNumber;
        elevators[closestElevator].currentRequest.direction = direction;

        // Signal the Elevator Thread
        pthread_mutex_lock(&mutexLock);
        pthread_cond_signal(&conditionVariable);
        pthread_mutex_unlock(&mutexLock);
    }

    return 0;
}