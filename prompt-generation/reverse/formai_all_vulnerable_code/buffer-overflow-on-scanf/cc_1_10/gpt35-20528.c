//FormAI DATASET v1.0 Category: Queue ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

typedef struct {
    int front, rear;
    int items[QUEUE_SIZE];
} Queue;

void enqueue(Queue *q, int item) {
    if (q->rear == QUEUE_SIZE - 1) {
        printf("Error: Queue is full\n");
        return;
    }
    q->rear++;
    q->items[q->rear] = item;
}

int dequeue(Queue *q) {
    if (q->front == q->rear) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    q->front++;
    return q->items[q->front];
}

void display(Queue *q) {
    int i;
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return;
    }
    for (i = q->front + 1; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    Queue myqueue;
    myqueue.front = -1;
    myqueue.rear = -1;
    int option, num;

    printf("Welcome to the queue example program\n");
    printf("===================================\n");

    do {
        printf("\nOptions:\n");
        printf("1. Enqueue a number\n");
        printf("2. Dequeue a number\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");
        printf("\nEnter your option (1-4): ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nEnter a number to enqueue: ");
                scanf("%d", &num);
                enqueue(&myqueue, num);
                break;
            case 2:
                num = dequeue(&myqueue);
                if (num != -1) {
                    printf("%d dequeued from the queue\n", num);
                }
                break;
            case 3:
                display(&myqueue);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option\n");
        }
    } while (option != 4);

    return 0;
}