//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 5

typedef struct {
    int current_floor;
    int destination_floor;
    int passengers;
} Elevator;

sem_t elevator_sem;

void* elevator_movement(void* arg) {
    Elevator* elevator = (Elevator*)arg;
    
    while (1) {
        sem_wait(&elevator_sem);

        printf("Elevator at floor %d with %d passengers.\n", elevator->current_floor, elevator->passengers);

        if (elevator->passengers > 0) {
            // Move to destination floor
            printf("Elevator moving to floor %d...\n", elevator->destination_floor);
            while (elevator->current_floor < elevator->destination_floor) {
                elevator->current_floor++;
                sleep(1);
                printf("Elevator at floor %d...\n", elevator->current_floor);
            }
            while (elevator->current_floor > elevator->destination_floor) {
                elevator->current_floor--;
                sleep(1);
                printf("Elevator at floor %d...\n", elevator->current_floor);
            }

            printf("Elevator has arrived at floor %d. Passengers leaving...\n", elevator->current_floor);
            elevator->passengers = 0; // All passengers have left
        } else {
            printf("Elevator waiting for passengers...\n");
        }

        sem_post(&elevator_sem);
        sleep(2); // Wait before checking for new passengers
    }
}

void request_elevator(Elevator* elevator, int from_floor, int to_floor) {
    sem_wait(&elevator_sem);

    if (elevator->passengers < MAX_CAPACITY) {
        elevator->destination_floor = to_floor;
        elevator->passengers++;
        printf("Passenger requests elevator from floor %d to %d. Current passengers: %d\n", from_floor, to_floor, elevator->passengers);
    } else {
        printf("Elevator at capacity! Request denied.\n");
    }

    sem_post(&elevator_sem);
}

int main() {
    Elevator elevator = {0, -1, 0}; // Start at ground floor with no destination
    pthread_t elevator_thread;
    
    sem_init(&elevator_sem, 0, 1);

    pthread_create(&elevator_thread, NULL, elevator_movement, (void*)&elevator);

    while (1) {
        int from_floor, to_floor;

        printf("Enter the floor you are on (0 to %d): ", MAX_FLOORS - 1);
        scanf("%d", &from_floor);

        if (from_floor < 0 || from_floor >= MAX_FLOORS) {
            printf("Invalid floor! Exiting...\n");
            break;
        }

        printf("Enter your destination floor (0 to %d): ", MAX_FLOORS - 1);
        scanf("%d", &to_floor);

        if (to_floor < 0 || to_floor >= MAX_FLOORS || to_floor == from_floor) {
            printf("Invalid destination! Exiting...\n");
            break;
        }

        request_elevator(&elevator, from_floor, to_floor);
    }

    pthread_cancel(elevator_thread);
    pthread_join(elevator_thread, NULL);
    sem_destroy(&elevator_sem);

    printf("Elevator simulation ended.\n");
    return 0;
}