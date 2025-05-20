//FormAI DATASET v1.0 Category: Queue Implementation ; Style: secure
// C Queue Implementation

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

// Struct definition for Queue
typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Function to check if queue is full
int isFull(Queue* queue) {
    return (queue->rear + 1) % MAX_QUEUE_SIZE == queue->front;
}

// Function to add an element to the queue
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Unable to enqueue element.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    }
    queue->data[queue->rear] = value;
}

// Function to remove an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Unable to dequeue element.\n");
        return -1;
    }
    int value = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    }
    return value;
}

// Main function
int main() {
    Queue* queue = createQueue();
    int choice, value;

    do {
        printf("\n1. Enqueue Element");
        printf("\n2. Dequeue Element");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                value = dequeue(queue);
                if (value != -1) {
                    printf("\nThe dequeued element is %d.", value);
                }
                break;
            case 3:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice. Please try again.");
        }
    } while (choice != 3);

    return 0;
}