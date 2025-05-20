//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5 // Define maximum size of the queue

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is full
bool isFull(Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}

// Function to check if the queue is empty
bool isEmpty(Queue *q) {
    return q->front == -1;
}

// Function to add an element to the queue
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Unable to enqueue %d\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0; // First element being added
        }
        q->rear = (q->rear + 1) % MAX;
        q->items[q->rear] = value;
        printf("Enqueued %d to the queue.\n", value);
    }
}

// Function to remove an element from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Unable to dequeue.\n");
        return -1; // Return -1 if the queue is empty
    } else {
        int dequeuedValue = q->items[q->front];
        printf("Dequeued %d from the queue.\n", dequeuedValue);
        if (q->front == q->rear) {
            // Queue becomes empty after this dequeue
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
        return dequeuedValue;
    }
}

// Function to display the contents of the queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue contents: ");
        int i = q->front;
        while (i != q->rear) {
            printf("%d ", q->items[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", q->items[i]); // Print the rear item
    }
}

// Function to clean up and free the queue
void freeQueue(Queue *q) {
    free(q);
}

int main() {
    Queue *q = createQueue();
    int choice, value;

    do {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 4);
    
    freeQueue(q);
    return 0;
}