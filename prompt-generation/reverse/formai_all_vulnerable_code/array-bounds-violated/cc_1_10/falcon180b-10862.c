//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_LIGHTS 3
#define GREEN_LIGHT 1
#define YELLOW_LIGHT 2
#define RED_LIGHT 3

#define LIGHT_CHANGE_DELAY 5
#define YELLOW_LIGHT_DELAY 2

int light_state[NUM_LIGHTS];
int light_change_time[NUM_LIGHTS];

void *traffic_light(void *arg) {
    int light_id = *(int*)arg;
    while (1) {
        switch (light_state[light_id]) {
            case GREEN_LIGHT:
                printf("Light %d is green\n", light_id);
                sleep(LIGHT_CHANGE_DELAY);
                light_state[light_id] = YELLOW_LIGHT;
                light_change_time[light_id] = time(NULL);
                break;
            case YELLOW_LIGHT:
                printf("Light %d is yellow\n", light_id);
                if (difftime(time(NULL), light_change_time[light_id]) >= YELLOW_LIGHT_DELAY) {
                    light_state[light_id] = RED_LIGHT;
                    light_change_time[light_id] = time(NULL);
                }
                break;
            case RED_LIGHT:
                printf("Light %d is red\n", light_id);
                sleep(LIGHT_CHANGE_DELAY);
                light_state[light_id] = GREEN_LIGHT;
                light_change_time[light_id] = time(NULL);
                break;
        }
    }
}

int main() {
    pthread_t threads[NUM_LIGHTS];
    int i;

    for (i = 0; i < NUM_LIGHTS; i++) {
        light_state[i] = GREEN_LIGHT;
        light_change_time[i] = time(NULL);
        pthread_create(&threads[i], NULL, traffic_light, (void*)i);
    }

    for (i = 0; i < NUM_LIGHTS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}