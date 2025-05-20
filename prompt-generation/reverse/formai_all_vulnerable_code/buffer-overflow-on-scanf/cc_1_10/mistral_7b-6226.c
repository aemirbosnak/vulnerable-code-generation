//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_QUEUE_SIZE 10

typedef struct Queue {
    int front;
    int rear;
    int arr[MAX_QUEUE_SIZE];
} Queue;

void enqueue(Queue *q, int data) {
    if (q->rear == MAX_QUEUE_SIZE - 1 && q->front == 0) {
        printf("Queue is full.\n");
        return;
    }

    if (q->rear == MAX_QUEUE_SIZE - 1) {
        q->rear = 0;
    } else {
        q->rear++;
    }

    q->arr[q->rear] = data;
}

int dequeue(Queue *q) {
    if (q->front == q->rear + 1 && q->front != 0) {
        printf("Queue is empty.\n");
        return -1;
    }

    int data = q->arr[q->front];

    if (q->front == MAX_QUEUE_SIZE - 1) {
        q->front = 0;
    } else {
        q->front++;
    }

    return data;
}

void display(Queue q) {
    int i = q.front;

    printf("Queue: ");

    do {
        printf("%d ", q.arr[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
    } while (i != q.rear);

    printf("\b\n");
}

int main() {
    Queue q;
    int choice, data;

    memset(&q, 0, sizeof(Queue));

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                data = dequeue(&q);
                if (data != -1) {
                    printf("Dequeued data: %d\n", data);
                }
                break;
            case 3:
                display(q);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}