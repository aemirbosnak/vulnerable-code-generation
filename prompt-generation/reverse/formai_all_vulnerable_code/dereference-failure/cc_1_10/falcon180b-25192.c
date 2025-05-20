//Falcon-180B DATASET v1.0 Category: System event logger ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_EVENTS 100
#define EVENT_QUEUE_SIZE 10

typedef struct event {
    char message[100];
    time_t timestamp;
} Event;

typedef struct event_queue {
    Event events[EVENT_QUEUE_SIZE];
    int front;
    int rear;
} EventQueue;

EventQueue *create_event_queue() {
    EventQueue *queue = (EventQueue *)malloc(sizeof(EventQueue));
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

int is_full(EventQueue *queue) {
    return (queue->rear == EVENT_QUEUE_SIZE - 1);
}

int is_empty(EventQueue *queue) {
    return (queue->front == queue->rear);
}

void enqueue(EventQueue *queue, char *message) {
    if (is_full(queue)) {
        printf("Queue is full!\n");
        return;
    }

    if (is_empty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear++;
    }

    strcpy(queue->events[queue->rear].message, message);
    queue->events[queue->rear].timestamp = time(NULL);
}

Event dequeue(EventQueue *queue) {
    if (is_empty(queue)) {
        printf("Queue is empty!\n");
        return (Event){.message = "",.timestamp = 0 };
    }

    Event event = queue->events[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }

    return event;
}

void log_event(EventQueue *queue, char *message) {
    enqueue(queue, message);
}

void *event_logger(void *args) {
    EventQueue *queue = (EventQueue *)args;

    while (1) {
        Event event = dequeue(queue);
        printf("Event: %s, Timestamp: %ld\n", event.message, event.timestamp);
        sleep(1);
    }

    return NULL;
}

int main() {
    EventQueue *queue = create_event_queue();

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, event_logger, queue);

    char message[100];
    while (1) {
        printf("Enter event message: ");
        scanf("%s", message);
        log_event(queue, message);
        sleep(1);
    }

    return 0;
}