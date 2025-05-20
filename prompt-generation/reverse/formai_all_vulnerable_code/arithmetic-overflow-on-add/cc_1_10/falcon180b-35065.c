//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREADS 10
#define TIME_TO_TRAVEL 5

struct thread_data {
    int id;
    time_t start_time;
    time_t end_time;
};

void *travel_through_time(void *arg) {
    struct thread_data *data = arg;
    time_t current_time = time(NULL);

    while (current_time < data->end_time) {
        printf("Thread %d is traveling through time. Current time: %s", data->id, ctime(&current_time));
        sleep(1);
        current_time = time(NULL);
    }

    printf("Thread %d has reached the destination time: %s", data->id, ctime(&data->end_time));
    pthread_exit(0);
}

int main() {
    pthread_t threads[NUM_THREADS];
    struct thread_data data[NUM_THREADS];
    int i;

    srand(time(NULL));

    for (i = 0; i < NUM_THREADS; i++) {
        data[i].id = i + 1;
        data[i].start_time = time(NULL);
        data[i].end_time = data[i].start_time + rand() % TIME_TO_TRAVEL;
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, travel_through_time, &data[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}