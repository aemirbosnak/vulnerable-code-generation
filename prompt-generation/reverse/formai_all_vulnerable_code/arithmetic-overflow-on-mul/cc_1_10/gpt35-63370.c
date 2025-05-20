//FormAI DATASET v1.0 Category: Queue ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_QUEUE_SIZE 10

// Queue structure
typedef struct {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Initialize queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
bool isFull(Queue* q) {
    if(q->rear == MAX_QUEUE_SIZE - 1)
        return true;
    return false;
}

// Check if the queue is empty
bool isEmpty(Queue* q) {
    if(q->front == -1 && q->rear == -1)
        return true;
    return false;
}

// Add item to the end of the queue
void enqueue(Queue* q, int val) {
    if(isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if(isEmpty(q)) {
        q->front = q->rear = 0;
    }
    else {
        q->rear++;
    }
    q->items[q->rear] = val;
}

// Remove item from the front of the queue
int dequeue(Queue* q) {
    int val;
    if(isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    if(q->front == q->rear) {
        val = q->items[q->front];
        q->front = q->rear = -1;
    }
    else {
        val = q->items[q->front];
        q->front++;
    }
    return val;
}

// Print queue elements
void printQueue(Queue* q) {
    if(isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    for(int i=q->front; i<=q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Thread function to enqueue numbers to the queue
void* enqueueThread(void* arg) {
    int id = *(int*)arg;
    for(int i=1; i<=5; i++) {
        enqueue((Queue*)arg, id*10 + i);
        printf("Enqueued %d%d\n", id, i);
        sleep(1);
    }
    pthread_exit(NULL);
}

// Thread function to dequeue numbers from the queue
void* dequeueThread(void* arg) {
    for(int i=1; i<=10; i++) {
        int val = dequeue((Queue*)arg);
        if(val != -1)
            printf("Dequeued %d\n", val);
        sleep(2);
    }
    pthread_exit(NULL);
}

int main() {
    // Initialize Queue
    Queue q;
    initQueue(&q);

    // Initialize threads
    pthread_t threadID_1, threadID_2;
    int thread_1 = 1;
    int thread_2 = 2;

    // Create threads
    pthread_create(&threadID_1, NULL, enqueueThread, &q);
    pthread_create(&threadID_2, NULL, dequeueThread, &q);

    // Wait for threads to finish
    pthread_join(threadID_1, NULL);
    pthread_join(threadID_2, NULL);

    return 0;
}