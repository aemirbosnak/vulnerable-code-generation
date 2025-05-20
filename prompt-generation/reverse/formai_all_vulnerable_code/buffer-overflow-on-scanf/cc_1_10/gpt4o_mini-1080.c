//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_FLOORS 10
#define ELEVATOR_CAPACITY 5

typedef struct {
    int current_floor;
    int target_floor;
    int passengers[ELEVATOR_CAPACITY];
    int passenger_count;
    pthread_mutex_t lock;
    pthread_cond_t condition;
    int is_moving;
} Elevator;

void *elevator_function(void *arg) {
    Elevator *elevator = (Elevator *)arg;
    while (1) {
        pthread_mutex_lock(&elevator->lock);
        
        while (elevator->passenger_count == 0) {
            printf("Elevator is idle at floor %d.\n", elevator->current_floor);
            elevator->is_moving = 0;
            pthread_cond_wait(&elevator->condition, &elevator->lock);
        }

        elevator->is_moving = 1;
        printf("Elevator is moving from floor %d to floor %d.\n", elevator->current_floor, elevator->target_floor);

        // Simulate moving time based on floor difference
        int floors_to_move = abs(elevator->target_floor - elevator->current_floor);
        sleep(floors_to_move); // Mock moving time

        elevator->current_floor = elevator->target_floor;
        elevator->passenger_count = 0; // All passengers are gone after reaching target
        printf("Elevator has arrived at floor %d.\n", elevator->current_floor);
        
        pthread_mutex_unlock(&elevator->lock);
    }
}

void request_elevator(Elevator *elevator, int requested_floor) {
    pthread_mutex_lock(&elevator->lock);
    if (elevator->passenger_count < ELEVATOR_CAPACITY) {
        elevator->passengers[elevator->passenger_count++] = requested_floor;
        elevator->target_floor = requested_floor;
        printf("Passenger requested the elevator to floor %d.\n", requested_floor);
        pthread_cond_signal(&elevator->condition);
    } else {
        printf("Elevator is full! Cannot accommodate additional passengers.\n");
    }
    pthread_mutex_unlock(&elevator->lock);
}

int main() {
    Elevator elevator;
    elevator.current_floor = 0;
    elevator.target_floor = 0;
    elevator.passenger_count = 0;
    pthread_mutex_init(&elevator.lock, NULL);
    pthread_cond_init(&elevator.condition, NULL);
    elevator.is_moving = 0;

    pthread_t elevator_thread;
    pthread_create(&elevator_thread, NULL, elevator_function, (void *)&elevator);

    int choice;
    while (1) {
        printf("Choose a floor (0-%d) to request the elevator or -1 to exit: ", MAX_FLOORS - 1);
        scanf("%d", &choice);
        if (choice == -1) {
            break;
        }
        if (choice < 0 || choice >= MAX_FLOORS) {
            printf("Invalid floor selection. Please choose a valid floor.\n");
            continue;
        }
        request_elevator(&elevator, choice);
    }

    // Clean up and exit
    pthread_cancel(elevator_thread);
    pthread_join(elevator_thread, NULL);
    pthread_mutex_destroy(&elevator.lock);
    pthread_cond_destroy(&elevator.condition);
    printf("Elevator simulation ended.\n");

    return 0;
}