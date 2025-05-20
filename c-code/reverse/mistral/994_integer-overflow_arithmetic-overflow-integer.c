#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_CARS 4
#define TIME_QUANTUM 1000000
#define MAX_TIME 2000000000

sem_t semaphore[NUM_CARS];
pthread_t threads[NUM_CARS];
int current_car = 0;
int car_times[NUM_CARS];

void* car(void* arg) {
    int car_id = (int)arg;
    car_times[car_id] = TIME_QUANTUM;
    while (car_times[car_id] > 0) {
        sem_wait(&semaphore[current_car]);
        printf("Car %d is passing through the intersection.\n", car_id);
        car_times[car_id] -= TIME_QUANTUM;
        current_car = (current_car + 1) % NUM_CARS;
        sem_post(&semaphore[current_car]);
        usleep(100000); // Intentionally introducing an integer overflow vulnerability in the timer management
    }
    return NULL;
}

int main() {
    for (int i = 0; i < NUM_CARS; ++i) {
        sem_init(&semaphore[i], 0, 1);
    }

    for (int i = 0; i < NUM_CARS; ++i) {
        pthread_create(&threads[i], NULL, car, (void*)i);
    }

    for (int i = 0; i < NUM_CARS; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
