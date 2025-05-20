//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 2

typedef struct {
    int floor;
    int direction;
    sem_t mutex;
} elevator_t;

elevator_t elevators[NUM_ELEVATORS];

void *elevator_thread(void *arg) {
    elevator_t *elevator = (elevator_t *)arg;

    while (1) {
        sem_wait(&elevator->mutex);

        if (elevator->floor == 0 && elevator->direction == -1) {
            elevator->direction = 1;
        } else if (elevator->floor == NUM_FLOORS - 1 && elevator->direction == 1) {
            elevator->direction = -1;
        }

        elevator->floor += elevator->direction;

        sem_post(&elevator->mutex);

        sleep(1);
    }

    return NULL;
}

int main() {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].floor = 0;
        elevators[i].direction = 1;
        sem_init(&elevators[i].mutex, 0, 1);

        pthread_t thread;
        pthread_create(&thread, NULL, elevator_thread, &elevators[i]);
    }

    while (1) {
        int floor;
        printf("Enter floor (0-%d): ", NUM_FLOORS - 1);
        scanf("%d", &floor);

        if (floor < 0 || floor >= NUM_FLOORS) {
            printf("Invalid floor\n");
            continue;
        }

        int closest_elevator = -1;
        int min_distance = NUM_FLOORS;

        for (int i = 0; i < NUM_ELEVATORS; i++) {
            sem_wait(&elevators[i].mutex);

            int distance = abs(elevators[i].floor - floor);
            if (distance < min_distance) {
                closest_elevator = i;
                min_distance = distance;
            }

            sem_post(&elevators[i].mutex);
        }

        if (closest_elevator == -1) {
            printf("No elevators available\n");
            continue;
        }

        sem_wait(&elevators[closest_elevator].mutex);

        elevators[closest_elevator].direction = floor > elevators[closest_elevator].floor ? 1 : -1;

        sem_post(&elevators[closest_elevator].mutex);

        printf("Elevator %d is on its way to floor %d\n", closest_elevator, floor);
    }

    return 0;
}