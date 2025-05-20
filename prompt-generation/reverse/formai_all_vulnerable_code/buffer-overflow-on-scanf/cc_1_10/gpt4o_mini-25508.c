//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100  // Maximum size of the Queue

// Define the Queue structure
typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function prototypes
Queue* createQueue();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int peek(Queue* q);
void display(Queue* q);
void freeQueue(Queue* q);

int main() {
    Queue* q = createQueue(); // Create a new Queue
    int choice, value;

    do {
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
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                value = dequeue(q);
                if (value != -1) {
                    printf("Dequeued element: %d\n", value);
                }
                break;
            case 3:
                value = peek(q);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
            case 4:
                display(q);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    freeQueue(q); // Free the allocated memory for the queue
    return 0;
}

// Function to create a new Queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is full
bool isFull(Queue* q) {
    return (q->rear == MAX - 1);
}

// Check if the queue is empty
bool isEmpty(Queue* q) {
    return (q->front == -1 || q->front > q->rear);
}

// Add an element to the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0; // Initialize front on first enqueue
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

// Remove and return the front element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1; // Indicating dequeue failed
    } else {
        int item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) { // Reset queue if it becomes empty
            q->front = q->rear = -1;
        }
        return item;
    }
}

// Return the front element without removing it
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot peek\n");
        return -1; // Indicating peek failed
    } else {
        return q->items[q->front];
    }
}

// Display all elements in the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

// Clean up memory allocated for the queue
void freeQueue(Queue* q) {
    free(q);
}