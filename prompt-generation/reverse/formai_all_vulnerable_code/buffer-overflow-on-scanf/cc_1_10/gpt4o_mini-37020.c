//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_FLOORS 10

typedef struct {
    int current_floor;
    int desired_floor;
    bool moving_up;
    bool running;
} Elevator;

Elevator elevator;

pthread_mutex_t lock;

void* elevator_controller(void* arg) {
    while (elevator.running) {
        pthread_mutex_lock(&lock);
        
        if (elevator.current_floor < elevator.desired_floor) {
            elevator.moving_up = true;
            elevator.current_floor++;
        } else if (elevator.current_floor > elevator.desired_floor) {
            elevator.moving_up = false;
            elevator.current_floor--;
        } else {
            elevator.moving_up = false;
            printf("Elevator has arrived at Floor %d\n", elevator.current_floor);
            elevator.desired_floor = -1; // Reset desired floor
        }

        pthread_mutex_unlock(&lock);
        sleep(1); // Mimic the elevator movement time
    }
    return NULL;
}

void request_floor(int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor requested!\n");
    } else {
        pthread_mutex_lock(&lock);
        
        if (elevator.desired_floor == -1) {
            elevator.desired_floor = floor;
            printf("Floor %d requested\n", floor);
        } else {
            printf("Elevator is busy. Please wait!\n");
        }

        pthread_mutex_unlock(&lock);
    }
}

void print_instructions() {
    printf("Elevator Control System\n");
    printf("Enter a floor number (0-%d) to request the elevator or -1 to exit:\n", MAX_FLOORS - 1);
}

int main() {
    elevator.current_floor = 0;
    elevator.desired_floor = -1; // No desired floor initially
    elevator.moving_up = true;
    elevator.running = true;

    pthread_t elevator_thread;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&elevator_thread, NULL, elevator_controller, NULL);

    int requested_floor = 0;
    while (true) {
        print_instructions();
        scanf("%d", &requested_floor);

        if (requested_floor == -1) {
            printf("Exiting elevator simulation...\n");
            break;
        }

        request_floor(requested_floor);
    }

    elevator.running = false; // Stop the elevator
    pthread_join(elevator_thread, NULL);
    
    pthread_mutex_destroy(&lock);
    return 0;
}