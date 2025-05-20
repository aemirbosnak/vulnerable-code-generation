//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_EVENTS 100

typedef struct event {
    time_t timestamp;
    void (*func)(void *arg);
    void *arg;
} Event;

Event events[MAX_EVENTS];
int num_events = 0;

void add_event(time_t timestamp, void (*func)(void *), void *arg) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: Too many events\n");
        return;
    }
    events[num_events].timestamp = timestamp;
    events[num_events].func = func;
    events[num_events].arg = arg;
    num_events++;
}

void *event_loop(void *arg) {
    while (1) {
        sleep(1);
        time_t now = time(NULL);
        for (int i = 0; i < num_events; i++) {
            if (events[i].timestamp <= now) {
                events[i].func(events[i].arg);
                events[i] = events[num_events - 1];
                num_events--;
                break;
            }
        }
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    int num_threads = rand() % 10 + 1;
    pthread_t threads[num_threads];

    for (int i = 0; i < num_threads; i++) {
        add_event(time(NULL) + rand() % 10, (void *)i, NULL);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, event_loop, NULL);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}