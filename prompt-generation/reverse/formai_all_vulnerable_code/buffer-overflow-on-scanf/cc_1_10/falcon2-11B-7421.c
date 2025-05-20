//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int num_floors = 10;
int current_floor = 0;
int next_floor = 0;
int num_passengers = 0;
int elevator_queue[100];
int elevator_queue_size = 0;
int elevator_up = 0;
int elevator_down = 0;
int elevator_floor = 0;
int elevator_destination = 0;
int elevator_busy = 0;
pthread_mutex_t elevator_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t elevator_cond = PTHREAD_COND_INITIALIZER;

void* elevator_thread(void* arg) {
    int id = *(int*)arg;
    while (1) {
        pthread_mutex_lock(&elevator_mutex);
        int next_move = 0;
        if (num_passengers > 0 && elevator_up == 0) {
            next_move = 1;
        } else if (num_passengers > 0 && elevator_down == 0) {
            next_move = 2;
        } else if (num_passengers > 0 && elevator_floor == 0) {
            next_move = 3;
        } else if (num_passengers > 0 && elevator_destination == 0) {
            next_move = 4;
        } else {
            pthread_cond_wait(&elevator_cond, &elevator_mutex);
            next_move = 0;
        }
        if (next_move!= 0) {
            if (next_move == 1) {
                elevator_up = 1;
                elevator_floor = num_floors;
            } else if (next_move == 2) {
                elevator_down = 1;
                elevator_floor = 0;
            } else if (next_move == 3) {
                elevator_floor = num_floors;
            } else if (next_move == 4) {
                elevator_destination = num_floors;
            }
            pthread_mutex_unlock(&elevator_mutex);
            pthread_mutex_lock(&elevator_mutex);
            if (elevator_up == 1) {
                elevator_up = 0;
                elevator_down = 0;
                elevator_destination = 0;
                elevator_busy = 0;
                printf("Going Up\n");
            } else if (elevator_down == 1) {
                elevator_down = 0;
                elevator_up = 0;
                elevator_destination = 0;
                elevator_busy = 0;
                printf("Going Down\n");
            } else if (elevator_floor == num_floors) {
                elevator_up = 0;
                elevator_down = 0;
                elevator_destination = 0;
                elevator_busy = 0;
                printf("Arrived at Destination Floor %d\n", elevator_floor);
            } else if (elevator_destination == num_floors) {
                elevator_up = 0;
                elevator_down = 0;
                elevator_destination = 0;
                elevator_busy = 0;
                printf("Arrived at Destination Floor %d\n", elevator_destination);
            } else {
                pthread_mutex_unlock(&elevator_mutex);
                pthread_cond_signal(&elevator_cond);
                pthread_mutex_lock(&elevator_mutex);
            }
        } else {
            pthread_mutex_unlock(&elevator_mutex);
            pthread_cond_wait(&elevator_cond, &elevator_mutex);
            pthread_mutex_lock(&elevator_mutex);
        }
    }
    return NULL;
}

void simulate() {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < num_floors; i++) {
        for (j = 0; j < num_passengers; j++) {
            elevator_queue[j] = i;
            pthread_mutex_lock(&elevator_mutex);
            elevator_queue_size++;
            if (rand() % 2 == 0) {
                elevator_up = 1;
                elevator_floor = i;
            } else {
                elevator_down = 1;
                elevator_floor = i;
            }
            pthread_mutex_unlock(&elevator_mutex);
            printf("Passenger %d wants to go to floor %d (up or down)\n", j, i);
            printf("Elevator at floor %d\n", elevator_floor);
            pthread_mutex_lock(&elevator_mutex);
            pthread_cond_broadcast(&elevator_cond);
            pthread_mutex_unlock(&elevator_mutex);
        }
    }
    pthread_mutex_lock(&elevator_mutex);
    elevator_queue_size = 0;
    pthread_mutex_unlock(&elevator_mutex);
    printf("Simulation is completed\n");
}

int main() {
    pthread_t elevator_thread1, elevator_thread2;
    int num_passengers = 0;
    while (1) {
        printf("Please enter the number of passengers: ");
        scanf("%d", &num_passengers);
        simulate();
        pthread_create(&elevator_thread1, NULL, elevator_thread, (void*)1);
        pthread_create(&elevator_thread2, NULL, elevator_thread, (void*)2);
        pthread_join(elevator_thread1, NULL);
        pthread_join(elevator_thread2, NULL);
    }
    return 0;
}