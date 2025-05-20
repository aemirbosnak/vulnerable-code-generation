//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_FLOORS 10
#define MAX_ELEVATORS 3

// Global variables
int currentFloor[MAX_ELEVATORS];
int destinationFloor[MAX_ELEVATORS];
int elevatorStatus[MAX_ELEVATORS];
pthread_mutex_t mutex;

// Function to move the elevator
void *moveElevator(void *arg) {
    int elevatorID = *(int *)arg;
    while (1) {
        pthread_mutex_lock(&mutex);
        if (elevatorStatus[elevatorID] == 1) {
            if (currentFloor[elevatorID] < destinationFloor[elevatorID]) {
                currentFloor[elevatorID]++;
                printf("Elevator %d moving up to Floor %d\n", elevatorID, currentFloor[elevatorID]);
            } else {
                elevatorStatus[elevatorID] = 0;
                printf("Elevator %d reached destination Floor %d\n", elevatorID, currentFloor[elevatorID]);
            }
        } else if (elevatorStatus[elevatorID] == -1) {
            if (currentFloor[elevatorID] > destinationFloor[elevatorID]) {
                currentFloor[elevatorID]--;
                printf("Elevator %d moving down to Floor %d\n", elevatorID, currentFloor[elevatorID]);
            } else {
                elevatorStatus[elevatorID] = 0;
                printf("Elevator %d reached destination Floor %d\n", elevatorID, currentFloor[elevatorID]);
            }
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t elevatorThread[MAX_ELEVATORS];
    int elevatorID[MAX_ELEVATORS];
    int numFloors, numElevators, option;
    
    // Get user input for number of floors and elevators
    printf("Enter number of floors (max %d): ", MAX_FLOORS);
    scanf("%d", &numFloors);
    printf("Enter number of elevators (max %d): ", MAX_ELEVATORS);
    scanf("%d", &numElevators);
    
    // Initialize global variables
    for (int i = 0; i < numElevators; i++) {
        elevatorID[i] = i;
        currentFloor[i] = 1;
        destinationFloor[i] = 1;
    }
    
    // Create threads for each elevator
    for (int i = 0; i < numElevators; i++) {
        pthread_create(&elevatorThread[i], NULL, moveElevator, &elevatorID[i]);
    }

    while (1) {
        printf("\nChoose an option: \n");
        printf("1. Request an elevator\n");
        printf("2. Exit\n");
        scanf("%d", &option);
        
        if (option == 1) {
            int fromFloor, toFloor;
            printf("Enter starting floor: ");
            scanf("%d", &fromFloor);
            printf("Enter destination floor: ");
            scanf("%d", &toFloor);
            
            // Find the closest elevator to the requested floor
            int closestElevator = -1;
            int minDistance = numFloors;
            for (int i = 0; i < numElevators; i++) {
                if (elevatorStatus[i] == 0) {
                    if (abs(fromFloor - currentFloor[i]) < minDistance) {
                        closestElevator = i;
                        minDistance = abs(fromFloor - currentFloor[i]);
                    }
                }
            }
            
            // If all elevators are busy, display message
            if (closestElevator == -1) {
                printf("All elevators are busy. Please wait.\n");
            } else {
                // Assign destination floor to the closest elevator
                printf("Elevator %d has been assigned.\n", closestElevator);
                pthread_mutex_lock(&mutex);
                destinationFloor[closestElevator] = fromFloor;
                elevatorStatus[closestElevator] = -1;
                pthread_mutex_unlock(&mutex);
                sleep(2);
                pthread_mutex_lock(&mutex);
                destinationFloor[closestElevator] = toFloor;
                if (toFloor > fromFloor) {
                    elevatorStatus[closestElevator] = 1;
                } else {
                    elevatorStatus[closestElevator] = -1;
                }
                pthread_mutex_unlock(&mutex);
            }
        } else if (option == 2) {
            exit(0);
        } else {
            printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}