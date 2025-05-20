//Falcon-180B DATASET v1.0 Category: System event logger ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_EVENTS 1000
#define EVENT_SIZE 256

typedef struct {
    time_t timestamp;
    char message[EVENT_SIZE];
} Event;

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    Event events[MAX_EVENTS];
    int count;
} EventQueue;

void enqueue(EventQueue* queue, const char* message) {
    pthread_mutex_lock(&queue->mutex);

    if (queue->count == MAX_EVENTS) {
        fprintf(stderr, "Event queue is full\n");
        pthread_mutex_unlock(&queue->mutex);
        return;
    }

    Event event = {time(NULL), strncpy(event.message, message, EVENT_SIZE)};
    queue->events[queue->count++] = event;

    pthread_cond_signal(&queue->cond);
    pthread_mutex_unlock(&queue->mutex);
}

void dequeue(EventQueue* queue, char* message) {
    pthread_mutex_lock(&queue->mutex);

    while (queue->count == 0) {
        pthread_cond_wait(&queue->cond, &queue->mutex);
    }

    strncpy(message, queue->events[--queue->count].message, EVENT_SIZE);

    pthread_mutex_unlock(&queue->mutex);
}

void log_events(EventQueue* queue) {
    while (1) {
        pthread_mutex_lock(&queue->mutex);

        while (queue->count == 0) {
            pthread_cond_wait(&queue->cond, &queue->mutex);
        }

        fprintf(stdout, "Timestamp: %s\nMessage: %s\n", ctime(&queue->events[0].timestamp), queue->events[0].message);
        dequeue(queue, NULL);

        pthread_mutex_unlock(&queue->mutex);

        sleep(1);
    }
}

int main() {
    EventQueue queue = {PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER, {{0}}, 0};

    pthread_t logger_thread;
    pthread_create(&logger_thread, NULL, &log_events, &queue);

    while (1) {
        char message[EVENT_SIZE];
        scanf("%s", message);
        enqueue(&queue, message);
    }

    return 0;
}