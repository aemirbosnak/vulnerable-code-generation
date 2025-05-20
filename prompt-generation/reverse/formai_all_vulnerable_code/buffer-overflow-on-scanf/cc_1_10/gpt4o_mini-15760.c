//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure for Queue
typedef struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to create a Queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the Queue is Empty
bool isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to check if the Queue is Full
bool isFull(Queue* q) {
    return q->rear == MAX_SIZE - 1;
}

// Function to enqueue elements into the Queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow: Unable to add %d\n", value);
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

// Function to dequeue elements from the Queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow: No elements to dequeue\n");
        return -1;
    } else {
        int item = q->items[q->front];
        if (q->front >= q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
        printf("Dequeued: %d\n", item);
        return item;
    }
}

// Function to peek at the front element of the Queue
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No elements to peek.\n");
        return -1;
    }
    return q->items[q->front];
}

// Function to display the elements of the Queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

// Function to free allocated memory for the Queue
void freeQueue(Queue* q) {
    free(q);
}

int main() {
    Queue* q = createQueue();
    
    int choice, value;

    do {
        printf("Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display Queue\n");
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
                if (value != -1) {
                    printf("Front item is: %d\n", value);
                }
                break;
            case 4:
                displayQueue(q);
                break;
            case 5:
                printf("Exiting...\n");
                freeQueue(q);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}