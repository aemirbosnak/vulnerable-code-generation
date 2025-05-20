//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define MAX_REQUESTS 100

typedef struct {
    int floor;
    bool is_called;
} Elevator;

typedef struct {
    int requested_floors[MAX_REQUESTS];
    int request_count;
    pthread_mutex_t lock;
} RequestQueue;

Elevator elevator;
RequestQueue queue;

void* elevator_movement(void* arg) {
    while (true) {
        pthread_mutex_lock(&queue.lock);
        if (queue.request_count > 0) {
            int next_floor = queue.requested_floors[0];

            // Move to the requested floor
            printf("Elevator moving to floor: %d\n", next_floor);
            sleep(2);  // Simulating time taken to reach the floor
            printf("Elevator has arrived at floor: %d\n", next_floor);

            // Remove this request from the queue
            for (int i = 0; i < queue.request_count - 1; i++) {
                queue.requested_floors[i] = queue.requested_floors[i + 1];
            }
            queue.request_count--;
        }
        pthread_mutex_unlock(&queue.lock);
        sleep(1);  // Reduce CPU usage when idle
    }
    return NULL;
}

void request_elevator(int floor) {
    pthread_mutex_lock(&queue.lock);
    if (queue.request_count < MAX_REQUESTS) {
        queue.requested_floors[queue.request_count++] = floor;
        printf("Request to floor %d added to the queue.\n", floor);
    } else {
        printf("Request queue is full! Cannot add request to floor %d.\n", floor);
    }
    pthread_mutex_unlock(&queue.lock);
}

int main() {
    pthread_t elevator_thread;
    elevator.is_called = false;
    queue.request_count = 0;
    pthread_mutex_init(&queue.lock, NULL);

    // Start the elevator thread
    pthread_create(&elevator_thread, NULL, elevator_movement, NULL);

    int choice;
    while (true) {
        printf("\nElevator Simulation Menu:\n");
        printf("1. Request elevator to a specific floor (0-%d)\n", MAX_FLOORS - 1);
        printf("2. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int floor;
            printf("Enter the floor number (0-%d): ", MAX_FLOORS - 1);
            scanf("%d", &floor);
            if (floor >= 0 && floor < MAX_FLOORS) {
                request_elevator(floor);
            } else {
                printf("Invalid floor number! Please try again.\n");
            }
        } else if (choice == 2) {
            // Cleanup and exit
            break;
        } else {
            printf("Invalid selection! Please try again.\n");
        }
    }

    // Wait for the elevator thread to finish (it won't in this simulation)
    pthread_cancel(elevator_thread);
    pthread_join(elevator_thread, NULL);
    pthread_mutex_destroy(&queue.lock);
    
    return 0;
}