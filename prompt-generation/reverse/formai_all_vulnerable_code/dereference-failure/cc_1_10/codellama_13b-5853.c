//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: synchronous
/*
 * queue.c: A simple queue implementation in C using a synchronous style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the queue structure
typedef struct {
    int size;
    int front;
    int rear;
    int* data;
} Queue;

// Initialize the queue
void init_queue(Queue* queue, int size) {
    queue->size = size;
    queue->front = 0;
    queue->rear = 0;
    queue->data = (int*)malloc(sizeof(int) * size);
}

// Add an element to the queue
void enqueue(Queue* queue, int element) {
    if (queue->rear < queue->size) {
        queue->data[queue->rear] = element;
        queue->rear++;
    }
}

// Remove an element from the queue
int dequeue(Queue* queue) {
    int element;
    if (queue->front < queue->rear) {
        element = queue->data[queue->front];
        queue->front++;
    }
    return element;
}

// Check if the queue is empty
int is_empty(Queue* queue) {
    return queue->front == queue->rear;
}

// Check if the queue is full
int is_full(Queue* queue) {
    return queue->front == queue->size;
}

// Test the queue implementation
int main() {
    Queue queue;
    init_queue(&queue, 5);
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    printf("Queue: ");
    while (!is_empty(&queue)) {
        printf("%d ", dequeue(&queue));
    }
    printf("\n");
    return 0;
}