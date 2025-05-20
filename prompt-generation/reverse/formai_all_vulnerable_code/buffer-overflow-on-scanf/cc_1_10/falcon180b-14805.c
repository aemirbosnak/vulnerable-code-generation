//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int *arr;
    int front;
    int rear;
    int count;
} Queue;

void init(Queue *q) {
    q->arr = (int *)malloc(MAX_SIZE * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->count = 0;
}

int isEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

int isFull(Queue *q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }

    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }

    q->arr[q->rear] = value;
    q->count++;
}

int dequeue(Queue *q) {
    int value;

    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    value = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }

    q->count--;
    return value;
}

void display(Queue *q) {
    int i;

    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements are: ");
    for (i = q->front; i <= q->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    int choice, value;

    init(&q);

    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
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
                printf("The dequeued value is %d.\n", value);
            }
            break;

        case 3:
            display(&q);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}