//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 5

// Struct to represent the state of the elevator
typedef struct Elevator {
    int current_floor;
    int target_floor;
    int capacity;
    int passengers;
    int is_moving;
    pthread_mutex_t mutex;
} Elevator;

// Declare the elevator object
Elevator elevator;

void *operate_elevator(void *arg) {
    while (1) {
        // Check if there's a target floor
        pthread_mutex_lock(&elevator.mutex);
        
        if (elevator.passengers == 0) {
            elevator.is_moving = 0; // If no passengers, stop
            pthread_mutex_unlock(&elevator.mutex);
            usleep(500000); // sleep for half a second
            continue;
        }

        if (elevator.current_floor < elevator.target_floor) {
            elevator.is_moving = 1;
            elevator.current_floor++;
        } 
        else if (elevator.current_floor > elevator.target_floor) {
            elevator.is_moving = 1;
            elevator.current_floor--;
        }

        if (elevator.current_floor == elevator.target_floor) {
            printf("Elevator arrived at floor %d.\n", elevator.current_floor);
            elevator.passengers = 0; // All passengers have exited
            elevator.is_moving = 0;
        }
        
        pthread_mutex_unlock(&elevator.mutex);
        usleep(100000); // sleep for a short moment
    }
    return NULL;
}

void request_elevator(int target_floor) {
    pthread_mutex_lock(&elevator.mutex);
    
    if (elevator.passengers < MAX_CAPACITY) {
        elevator.target_floor = target_floor;
        elevator.passengers++;
        printf("Elevator requested to floor %d. Current Passengers: %d\n", target_floor, elevator.passengers);
    } else {
        printf("Elevator is full. Cannot accept more passengers!\n");
    }
    
    pthread_mutex_unlock(&elevator.mutex);
}

void *user_interaction(void *arg) {
    int choice;
    
    while (1) {
        printf("Press a floor number (0-%d) to request elevator: ", MAX_FLOORS - 1);
        scanf("%d", &choice);
        
        if (choice < 0 || choice >= MAX_FLOORS) {
            printf("Invalid floor! Please choose a floor between 0 and %d.\n", MAX_FLOORS - 1);
            continue;
        }

        request_elevator(choice);
    }
    
    return NULL;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    elevator.current_floor = 0;
    elevator.target_floor = 0;
    elevator.passengers = 0;
    elevator.is_moving = 0;
    pthread_mutex_init(&elevator.mutex, NULL);

    pthread_t elevator_thread;
    pthread_t user_thread;

    // Start the elevator operation in a separate thread
    pthread_create(&elevator_thread, NULL, operate_elevator, NULL);
    // Start user interaction in another thread
    pthread_create(&user_thread, NULL, user_interaction, NULL);

    // Join threads (in this case, they will run indefinitely)
    pthread_join(elevator_thread, NULL);
    pthread_join(user_thread, NULL);

    // Cleanup
    pthread_mutex_destroy(&elevator.mutex);
    return 0;
}