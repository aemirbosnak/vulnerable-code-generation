//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5 // Maximum size of the queue

typedef struct {
    int items[MAX];
    int front;
    int rear;
} CircularQueue;

// Function to initialize the queue
void initializeQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is full
bool isFull(CircularQueue *q) {
    return (q->front == (q->rear + 1) % MAX);
}

// Check if queue is empty
bool isEmpty(CircularQueue *q) {
    return (q->front == -1);
}

// Enqueue operation
void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Can't enqueue %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Enqueued %d to the queue.\n", value);
}

// Dequeue operation
int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Can't dequeue.\n");
        return -1; // Indicating an empty queue
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1; // Queue is now empty
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    printf("Dequeued %d from the queue.\n", item);
    return item;
}

// Display queue contents
void displayQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Current Queue: ");
    int i = q->front;
    while (true) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Menu function
void displayMenu() {
    printf("\nCircular Queue Operations:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display Queue\n");
    printf("4. Check if Queue is Full\n");
    printf("5. Check if Queue is Empty\n");
    printf("6. Exit\n");
}

int main() {
    CircularQueue q;
    initializeQueue(&q);
    int choice, value;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                if (isFull(&q)) {
                    printf("The queue is full.\n");
                } else {
                    printf("The queue is not full.\n");
                }
                break;
            case 5:
                if (isEmpty(&q)) {
                    printf("The queue is empty.\n");
                } else {
                    printf("The queue is not empty.\n");
                }
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}