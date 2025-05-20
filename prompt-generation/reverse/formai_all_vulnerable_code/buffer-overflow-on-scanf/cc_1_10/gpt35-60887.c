//FormAI DATASET v1.0 Category: Queue Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int front;
    int rear;
    int arr[MAX_QUEUE_SIZE];
} Queue;

void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    return q->rear == MAX_QUEUE_SIZE - 1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full, cannot add element.\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear++;
    }

    q->arr[q->rear] = value;
    printf("%d added to the Queue\n", value);
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty, cannot remove element.\n");
        return -1;
    }

    int removed = q->arr[q->front];

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }

    printf("%d removed from the Queue\n", removed);
    return removed;
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty, nothing to display.\n");
    } else {
        printf("Queue contents: ");

        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }

        printf("\n");
    }
}

int main() {
    Queue q;
    initialize(&q);

    printf("Welcome to the Queue implementation program!\n");
    printf("I see that the maximum size of the Queue is %d\n", MAX_QUEUE_SIZE);

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an element to the Queue.\n");
        printf("2. Remove an element from the Queue.\n");
        printf("3. Display the contents of the Queue.\n");
        printf("4. Exit.\n\n");

        int choice;

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int value;

                printf("Enter the value to be added: ");
                scanf("%d", &value);

                enqueue(&q, value);
                break;
            }
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Thank you for using the Queue implementation program!\n");
                exit(0);
            default:
                printf("Invalid input, please try again.\n");
        }
    }

    return 0;
}