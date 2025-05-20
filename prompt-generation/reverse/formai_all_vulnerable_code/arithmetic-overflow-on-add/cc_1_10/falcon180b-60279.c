//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 3
#define RED_TIME 10
#define GREEN_TIME 20
#define YELLOW_TIME 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *traffic_light(void *arg) {
    int id = *((int *) arg);
    char *light_state = "Red";
    time_t start_time, end_time;

    start_time = time(NULL);
    while (1) {
        pthread_mutex_lock(&mutex);
        if (id == 0) {
            printf("Light %d is %s\n", id, light_state);
        }
        pthread_mutex_unlock(&mutex);

        if (light_state == "Red") {
            end_time = start_time + RED_TIME;
        } else if (light_state == "Green") {
            end_time = start_time + GREEN_TIME;
        } else {
            end_time = start_time + YELLOW_TIME;
        }

        sleep(end_time - time(NULL));

        pthread_mutex_lock(&mutex);
        if (id == 0) {
            printf("Light %d changed to %s\n", id, light_state);
        }
        pthread_mutex_unlock(&mutex);

        if (light_state == "Red") {
            light_state = "Green";
        } else if (light_state == "Green") {
            light_state = "Yellow";
        } else {
            light_state = "Red";
        }
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS] = {0, 1, 2};

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, traffic_light, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}