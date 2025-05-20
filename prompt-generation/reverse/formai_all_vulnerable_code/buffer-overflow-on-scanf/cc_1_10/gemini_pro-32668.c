//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_FLOORS 10
#define MAX_ELEVATORS 4

typedef struct {
    int current_floor;
    int destination_floor;
    bool up_direction;
} Elevator;

Elevator elevators[MAX_ELEVATORS];

sem_t mutex;
sem_t elevator_sems[MAX_ELEVATORS];

void initialize_elevators() {
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        elevators[i].current_floor = 0;
        elevators[i].destination_floor = -1;
        elevators[i].up_direction = true;
        sem_init(&elevator_sems[i], 0, 1);
    }
}

void *elevator_thread(void *arg) {
    int elevator_id = *(int *)arg;

    while (true) {
        sem_wait(&mutex);
        if (elevators[elevator_id].destination_floor == -1) {
            sem_post(&mutex);
            continue;
        }

        if (elevators[elevator_id].current_floor == elevators[elevator_id].destination_floor) {
            elevators[elevator_id].destination_floor = -1;
            sem_post(&mutex);
            continue;
        }

        if (elevators[elevator_id].up_direction) {
            elevators[elevator_id].current_floor++;
        } else {
            elevators[elevator_id].current_floor--;
        }

        sem_post(&mutex);
    }

    return NULL;
}

void request_elevator(int from_floor, int to_floor) {
    int elevator_id = -1;
    int min_distance = MAX_FLOORS;

    sem_wait(&mutex);
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        int distance = abs(elevators[i].current_floor - from_floor);
        if (distance < min_distance && elevators[i].destination_floor == -1) {
            min_distance = distance;
            elevator_id = i;
        }
    }

    if (elevator_id == -1) {
        for (int i = 0; i < MAX_ELEVATORS; i++) {
            int distance = abs(elevators[i].current_floor - from_floor);
            if (distance < min_distance) {
                min_distance = distance;
                elevator_id = i;
            }
        }
    }

    elevators[elevator_id].destination_floor = to_floor;
    elevators[elevator_id].up_direction = to_floor > from_floor;
    sem_post(&mutex);

    sem_wait(&elevator_sems[elevator_id]);
    sem_post(&elevator_sems[elevator_id]);
}

int main() {
    initialize_elevators();

    pthread_t elevator_threads[MAX_ELEVATORS];
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        pthread_create(&elevator_threads[i], NULL, elevator_thread, &i);
    }

    while (true) {
        int from_floor, to_floor;
        printf("Enter from floor: ");
        scanf("%d", &from_floor);
        printf("Enter to floor: ");
        scanf("%d", &to_floor);

        request_elevator(from_floor, to_floor);
    }

    for (int i = 0; i < MAX_ELEVATORS; i++) {
        pthread_join(elevator_threads[i], NULL);
    }

    return 0;
}