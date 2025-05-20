//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

// Define the circular queue structure
typedef struct CircularQueue {
    int queue[MAX_QUEUE_SIZE];
    int front;
    int rear;
} CircularQueue;

// Initialize the circular queue
void initializeQueue(CircularQueue *queue) {
    queue->front = 0;
    queue->rear = -1;
}

// Check if the circular queue is full
int isFull(CircularQueue *queue) {
    return (queue->rear + 1) % MAX_QUEUE_SIZE == queue->front;
}

// Add an element to the circular queue from the rear
void enqueue(CircularQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Error: Circular Queue is full!\n");
        return;
    }

    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->queue[queue->rear] = value;
}

// Remove an element from the circular queue from the front
int dequeue(CircularQueue *queue) {
    if (queue->front == queue->rear) {
        printf("Error: Circular Queue is empty!\n");
        return -1;
    }

    int value = queue->queue[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    return value;
}

// Test the circular queue implementation
int main() {
    CircularQueue queue;
    initializeQueue(&queue);

    // Enqueue elements from the rear
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);

    printf("Front element: %d\n", queue.queue[queue.front]);
    printf("Rear element: %d\n", queue.queue[queue.rear]);

    // Dequeue elements from the front
    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    // Enqueue and dequeue elements to check the circular queue behavior
    enqueue(&queue, 5);
    printf("Front element: %d\n", queue.queue[queue.front]);
    printf("Rear element: %d\n", queue.queue[queue.rear]);

    return 0;
}