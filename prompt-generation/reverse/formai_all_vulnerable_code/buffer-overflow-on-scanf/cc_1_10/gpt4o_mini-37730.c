//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum queue size

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return ((q->rear + 1) % MAX == q->front);
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == -1);
}

// Function to add an element to the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Element %d cannot be added.\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0; // Initialize front
        }
        q->rear = (q->rear + 1) % MAX;
        q->items[q->rear] = value;
        printf("Element %d enqueued to the queue.\n", value);
    }
}

// Function to remove an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No elements to dequeue.\n");
        return -1;
    } else {
        int item = q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1; // Queue becomes empty
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
        return item;
    }
}

// Function to display the elements of the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = 0; i < MAX; i++) {
            int index = (q->front + i) % MAX;
            if (i > 0 && index != q->rear + 1) {
                break; // Stop if we reach the end of the queue
            }
            if (index != -1) {
                printf("%d ", q->items[index]);
            }
        }
        printf("\n");
    }
}

// Main function to demonstrate the queue operations
int main() {
    Queue* q = createQueue();
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
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
                display(q);
                break;
            case 4:
                free(q);
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}