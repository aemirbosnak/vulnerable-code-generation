//FormAI DATASET v1.0 Category: Queue ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Queue structure definition
typedef struct {
    int queue[MAX_SIZE];
    int front, rear;
} Queue;

int isFull(Queue *q) {
    return (q->rear == MAX_SIZE - 1);
}

int isEmpty(Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full, cannot enqueue element %d\n", data);
        return;
    }
    if (q->front == -1) { // If the queue is empty
        q->front = 0; // Set the front pointer to the first element
    }
    q->rear++;
    q->queue[q->rear] = data; // Enqueue the new element
    printf("Enqueued element %d\n", data);
}

int dequeue(Queue *q) {
    if (isEmpty(q)) { // If the queue is empty
        printf("Queue is empty, cannot dequeue element\n");
        return -1;
    }
    int data = q->queue[q->front]; // Dequeue the front element and return its value
    q->front++;
    printf("Dequeued element %d\n", data);
    return data;
}

int main() {
    Queue q;
    q.front = q.rear = -1;
    int choice, data;
    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue an element\n");
        printf("2. Dequeue an element\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                printf("\nExiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    } while (1); // Repeat the menu until the user chooses to exit
    return 0;
}