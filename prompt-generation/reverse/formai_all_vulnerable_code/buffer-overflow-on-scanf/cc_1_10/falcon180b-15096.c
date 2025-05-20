//Falcon-180B DATASET v1.0 Category: System event logger ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_EVENTS 1000
#define MAX_EVENT_LENGTH 200

typedef struct {
    char message[MAX_EVENT_LENGTH];
    time_t timestamp;
} Event;

typedef struct {
    Event events[MAX_EVENTS];
    int front;
    int rear;
} EventQueue;

EventQueue *eventQueueCreate() {
    EventQueue *queue = (EventQueue *)malloc(sizeof(EventQueue));
    if(queue == NULL) {
        printf("Error creating event queue\n");
        exit(1);
    }
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

int eventQueueIsEmpty(EventQueue *queue) {
    if(queue->front == -1)
        return 1;
    else
        return 0;
}

int eventQueueIsFull(EventQueue *queue) {
    if((queue->rear + 1) % MAX_EVENTS == queue->front)
        return 1;
    else
        return 0;
}

void eventQueueEnqueue(EventQueue *queue, char *message) {
    strncpy(queue->events[++queue->rear % MAX_EVENTS].message, message, MAX_EVENT_LENGTH);
    queue->events[queue->rear % MAX_EVENTS].timestamp = time(NULL);
    if(eventQueueIsEmpty(queue))
        queue->front = 0;
    printf("Event added to queue: %s\n", message);
}

void eventQueueDequeue(EventQueue *queue) {
    if(eventQueueIsEmpty(queue))
        printf("Queue is empty\n");
    else if(eventQueueIsFull(queue)) {
        printf("Queue is full\n");
        eventQueueDequeue(queue);
    }
    printf("Event removed from queue: %s\n", queue->events[queue->front % MAX_EVENTS].message);
    queue->front = (queue->front + 1) % MAX_EVENTS;
}

void eventLogger(void *param) {
    EventQueue *queue = (EventQueue *)param;
    while(1) {
        sleep(1);
        if(!eventQueueIsEmpty(queue)) {
            eventQueueDequeue(queue);
        }
    }
}

int main() {
    EventQueue *queue = eventQueueCreate();
    pthread_t threadId;
    pthread_create(&threadId, NULL, eventLogger, (void *)queue);

    while(1) {
        char message[MAX_EVENT_LENGTH];
        printf("Enter event message: ");
        scanf("%s", message);
        eventQueueEnqueue(queue, message);
    }

    return 0;
}