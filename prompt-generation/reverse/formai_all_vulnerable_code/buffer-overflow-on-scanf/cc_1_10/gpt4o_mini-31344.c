//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to create a queue and initialize its members
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to enqueue an element into the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = value;
    printf("%d enqueued to queue\n", value);
}

// Function to dequeue an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear) { // Only one element was in the queue
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    printf("%d dequeued from queue\n", item);
    return item;
}

// Function to display the contents of the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i != q->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", q->items[i]);
    }
    printf("%d\n", q->items[q->rear]); // for the rear element
}

// Function to free the queue
void freeQueue(Queue* q) {
    free(q);
}

void menu() {
    printf("\n----- Queue Operations -----\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display Queue\n");
    printf("4. Exit\n");
    printf("----------------------------\n");
}

int main() {
    Queue* q = createQueue();
    int choice, value;

    while (1) {
        menu();
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
                displayQueue(q);
                break;
            case 4:
                freeQueue(q);
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}