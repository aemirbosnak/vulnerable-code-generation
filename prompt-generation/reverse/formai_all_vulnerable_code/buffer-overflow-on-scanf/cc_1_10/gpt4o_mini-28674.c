//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_FLOORS 10
#define MAX_REQUESTS 100

typedef struct {
    int requestedFloor;
} Request;

typedef struct {
    Request requests[MAX_REQUESTS];
    int front;
    int rear;
    int size;
    pthread_mutex_t lock;
    pthread_cond_t not_empty;
    pthread_cond_t not_full;
} RequestQueue;

RequestQueue queue = {{0}, 0, 0, 0, PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER};

void initQueue(RequestQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool isFull(RequestQueue *q) {
    return q->size >= MAX_REQUESTS;
}

bool isEmpty(RequestQueue *q) {
    return q->size == 0;
}

void enqueue(RequestQueue *q, int floor) {
    pthread_mutex_lock(&q->lock);
    while (isFull(q)) {
        pthread_cond_wait(&q->not_full, &q->lock);
    }
    
    q->rear = (q->rear + 1) % MAX_REQUESTS;
    q->requests[q->rear].requestedFloor = floor;
    q->size++;
    
    pthread_cond_signal(&q->not_empty);
    pthread_mutex_unlock(&q->lock);
}

Request dequeue(RequestQueue *q) {
    pthread_mutex_lock(&q->lock);
    while (isEmpty(q)) {
        pthread_cond_wait(&q->not_empty, &q->lock);
    }
    
    Request req = q->requests[q->front];
    q->front = (q->front + 1) % MAX_REQUESTS;
    q->size--;
    
    pthread_cond_signal(&q->not_full);
    pthread_mutex_unlock(&q->lock);
    return req;
}

void* elevatorThread(void* arg) {
    while (true) {
        Request req = dequeue(&queue);
        printf("Elevator moving to floor %d...\n", req.requestedFloor);
        sleep(1); // Simulate time taken to reach the floor
        printf("Arrived at floor %d\n", req.requestedFloor);
    }
    return NULL;
}

int main() {
    pthread_t elevator;
    initQueue(&queue);
    
    if (pthread_create(&elevator, NULL, elevatorThread, NULL) != 0) {
        fprintf(stderr, "Error creating elevator thread\n");
        return 1;
    }
    
    int floorRequest;
    while (true) {
        printf("Enter a floor number (0 to %d, -1 to exit): ", MAX_FLOORS - 1);
        scanf("%d", &floorRequest);
        
        if (floorRequest == -1) {
            break;
        } else if (floorRequest < 0 || floorRequest >= MAX_FLOORS) {
            printf("Invalid floor number. Please try again.\n");
        } else {
            enqueue(&queue, floorRequest);
        }
    }
    
    // Cleanup and exit
    pthread_cancel(elevator);
    pthread_join(elevator, NULL);
    return 0;
}