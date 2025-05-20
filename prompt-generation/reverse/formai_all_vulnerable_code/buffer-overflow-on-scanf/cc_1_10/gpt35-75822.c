//FormAI DATASET v1.0 Category: Queue ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int front, rear;
    int items[MAX_QUEUE_SIZE];
} Queue;

void enqueue(Queue *q, int value) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue overflow!");
        exit(EXIT_FAILURE);
    } else {
        q->rear++;
        q->items[q->rear] = value;
    }
}

void dequeue(Queue *q) {
    if (q->front == q->rear) {
        printf("Queue underflow!");
        exit(EXIT_FAILURE);
    } else {
        q->front++;
    }
}

int front(Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty!");
        exit(EXIT_FAILURE);
    } else {
        return q->items[q->front + 1];
    }
}

int main() {
    Queue q;
    q.front = -1;
    q.rear = -1;

    int choice, value;

    do {
        printf("\n\nQueue Menu");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Front value");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                printf("\nFront value: %d", front(&q));
                break;
            case 4:
                printf("\nExiting program");
                break;
            default:
                printf("\nInvalid input, please try again");
        }
    } while (choice != 4);

    return 0;
}