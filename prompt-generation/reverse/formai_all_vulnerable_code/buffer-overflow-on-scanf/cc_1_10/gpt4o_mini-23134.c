//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5  // Maximum size of the queue

// Queue structure
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to create and initialize the queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Check if the queue is full
bool isFull(Queue* queue) {
    return (queue->rear + 1) % MAX == queue->front;
}

// Function to enqueue an item
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full! Cannot enqueue %d.\n", value);
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->items[queue->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to dequeue an item
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Return -1 if queue is empty to indicate failure
    }
    int item = queue->items[queue->front];
    if (queue->front == queue->rear) { // Queue has only one element
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX;
    }
    printf("Dequeued: %d\n", item);
    return item;
}

// Function to peek at the front item without dequeuing it
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! No front element to peek.\n");
        return -1; // Return -1 if queue is empty
    }
    return queue->items[queue->front];
}

// Function to display the queue
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Nothing to display.\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = 0; i < MAX; i++) {
        if (queue->items[i] != 0) {
            printf("%d ", queue->items[i]);
        }
    }
    printf("\n");
}

// Cleaning up the queue
void freeQueue(Queue* queue) {
    if (queue != NULL) {
        free(queue);
        printf("Queue memory freed.\n");
    }
}

int main() {
    Queue* queue = createQueue();
    int choice, value;

    while (true) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                value = peek(queue);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
            case 4:
                display(queue);
                break;
            case 5:
                freeQueue(queue);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}