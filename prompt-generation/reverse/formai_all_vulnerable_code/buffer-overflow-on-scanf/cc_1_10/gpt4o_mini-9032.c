//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5 // Max size of the queue 

typedef struct Queue {
    int items[MAX]; // Array to hold the queue elements
    int front;  // Front points to the front element in the queue
    int rear;   // Rear points to the last element in the queue
} Queue;

// Function to create and initialize a queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) {
        printf("Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }
    q->front = -1; // Queue is initially empty
    q->rear = -1;
    return q;
}

// Check if the queue is full
bool isFull(Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

// Check if the queue is empty
bool isEmpty(Queue* q) {
    return q->front == -1;
}

// Enqueue an element to the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (q->front == -1) {
        q->front = 0; // First element being inserted
    }
    q->rear = (q->rear + 1) % MAX; // Circular increment
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Dequeue an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Indicates that the queue is empty
    }
    int value = q->items[q->front];
    if (q->front == q->rear) { // Queue has only one element
        q->front = q->rear = -1; // Reset the queue
    } else {
        q->front = (q->front + 1) % MAX; // Circular increment
    }
    printf("Dequeued: %d\n", value);
    return value;
}

// Function to peek at the front element of the queue
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot peek.\n");
        return -1; // Indicates that the queue is empty
    }
    return q->items[q->front];
}

// Display the Queue Status
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (true) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX; // Circular increment
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue(); // Create a new queue
    int choice, value;

    while (1) {
        printf("\nQueue Operations Menu:\n");
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
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                value = peek(q);
                if (value != -1) 
                    printf("Front of the queue: %d\n", value);
                break;
            case 4:
                display(q);
                break;
            case 5:
                free(q); // Free allocated memory for the queue
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}