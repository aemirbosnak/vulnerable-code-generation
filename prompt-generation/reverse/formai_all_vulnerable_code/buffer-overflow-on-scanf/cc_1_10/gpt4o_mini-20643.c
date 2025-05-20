//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_FLOORS 5
#define MAX_REQUESTS 10

typedef struct {
    int floor;
    int direction; // 1 for up, -1 for down
} Request;

typedef struct {
    Request requests[MAX_REQUESTS];
    int front;
    int rear;
    int size;
    pthread_mutex_t lock;
} RequestQueue;

RequestQueue queue;

void initQueue(RequestQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    pthread_mutex_init(&q->lock, NULL);
}

bool isFull(RequestQueue *q) {
    return q->size == MAX_REQUESTS;
}

bool isEmpty(RequestQueue *q) {
    return q->size == 0;
}

void enqueue(RequestQueue *q, Request request) {
    pthread_mutex_lock(&q->lock);
    if (!isFull(q)) {
        q->rear = (q->rear + 1) % MAX_REQUESTS;
        q->requests[q->rear] = request;
        q->size++;
    }
    pthread_mutex_unlock(&q->lock);
}

Request dequeue(RequestQueue *q) {
    pthread_mutex_lock(&q->lock);
    Request request = { 0, 0 };
    if (!isEmpty(q)) {
        request = q->requests[q->front];
        q->front = (q->front + 1) % MAX_REQUESTS;
        q->size--;
    }
    pthread_mutex_unlock(&q->lock);
    return request;
}

void *elevator(void *arg) {
    while (true) {
        if (isEmpty(&queue)) {
            sleep(1);
            continue;
        }
        
        Request request = dequeue(&queue);
        printf("Elevator moving to Floor %d...\n", request.floor);
        sleep(2); // Simulating time taken to move
        
        if (request.direction == 1) {
            printf("Elevator arrived at Floor %d, going up!\n", request.floor);
        } else {
            printf("Elevator arrived at Floor %d, going down!\n", request.floor);
        }
    }
    return NULL;
}

int main() {
    pthread_t elevator_thread;
    initQueue(&queue);
    
    if (pthread_create(&elevator_thread, NULL, elevator, NULL) != 0) {
        fprintf(stderr, "Error creating elevator thread\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        int floor;
        printf("Requesting elevator to Floor (0-%d): ", MAX_FLOORS - 1);
        scanf("%d", &floor);
        if (floor < 0 || floor >= MAX_FLOORS) {
            printf("Invalid floor. Please try again.\n");
            i--; // redo this iteration
            continue;
        }

        Request request;
        request.floor = floor;
        request.direction = (floor > 0) ? 1 : -1; // Simple logic for direction
        enqueue(&queue, request);
    }

    pthread_join(elevator_thread, NULL);
    return 0;
}