//Falcon-180B DATASET v1.0 Category: System event logger ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_EVENTS 1000
#define EVENT_BUFFER_SIZE 1024

typedef struct {
    char message[EVENT_BUFFER_SIZE];
    time_t timestamp;
} Event;

typedef struct {
    int front;
    int rear;
    Event events[MAX_EVENTS];
} EventQueue;

EventQueue *eventQueueCreate() {
    EventQueue *queue = (EventQueue *) malloc(sizeof(EventQueue));
    if (queue == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

int eventQueueIsEmpty(EventQueue *queue) {
    return (queue->front == queue->rear);
}

int eventQueueIsFull(EventQueue *queue) {
    return ((queue->rear + 1) % MAX_EVENTS == queue->front);
}

void eventQueueEnqueue(EventQueue *queue, char *message) {
    if (eventQueueIsFull(queue)) {
        printf("Error: Event queue is full\n");
        return;
    }
    strncpy(queue->events[++(queue->rear) % MAX_EVENTS].message, message, EVENT_BUFFER_SIZE - 1);
    queue->events[queue->rear].message[EVENT_BUFFER_SIZE - 1] = '\0';
    queue->events[queue->rear].timestamp = time(NULL);
}

Event *eventQueueDequeue(EventQueue *queue) {
    if (eventQueueIsEmpty(queue)) {
        return NULL;
    }
    return &(queue->events[queue->front++ % MAX_EVENTS]);
}

void *eventLogger(void *arg) {
    EventQueue *queue = (EventQueue *) arg;
    while (1) {
        Event *event = eventQueueDequeue(queue);
        if (event == NULL) {
            continue;
        }
        printf("%s - %s\n", ctime(&(event->timestamp)), event->message);
    }
}

int main() {
    EventQueue *eventQueue = eventQueueCreate();
    pthread_t loggerThread;
    int ret = pthread_create(&loggerThread, NULL, eventLogger, (void *) eventQueue);
    if (ret!= 0) {
        printf("Error: Unable to create thread, %d\n", ret);
        exit(1);
    }

    while (1) {
        char message[EVENT_BUFFER_SIZE];
        printf("Enter an event message: ");
        scanf("%s", message);
        eventQueueEnqueue(eventQueue, message);
    }

    return 0;
}