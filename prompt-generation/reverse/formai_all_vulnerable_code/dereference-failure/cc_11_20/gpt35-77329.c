//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_FLOOR 10        // Maximum number of floors in the building
#define MAX_PASSENGERS 10   // Maximum number of passengers that can fit in an elevator
#define MAX_CAPACITY 100    // Maximum capacity of the building

int currentFloor = 0;       // Current floor where the elevator is located
enum { UP, DOWN } direction = UP;    // Direction of the elevator
int numPassengers = 0;      // Number of passengers in the elevator
int maxFloor = 0;           // Highest floor that the elevator has to visit
int minFloor = MAX_FLOOR+1; // Lowest floor that the elevator has to visit
int floors[MAX_FLOOR+1];    // An array to keep track of how many passengers are waiting on each floor
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;   // Mutex for accessing shared variables
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;        // Condition variable for signalling events

// Function to simulate a passenger waiting on a floor
void *passenger(void *arg) {
    int *floor = (int *)arg;
    
    // Wait for the elevator to arrive on the correct floor
    pthread_mutex_lock(&mutex);
    while (currentFloor != *floor) {
        pthread_cond_wait(&cv, &mutex);
    }
    
    // Get in the elevator
    numPassengers++;
    floors[*floor]--;
    printf("Passenger entered elevator on floor %d\n", *floor);
    
    // Signal the elevator if it needs to change direction
    if (numPassengers == 1) {
        if (direction == UP && currentFloor == maxFloor) {
            direction = DOWN;
            printf("Elevator changed direction to DOWN\n");
        }
        else if (direction == DOWN && currentFloor == minFloor) {
            direction = UP;
            printf("Elevator changed direction to UP\n");
        }
        pthread_cond_signal(&cv);
    }
    
    pthread_mutex_unlock(&mutex);
    return NULL;
}

// Function to simulate the elevator
void *elevator(void *arg) {
    // Randomly generate how many floors the passengers need to go to
    for (int i = 1; i <= MAX_FLOOR; i++) {
        floors[i] = rand() % MAX_PASSENGERS;
        if (floors[i] > 0) {
            // Update the highest and lowest floors as necessary
            if (i > maxFloor) {
                maxFloor = i;
            }
            if (i < minFloor) {
                minFloor = i;
            }
        }
    }

    while (1) {
        // Wait for passengers to arrive
        pthread_mutex_lock(&mutex);
        while (numPassengers == 0 && (floors[currentFloor] == 0 || (direction == UP && currentFloor == maxFloor) || (direction == DOWN && currentFloor == minFloor))) {
            pthread_cond_wait(&cv, &mutex);
        }

        // Move the elevator to the next floor
        if (direction == UP) {
            currentFloor++;
        }
        else {
            currentFloor--;
        }
        printf("Elevator arrived on floor %d\n", currentFloor);

        // Let passengers off the elevator
        if (numPassengers > 0 && floors[currentFloor] > 0) {
            int numExited = 0;
            while (numExited < floors[currentFloor] && numPassengers > 0) {
                numPassengers--;
                numExited++;
                printf("Passenger exited elevator on floor %d\n", currentFloor);
            }
            floors[currentFloor] -= numExited;
        }

        // Let passengers on the elevator if there is room and they are going in the correct direction
        if (numPassengers < MAX_PASSENGERS) {
            while (numPassengers < MAX_PASSENGERS && floors[currentFloor] > 0 && ((direction == UP && currentFloor < maxFloor) || (direction == DOWN && currentFloor > minFloor))) {
                numPassengers++;
                floors[currentFloor]--;
                printf("Passenger entered elevator on floor %d\n", currentFloor);

                // Update the highest and lowest floors as necessary
                if (currentFloor > maxFloor) {
                    maxFloor = currentFloor;
                }
                if (currentFloor < minFloor) {
                    minFloor = currentFloor;
                }
            }
        }

        // Change direction if necessary and no more passengers are waiting
        if (floors[currentFloor] == 0) {
            if (direction == UP && currentFloor == maxFloor) {
                direction = DOWN;
                printf("Elevator changed direction to DOWN\n");
            }
            else if (direction == DOWN && currentFloor == minFloor) {
                direction = UP;
                printf("Elevator changed direction to UP\n");
            }
        }
        
        // Signal any waiting passengers or the elevator itself
        pthread_cond_broadcast(&cv);
        pthread_mutex_unlock(&mutex);
        usleep(1000000);    // Wait 1 second between iterations
    }
}

int main() {
    // Create the elevator and passenger threads
    pthread_t elev, p[MAX_CAPACITY];
    pthread_create(&elev, NULL, elevator, NULL);
    
    // Randomly generate how many passengers will try to enter the building
    int numPassengers = rand() % MAX_CAPACITY;
    for (int i = 0; i < numPassengers; i++) {
        // Randomly generate which floor the passenger is on
        int *floor = (int *)malloc(sizeof(int));
        *floor = rand() % MAX_FLOOR + 1;
        pthread_create(&p[i], NULL, passenger, floor);
    }

    // Wait for the elevator and passenger threads to finish
    pthread_join(elev, NULL);
    for (int i = 0; i < numPassengers; i++) {
        pthread_join(p[i], NULL);
    }
    
    return 0;
}