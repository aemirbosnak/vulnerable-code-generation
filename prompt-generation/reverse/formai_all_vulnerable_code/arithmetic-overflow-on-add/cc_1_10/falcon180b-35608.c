//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_LIGHTS 3
#define MIN_DURATION 1
#define MAX_DURATION 10

struct light {
    int id;
    int duration;
    int current_duration;
    int state;
};

void *light_thread(void *arg) {
    struct light *light = (struct light *) arg;
    int i;

    for (i = 0; i < light->duration; i++) {
        printf("Light %d is on for %d seconds\n", light->id, light->current_duration);
        fflush(stdout);
        light->current_duration++;
        if (light->current_duration > light->duration) {
            light->current_duration = light->duration;
        }
        sleep(light->current_duration);
        printf("Light %d is off for %d seconds\n", light->id, light->current_duration);
        fflush(stdout);
        light->current_duration = 0;
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_LIGHTS];
    struct light lights[NUM_LIGHTS];
    int i;

    srand(time(NULL));

    for (i = 0; i < NUM_LIGHTS; i++) {
        lights[i].id = i + 1;
        lights[i].duration = rand() % (MAX_DURATION - MIN_DURATION + 1) + MIN_DURATION;
    }

    for (i = 0; i < NUM_LIGHTS; i++) {
        pthread_create(&threads[i], NULL, light_thread, &lights[i]);
    }

    for (i = 0; i < NUM_LIGHTS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}