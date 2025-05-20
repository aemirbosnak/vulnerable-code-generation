//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_FLOORS 10
#define ELEVATOR_CAPACITY 5

typedef struct {
    int current_floor;
    int requested_floors[MAX_FLOORS];
    int request_count;
    int passenger_count;
    int operation;
    pthread_mutex_t lock;
    pthread_cond_t cond;
} Elevator;

Elevator elevator;

void* elevator_operation(void* arg) {
    while (1) {
        pthread_mutex_lock(&elevator.lock);
        
        // Wait if there are no requests
        while (elevator.request_count == 0) {
            pthread_cond_wait(&elevator.cond, &elevator.lock);
        }

        // Move the elevator
        for (int i = 0; i < MAX_FLOORS; i++) {
            if (elevator.requested_floors[i] > 0) {
                printf("Elevator moving to floor %d...\n", i + 1);
                elevator.current_floor = i + 1;
                sleep(1); // Simulate time taken to move
                
                // Handle passengers on the floor
                int count = elevator.requested_floors[i];
                printf("Stopping at floor %d to drop off %d passengers.\n", i + 1, count);
                elevator.passenger_count -= count;
                elevator.requested_floors[i] = 0; // Reset the floor request
                elevator.request_count--;
            }
        }

        pthread_mutex_unlock(&elevator.lock);
    }
    return NULL;
}

void request_floor(int floor) {
    pthread_mutex_lock(&elevator.lock);
    
    if (elevator.passenger_count < ELEVATOR_CAPACITY) {
        elevator.requested_floors[floor - 1]++;
        elevator.passenger_count++;
        elevator.request_count++;
        printf("Passenger requested floor %d. Total passengers: %d\n", floor, elevator.passenger_count);
        pthread_cond_signal(&elevator.cond); // Wake the elevator if it's idle
    } else {
        printf("Elevator is at full capacity! Cannot request floor %d.\n", floor);
    }

    pthread_mutex_unlock(&elevator.lock);
}

void simulate_passenger_requests() {
    int floor;
    while (1) {
        printf("Enter floor to request (1-%d, 0 to exit): ", MAX_FLOORS);
        scanf("%d", &floor);
        if (floor == 0) break;
        if (floor < 1 || floor > MAX_FLOORS) {
            printf("Invalid floor. Please try again.\n");
            continue;
        }
        request_floor(floor);
    }
}

int main() {
    elevator.current_floor = 1;
    elevator.request_count = 0;
    elevator.passenger_count = 0;
    
    pthread_mutex_init(&elevator.lock, NULL);
    pthread_cond_init(&elevator.cond, NULL);

    pthread_t elevator_thread;
    pthread_create(&elevator_thread, NULL, elevator_operation, NULL);

    simulate_passenger_requests();

    // Cleanup
    pthread_cancel(elevator_thread);
    pthread_join(elevator_thread, NULL);
    pthread_mutex_destroy(&elevator.lock);
    pthread_cond_destroy(&elevator.cond);

    printf("Elevator simulation ended.\n");
    return 0;
}