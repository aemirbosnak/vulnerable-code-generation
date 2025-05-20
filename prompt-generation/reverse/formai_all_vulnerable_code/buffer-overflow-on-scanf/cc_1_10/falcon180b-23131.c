//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Queue {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    if (q->front == -1 && q->rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

int isFull(Queue *q) {
    if ((q->rear + 1) % MAX_SIZE == q->front) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    } else if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->data[q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else if (q->front == q->rear) {
        int value = q->data[q->front];
        q->front = -1;
        q->rear = -1;
        return value;
    } else {
        int value = q->data[q->front];
        q->front = (q->front + 1) % MAX_SIZE;
        return value;
    }
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        int i = q->front;
        while (i!= q->rear) {
            printf("%d ", q->data[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", q->data[q->rear]);
    }
}

int main() {
    Queue q;
    initQueue(&q);
    int choice, value;
    do {
        printf("\nEnter your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the value to be enqueued: ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;
        case 2:
            value = dequeue(&q);
            if (value!= -1) {
                printf("Dequeued value: %d\n", value);
            }
            break;
        case 3:
            display(&q);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice!= 4);
    return 0;
}