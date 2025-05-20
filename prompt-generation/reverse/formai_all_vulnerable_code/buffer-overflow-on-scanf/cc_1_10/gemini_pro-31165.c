//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_FLOORS      10
#define NUM_ELEVATORS    2

struct Elevator {
    int current_floor;
    int direction;
    sem_t semaphore;
};

struct Person {
    int start_floor;
    int end_floor;
};

void *elevator_thread(void *arg) {
    struct Elevator *elevator = (struct Elevator *)arg;

    while (1) {
        // Wait for someone to press the elevator button.
        sem_wait(&elevator->semaphore);

        // Pick up the person.
        struct Person person;
        scanf("%d %d", &person.start_floor, &person.end_floor);

        // Move the elevator to the person's starting floor.
        while (elevator->current_floor != person.start_floor) {
            if (elevator->current_floor < person.start_floor) {
                elevator->current_floor++;
            } else {
                elevator->current_floor--;
            }
        }

        // Pick up the person.
        printf("Elevator %d is picking up a person on floor %d.\n", elevator->current_floor, person.start_floor);

        // Move the elevator to the person's ending floor.
        while (elevator->current_floor != person.end_floor) {
            if (elevator->current_floor < person.end_floor) {
                elevator->current_floor++;
            } else {
                elevator->current_floor--;
            }
        }

        // Drop off the person.
        printf("Elevator %d is dropping off a person on floor %d.\n", elevator->current_floor, person.end_floor);
    }

    return NULL;
}

int main() {
    // Create the elevators.
    struct Elevator elevators[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].current_floor = 0;
        elevators[i].direction = 1;
        sem_init(&elevators[i].semaphore, 0, 0);
    }

    // Create the elevator threads.
    pthread_t elevator_threads[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        pthread_create(&elevator_threads[i], NULL, elevator_thread, &elevators[i]);
    }

    // Wait for the elevator threads to finish.
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        pthread_join(elevator_threads[i], NULL);
    }

    return 0;
}