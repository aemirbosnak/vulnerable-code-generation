//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int rear;
} Queue;

void createQueue(Queue* q) {
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return (q->rear == -1);
}

int isFull(Queue* q) {
    return (q->rear == MAX_SIZE - 1);
}

void enqueue(Queue* q, int data) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d\n", data);
        return;
    }
    if (isEmpty(q)) {
        q->rear++;
        q->data = data;
    } else {
        q->rear++;
        q->data = data;
    }
}

int dequeue(Queue* q) {
    int data = -1;
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return data;
    }
    data = q->data;
    q->rear--;
    return data;
}

int peek(Queue* q) {
    int data = -1;
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot peek.\n");
        return data;
    }
    data = q->data;
    return data;
}

int main() {
    Queue q;
    createQueue(&q);

    int choice, data;
    do {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                data = dequeue(&q);
                if (data!= -1) {
                    printf("Dequeued data: %d\n", data);
                }
                break;
            case 3:
                data = peek(&q);
                if (data!= -1) {
                    printf("Front data: %d\n", data);
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}