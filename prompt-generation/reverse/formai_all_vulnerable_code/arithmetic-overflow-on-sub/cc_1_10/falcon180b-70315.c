//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <semaphore.h>

#define RED_LIGHT 1
#define YELLOW_LIGHT 2
#define GREEN_LIGHT 3

#define LIGHT_DURATION 5
#define PEDESTRIAN_LIGHT_DURATION 15
#define TOTAL_LIGHTS 3

int main() {
    // Initialize semaphores
    sem_t traffic_lights[TOTAL_LIGHTS];
    for (int i = 0; i < TOTAL_LIGHTS; i++) {
        sem_init(&traffic_lights[i], 0, 0);
    }

    // Initialize timers
    struct timespec light_duration = {.tv_sec = LIGHT_DURATION,.tv_nsec = 0 };
    struct timespec pedestrian_light_duration = {.tv_sec = PEDESTRIAN_LIGHT_DURATION,.tv_nsec = 0 };

    // Set initial light to red
    sem_post(&traffic_lights[RED_LIGHT]);

    while (1) {
        sleep(light_duration.tv_sec);

        // Switch to yellow light
        sem_wait(&traffic_lights[RED_LIGHT]);
        sem_post(&traffic_lights[YELLOW_LIGHT]);
        sleep(light_duration.tv_sec);

        // Switch to green light
        sem_wait(&traffic_lights[YELLOW_LIGHT]);
        sem_post(&traffic_lights[GREEN_LIGHT]);
        sleep(light_duration.tv_sec);

        // Switch to red light
        sem_wait(&traffic_lights[GREEN_LIGHT]);
        sem_post(&traffic_lights[RED_LIGHT]);
        sleep(light_duration.tv_sec);

        // Switch to pedestrian light
        sem_wait(&traffic_lights[RED_LIGHT]);
        sem_post(&traffic_lights[YELLOW_LIGHT]);
        sem_wait(&traffic_lights[YELLOW_LIGHT]);
        sem_post(&traffic_lights[GREEN_LIGHT]);
        sleep(pedestrian_light_duration.tv_sec);

        // Switch back to red light
        sem_wait(&traffic_lights[GREEN_LIGHT]);
        sem_post(&traffic_lights[RED_LIGHT]);
        sleep(light_duration.tv_sec);
    }

    return 0;
}