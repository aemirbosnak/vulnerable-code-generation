//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int currentFloor;
    int requestedFloor;
    bool movingUp;
} Elevator;

Elevator elevator;

pthread_mutex_t elevatorMutex;
pthread_cond_t elevatorCond;

void initializeElevator() {
    elevator.currentFloor = 0;  // Start at ground floor
    elevator.requestedFloor = -1; // No floor requested initially
    elevator.movingUp = true;  // Moving up or down
}

void callElevator(int floor) {
    pthread_mutex_lock(&elevatorMutex);
    elevator.requestedFloor = floor;
    pthread_cond_signal(&elevatorCond);
    pthread_mutex_unlock(&elevatorMutex);
}

void* elevatorThread(void* arg) {
    while (true) {
        pthread_mutex_lock(&elevatorMutex);

        // Wait until a floor is requested
        while (elevator.requestedFloor == -1) {
            pthread_cond_wait(&elevatorCond, &elevatorMutex);
        }

        // Move the elevator towards the requested floor
        while (elevator.currentFloor != elevator.requestedFloor) {
            // Print current status
            printf("Elevator at floor %d...\n", elevator.currentFloor);
            if (elevator.currentFloor < elevator.requestedFloor) {
                elevator.currentFloor++;
            } else {
                elevator.currentFloor--;
            }
            sleep(1); // Simulate time taken to move between floors
        }
        
        // Arrived at the requested floor
        printf("Elevator arrived at floor %d\n", elevator.currentFloor);
        elevator.requestedFloor = -1; // Reset the request
        pthread_mutex_unlock(&elevatorMutex);
    }
    return NULL;
}

void printMenu() {
    printf("Elevator Control System\n");
    printf("1. Call elevator to floor 0\n");
    printf("2. Call elevator to floor 1\n");
    printf("3. Call elevator to floor 2\n");
    printf("4. Call elevator to floor 3\n");
    printf("5. Call elevator to floor 4\n");
    printf("6. Call elevator to floor 5\n");
    printf("7. Call elevator to floor 6\n");
    printf("8. Call elevator to floor 7\n");
    printf("9. Call elevator to floor 8\n");
    printf("10. Call elevator to floor 9\n");
    printf("0. Exit\n");
}

int main() {
    pthread_t elevatorControlThread;

    pthread_mutex_init(&elevatorMutex, NULL);
    pthread_cond_init(&elevatorCond, NULL);

    initializeElevator();
    pthread_create(&elevatorControlThread, NULL, elevatorThread, NULL);

    int choice;
    do {
        printMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        if (choice >= 0 && choice <= MAX_FLOORS) {
            if (choice != 0) {
                callElevator(choice - 1);
            }
        } else {
            printf("Invalid option. Please try again.\n");
        }
    } while (choice != 0);

    printf("Exiting elevator control system...\n");

    // Cleanup
    pthread_mutex_destroy(&elevatorMutex);
    pthread_cond_destroy(&elevatorCond);
    pthread_cancel(elevatorControlThread);
    pthread_join(elevatorControlThread, NULL);

    return 0;
}