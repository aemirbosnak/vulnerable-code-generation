#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define NUM_LIGHTS 4

typedef struct {
    int id;
    sem_t *mutex;
    sem_t *empty;
    sem_t *full;
} TrafficLight;

void* traffic_light(void* arg) {
    TrafficLight *light = (TrafficLight*)arg;
    while (1) {
        sem_wait(light->empty);
        sem_wait(light->mutex);

        // Simulate state change with timestamp
        time_t now = time(NULL);
        printf("Light %d changed at %s", light->id, ctime(&now));

        sem_post(light->mutex);
        sem_post(light->full);
    }
}

int main() {
    pthread_t threads[NUM_LIGHTS];
    TrafficLight lights[NUM_LIGHTS];

    sem_t mutex, empty, full;
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, NUM_LIGHTS);
    sem_init(&full, 0, 0);

    for (int i = 0; i < NUM_LIGHTS; i++) {
        lights[i].id = i + 1;
        lights[i].mutex = &mutex;
        lights[i].empty = &empty;
        lights[i].full = &full;
        pthread_create(&threads[i], NULL, traffic_light, &lights[i]);
    }

    for (int i = 0; i < NUM_LIGHTS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
