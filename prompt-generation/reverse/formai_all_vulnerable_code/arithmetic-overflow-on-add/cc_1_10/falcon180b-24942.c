//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_EVENTS 5

struct Event {
    time_t time;
    char *description;
};

void *time_travel(void *args) {
    struct Event *events = args;
    int i;

    for (i = 0; i < NUM_EVENTS; i++) {
        sleep(events[i].time - time(NULL));
        printf("Traveling back to %s...\n", events[i].description);
    }

    return NULL;
}

int main() {
    struct Event events[NUM_EVENTS] = {
        { time(NULL) + 5, "5 seconds ago" },
        { time(NULL) + 60, "1 minute ago" },
        { time(NULL) + 300, "5 minutes ago" },
        { time(NULL) - 60, "1 minute into the future" },
        { time(NULL) - 300, "5 minutes into the future" }
    };

    pthread_t threads[NUM_EVENTS];
    sem_t mutex;

    sem_init(&mutex, 0, 1);

    int i;
    for (i = 0; i < NUM_EVENTS; i++) {
        pthread_create(&threads[i], NULL, time_travel, &events[i]);
        sem_wait(&mutex);
    }

    for (i = 0; i < NUM_EVENTS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&mutex);

    return 0;
}