//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>

#define MAX_FLOOR 10
#define MAX_ELEVATOR 3
#define MAX_PASSENGER 20

pthread_mutex_t mutex_lock;
pthread_cond_t cond;
pthread_t elevator[MAX_ELEVATOR];

int elevator_position[MAX_ELEVATOR];
int passenger_position[MAX_PASSENGER];
bool elevator_direction[MAX_ELEVATOR];
bool elevator_state[MAX_ELEVATOR];
bool passenger_state[MAX_PASSENGER];

void *elevator_thread(void *eid) {
    int elevator_id = *((int *) eid);
    while (true) {
        pthread_mutex_lock(&mutex_lock);
        while (!elevator_state[elevator_id]) {
            pthread_cond_wait(&cond, &mutex_lock);
        }

        int p_count = 0;
        for (int i = 0; i < MAX_PASSENGER; i++) {
            if (passenger_state[i] && passenger_position[i] == elevator_position[elevator_id]) {
                p_count++;
                if (p_count > 5) {
                    break;
                }
                printf("Elevator - %d: Passenger - %d entered\n", elevator_id, i);
                passenger_state[i] = false;
            }
        }

        elevator_direction[elevator_id] = (rand() % 2 == 0);
        if (elevator_direction[elevator_id]) {
            elevator_position[elevator_id]++;
        } else {
            elevator_position[elevator_id]--;
        }
        printf("Elevator - %d: currently at - %d\n", elevator_id, elevator_position[elevator_id]);

        int current_floor = elevator_position[elevator_id];
        if (elevator_direction[elevator_id]) {
            for (int i = 0; i < MAX_PASSENGER; i++) {
                if (passenger_state[i] && passenger_position[i] > current_floor && p_count < 5) {
                    passenger_position[i] = current_floor;
                    p_count++;
                    printf("Elevator - %d: Passenger - %d entered\n", elevator_id, i);
                    passenger_state[i] = false;
                }
            }
        } else {
            for (int i = 0; i < MAX_PASSENGER; i++) {
                if (passenger_state[i] && passenger_position[i] < current_floor && p_count < 5) {
                    passenger_position[i] = current_floor;
                    p_count++;
                    printf("Elevator - %d: Passenger - %d entered\n", elevator_id, i);
                    passenger_state[i] = false;
                }
            }
        }

        if (elevator_position[elevator_id] == MAX_FLOOR || elevator_position[elevator_id] == 1) {
            elevator_direction[elevator_id] = !elevator_direction[elevator_id];
        }

        pthread_mutex_unlock(&mutex_lock);
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_mutex_init(&mutex_lock, NULL);
    pthread_cond_init(&cond, NULL);

    for (int i = 0; i < MAX_ELEVATOR; i++) {
        int *elevator_id = (int *) malloc(sizeof(int));
        *elevator_id = i;
        elevator_position[i] = rand() % MAX_FLOOR + 1;
        elevator_direction[i] = rand() % 2 == 0;
        elevator_state[i] = true;
        pthread_create(&elevator[i], NULL, elevator_thread, (void *) elevator_id);
    }

    for (int i = 0; i < MAX_PASSENGER; i++) {
        passenger_position[i] = rand() % MAX_FLOOR + 1;
        passenger_state[i] = true;
    }

    while (true) {
        pthread_mutex_lock(&mutex_lock);

        for (int i = 0; i < MAX_ELEVATOR; i++) {
            if (rand() % 2 == 0) {
                elevator_state[i] = !elevator_state[i];
                if (elevator_state[i]) {
                    pthread_cond_signal(&cond);
                }
            }
        }

        pthread_mutex_unlock(&mutex_lock);
        usleep(1000000);
    }

    pthread_mutex_destroy(&mutex_lock);
    pthread_cond_destroy(&cond);
}