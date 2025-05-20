//FormAI DATASET v1.0 Category: Queue ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_SIZE 10

struct queue {
    int front;
    int rear;
    int items[QUEUE_SIZE];
};

void enqueue(struct queue *q, int data) {
    if ((q->rear + 1) % QUEUE_SIZE == q->front) {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->items[q->rear] = data;
}

int dequeue(struct queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    q->front = (q->front + 1) % QUEUE_SIZE;
    return q->items[q->front];
}

bool is_empty(struct queue *q) {
    return q->front == q->rear;
}

int main() {
    struct queue q;
    q.front = 0;
    q.rear = 0;
    int choice, data;

    printf("Welcome to the C Queue Example Program!\n");

    while (true) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Check if Queue is empty\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&q, data);
                printf("%d enqueued successfully\n", data);
                break;
            case 2:
                data = dequeue(&q);
                if (data != -1) {
                    printf("%d dequeued successfully\n", data);
                }
                break;
            case 3:
                if (is_empty(&q)) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}