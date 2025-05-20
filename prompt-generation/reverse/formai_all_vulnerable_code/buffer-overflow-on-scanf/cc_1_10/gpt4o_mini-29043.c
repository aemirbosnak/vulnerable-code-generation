//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 5

typedef struct {
    int currentFloor;
    int destinationFloor;
    int passengerCount;
} Elevator;

Elevator elevator;
sem_t elevatorSem;
pthread_mutex_t elevatorMutex;

void* elevatorFunction(void* arg) {
    while (true) {
        sleep(1); // Elevator operates every second

        pthread_mutex_lock(&elevatorMutex);
        
        // Move elevator if there are passengers
        if (elevator.passengerCount > 0) {
            if (elevator.currentFloor < elevator.destinationFloor) {
                elevator.currentFloor++;
            } else if (elevator.currentFloor > elevator.destinationFloor) {
                elevator.currentFloor--;
            }

            printf("Elevator moving to floor %d\n", elevator.currentFloor);
        }

        pthread_mutex_unlock(&elevatorMutex);
    }
    return NULL;
}

void callElevator(int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor!\n");
        return;
    }

    pthread_mutex_lock(&elevatorMutex);
    elevator.destinationFloor = floor;
    printf("Elevator called to floor %d\n", floor);
    pthread_mutex_unlock(&elevatorMutex);
}

void loadPassenger() {
    pthread_mutex_lock(&elevatorMutex);
    
    if (elevator.passengerCount < MAX_CAPACITY) {
        elevator.passengerCount++;
        printf("A passenger entered. Current passenger count: %d\n", elevator.passengerCount);
    } else {
        printf("Elevator is full! Cannot load more passengers.\n");
    }
    
    pthread_mutex_unlock(&elevatorMutex);
}

void unloadPassenger() {
    pthread_mutex_lock(&elevatorMutex);
    
    if (elevator.passengerCount > 0) {
        elevator.passengerCount--;
        printf("A passenger exited. Current passenger count: %d\n", elevator.passengerCount);
    } else {
        printf("No passengers to unload!\n");
    }
    
    pthread_mutex_unlock(&elevatorMutex);
}

int main() {
    elevator.currentFloor = 0;
    elevator.destinationFloor = 0;
    elevator.passengerCount = 0;

    sem_init(&elevatorSem, 0, 1);
    pthread_mutex_init(&elevatorMutex, NULL);

    pthread_t elevatorThread;
    pthread_create(&elevatorThread, NULL, elevatorFunction, NULL);

    while (true) {
        int choice;
        printf("\nElevator Simulation Menu:\n");
        printf("1. Call Elevator to Floor\n");
        printf("2. Load Passenger\n");
        printf("3. Unload Passenger\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int floor;
                printf("Enter floor number to call the elevator (0-%d): ", MAX_FLOORS - 1);
                scanf("%d", &floor);
                callElevator(floor);
                break;
            }
            case 2:
                loadPassenger();
                break;
            case 3:
                unloadPassenger();
                break;
            case 4:
                printf("Exiting simulation...\n");
                pthread_cancel(elevatorThread); // Cancel elevator thread
                pthread_join(elevatorThread, NULL); // Wait for thread to finish
                pthread_mutex_destroy(&elevatorMutex);
                sem_destroy(&elevatorSem);
                exit(0);
            default:
                printf("Invalid option, try again!\n");
        }
    }

    return 0;
}