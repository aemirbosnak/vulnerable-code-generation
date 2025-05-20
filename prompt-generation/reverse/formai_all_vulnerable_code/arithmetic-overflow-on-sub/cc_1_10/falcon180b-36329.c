//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 3
#define MAX_ROUTES 10

int routes[MAX_ROUTES][3]; // [latitude, longitude, distance]
int num_routes = 0;

pthread_t threads[NUM_THREADS];

void *thread_func(void *arg) {
    int thread_id = *((int *) arg);
    int start_index = thread_id * (MAX_ROUTES / NUM_THREADS);
    int end_index = (thread_id == NUM_THREADS - 1)? MAX_ROUTES - 1 : (thread_id + 1) * (MAX_ROUTES / NUM_THREADS) - 1;

    for (int i = start_index; i <= end_index; i++) {
        double distance = routes[i][2];
        double speed = 100; // km/h
        double time = distance / speed;

        printf("Thread %d: Route %d takes %.2f seconds to travel.\n", thread_id, i, time);

        sleep(time);
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < MAX_ROUTES; i++) {
        routes[i][0] = rand() % 180 - 90; // latitude [-90, 90]
        routes[i][1] = rand() % 360 - 180; // longitude [-180, 180]
        routes[i][2] = rand() % 1000 + 1; // distance [1, 1000] km

        printf("Route %d: (%d, %d) -> (%d, %d) [%d km]\n", i, routes[i][0], routes[i][1], routes[i][0] + 1, routes[i][1] + 1, routes[i][2]);

        num_routes++;
    }

    pthread_t thread_id[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&thread_id[i], NULL, thread_func, (void *) i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}