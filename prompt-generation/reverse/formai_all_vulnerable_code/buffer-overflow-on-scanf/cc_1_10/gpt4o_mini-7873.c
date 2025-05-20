//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_FLOORS 10

typedef struct {
    int currentFloor;
    bool movingUp;
    pthread_mutex_t lock;
} Elevator;

Elevator elevator;

void initElevator() {
    elevator.currentFloor = 0;
    elevator.movingUp = true;
    pthread_mutex_init(&elevator.lock, NULL);
}

void requestElevator(int desiredFloor) {
    if (desiredFloor < 0 || desiredFloor >= MAX_FLOORS) {
        printf("Invalid floor! Please select a floor between 0 and %d.\n", MAX_FLOORS - 1);
        return;
    }

    pthread_mutex_lock(&elevator.lock);
    
    if (elevator.currentFloor == desiredFloor) {
        printf("Elevator is already on floor %d.\n", desiredFloor);
    } else {
        printf("Requesting elevator to floor %d...\n", desiredFloor);
        while (elevator.currentFloor != desiredFloor) {
            if (desiredFloor > elevator.currentFloor) {
                elevator.movingUp = true;
                elevator.currentFloor++;
            } else {
                elevator.movingUp = false;
                elevator.currentFloor--;
            }
            printf("Elevator is moving %s to floor %d...\n", 
                   elevator.movingUp ? "up" : "down", 
                   elevator.currentFloor);
            sleep(1); // Simulate time taken for the elevator to move
        }
        printf("Elevator has arrived at floor %d.\n", desiredFloor);
    }
    
    pthread_mutex_unlock(&elevator.lock);
}

void showMenu() {
    printf("\n=== Elevator Simulation ===\n");
    printf("Select a floor (0 - %d), or -1 to exit:\n", MAX_FLOORS - 1);
}

int main() {
    initElevator();

    int userChoice;

    while (true) {
        showMenu();
        scanf("%d", &userChoice);
        
        if (userChoice == -1) {
            printf("Exiting the elevator simulation...\n");
            break;
        }

        requestElevator(userChoice);
    }

    pthread_mutex_destroy(&elevator.lock);
    return 0;
}