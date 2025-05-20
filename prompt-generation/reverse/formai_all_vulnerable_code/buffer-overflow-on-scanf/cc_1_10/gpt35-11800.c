//FormAI DATASET v1.0 Category: Queue Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

struct Queue {
    int front, rear;
    int queue[MAX_QUEUE_SIZE];
};

void enqueue(struct Queue *q, int val) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full! Cannot enqueue any more values.\n");
        return;
    }
    q->rear++;
    q->queue[q->rear] = val;
}

int dequeue(struct Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty! Cannot dequeue any value.\n");
        return -1;
    }
    q->front++;
    return q->queue[q->front];
}

int main() {
    struct Queue q;
    q.front = -1;
    q.rear = -1;
    int choice, value;

    printf("===============================================\n");
    printf(" RETRO C QUEUE IMPLEMENTATION EXAMPLE PROGRAM \n");
    printf("===============================================\n\n");

    do {
        printf("\n---------------------------------------\n");
        printf("PLEASE CHOOSE AN OPERATION TO PERFORM:\n");
        printf("---------------------------------------\n");
        printf("1. Enqueue a value\n");
        printf("2. Dequeue a value\n");
        printf("3. Exit the program\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                printf("\n%d was enqueued successfully!\n", value);
                break;

            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("\n%d was dequeued successfully!\n", value);
                }
                break;

            case 3:
                printf("\nExiting the program...");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (1);

    return 0;
}