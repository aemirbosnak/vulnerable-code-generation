//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_LIGHTS 3
#define MAX_BRIGHTNESS 100
#define MIN_BRIGHTNESS 0

struct light {
    int brightness;
    int target_brightness;
    int id;
};

typedef struct light Light;

Light lights[NUM_LIGHTS];

void *light_thread(void *arg) {
    int id = *(int *) arg;
    Light *light = &lights[id];

    while (1) {
        if (light->target_brightness!= light->brightness) {
            if (light->target_brightness > light->brightness) {
                light->brightness += 1;
            } else {
                light->brightness -= 1;
            }
        }

        usleep(10000);
    }

    return NULL;
}

int main() {
    int i;

    for (i = 0; i < NUM_LIGHTS; i++) {
        lights[i].id = i;
        lights[i].brightness = MIN_BRIGHTNESS;
        lights[i].target_brightness = MIN_BRIGHTNESS;
    }

    int threads[NUM_LIGHTS];

    for (i = 0; i < NUM_LIGHTS; i++) {
        pthread_create(&threads[i], NULL, light_thread, &i);
    }

    for (i = 0; i < NUM_LIGHTS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}