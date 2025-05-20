//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

typedef struct Queue {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Function to create an empty queue
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

// Function to check if the queue is full
bool isFull(Queue* queue) {
    return (queue->rear + 1) % MAX_QUEUE_SIZE == queue->front;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Function to add an element to the queue
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        fprintf(stderr, "Queue overflow, cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->items[queue->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        fprintf(stderr, "Queue underflow, cannot dequeue\n");
        exit(EXIT_FAILURE);
    }
    int value = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    }
    printf("Dequeued: %d\n", value);
    return value;
}

// Function to display the elements of the queue
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->items[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
    printf("%d\n", queue->items[queue->rear]);
}

// Function to destroy the queue and free memory
void destroyQueue(Queue* queue) {
    if (queue) {
        free(queue);
        printf("Queue destroyed and memory freed\n");
    }
}

int main() {
    Queue* queue = createQueue();
    int choice, value;

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
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
                display(queue);
                break;
            case 4:
                destroyQueue(queue);
                exit(EXIT_SUCCESS);
            default:
                fprintf(stderr, "Invalid option, please choose again.\n");
        }
    }

    return 0;
}