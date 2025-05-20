//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define FLOORS 10
#define ELEVATORS 3

typedef struct {
    int curr_floor;
    int target_floor;
    bool moving_up;
    bool in_use;
} elevator_t;

elevator_t elevators[ELEVATORS];

void *elevator_thread(void *arg) {
    int *elevator_num = (int *) arg;
    elevator_t *elevator = &elevators[*elevator_num];

    while (true) {
        // Wait for a request to be made
        while (!elevator->in_use) {
            continue;
        }

        // Move the elevator towards the target floor
        while (elevator->curr_floor != elevator->target_floor) {
            if (elevator->moving_up) {
                elevator->curr_floor++;
            }
            else {
                elevator->curr_floor--;
            }

            printf("Elevator %d moving to floor %d\n", *elevator_num, elevator->curr_floor);
        }

        // Open the doors and wait for riders to enter/exit
        printf("Elevator %d arrived at floor %d\n", *elevator_num, elevator->curr_floor);
        // TODO: Code to open doors and allow riders to enter/exit

        // Mark the elevator as available again
        elevator->in_use = false;
    }

    pthread_exit(NULL);
}

int get_available_elevator() {
    // Find an available elevator
    for (int i = 0; i < ELEVATORS; i++) {
        if (!elevators[i].in_use) {
            return i;
        }
    }

    // If no elevator is available, just use the first one
    return 0;
}

int main() {
    // Initialize elevators
    for (int i = 0; i < ELEVATORS; i++) {
        elevators[i].curr_floor = 1;
        elevators[i].target_floor = 1;
        elevators[i].moving_up = true;
        elevators[i].in_use = false;
    }

    // Create threads for each elevator
    pthread_t thread_ids[ELEVATORS];
    int thread_args[ELEVATORS];

    for (int i = 0; i < ELEVATORS; i++) {
        thread_args[i] = i;
        pthread_create(&thread_ids[i], NULL, elevator_thread, &thread_args[i]);
        pthread_detach(thread_ids[i]);
    }

    // Main loop to handle elevator requests
    int rider_target_floor;

    while (true) {
        printf("Enter target floor [1-%d]: ", FLOORS);
        scanf("%d", &rider_target_floor);

        if (rider_target_floor < 1 || rider_target_floor > FLOORS) {
            printf("Invalid floor\n");
            continue;
        }

        // Request an elevator
        int elevator_num = get_available_elevator();
        elevator_t *elevator = &elevators[elevator_num];

        elevator->target_floor = rider_target_floor;
        elevator->in_use = true;
        elevator->moving_up = (elevator->target_floor > elevator->curr_floor);
    }

    return 0;
}