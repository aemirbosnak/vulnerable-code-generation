//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct Elevator {
    int current_floor;
    int requested_floor;
    bool moving_up;
    bool door_open;
} Elevator;

Elevator elevator = {0, -1, false, false};

void open_door() {
    elevator.door_open = true;
    printf("Elevator doors are now open.\n");
}

void close_door() {
    elevator.door_open = false;
    printf("Elevator doors are now closed.\n");
}

void move_elevator() {
    if (elevator.requested_floor == -1) {
        printf("No floor requested. Elevator is idle.\n");
        return;
    }

    printf("Moving from floor %d to floor %d...\n", elevator.current_floor, elevator.requested_floor);
    
    while (elevator.current_floor != elevator.requested_floor) {
        if (elevator.current_floor < elevator.requested_floor) {
            elevator.current_floor++;
            elevator.moving_up = true;
        } else {
            elevator.current_floor--;
            elevator.moving_up = false;
        }
        
        printf("Elevator at floor %d\n", elevator.current_floor);
        sleep(1); // Simulate time taken to move floor
    }
    
    printf("Arrived at floor %d\n", elevator.current_floor);
    open_door();
}

void request_floor(int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor request!\n");
        return;
    }
    
    if (elevator.door_open) {
        close_door();
    }
    
    elevator.requested_floor = floor;
    move_elevator();
}

void *elevator_thread(void *arg) {
    while (true) {
        if (elevator.requested_floor != -1) {
            move_elevator();
            elevator.requested_floor = -1; // Reset after serving request
        }
        sleep(1); // Prevent busy waiting
    }
}

int main() {
    pthread_t thread_id;
    
    // Create a thread for the elevator operation
    pthread_create(&thread_id, NULL, elevator_thread, NULL);
    
    int requested_floor = -1;
    
    while (true) {
        printf("Enter the floor number to request (0-%d) or -1 to exit: ", MAX_FLOORS - 1);
        scanf("%d", &requested_floor);
        
        if (requested_floor == -1) {
            printf("Exiting the elevator simulation. Goodbye!\n");
            break;
        }
        
        request_floor(requested_floor);
    }
    
    pthread_cancel(thread_id);
    pthread_join(thread_id, NULL);

    return 0;
}