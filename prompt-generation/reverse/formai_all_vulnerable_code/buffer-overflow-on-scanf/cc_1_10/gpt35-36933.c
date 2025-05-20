//FormAI DATASET v1.0 Category: Queue Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int arr[SIZE];
    int front;
    int rear;
} Queue;

void initialize(Queue *q) {
    q -> front = -1;
    q -> rear = -1;
}

int isEmpty(Queue q) {
    return q.rear == -1;
}

int isFull(Queue q) {
    return q.rear == SIZE - 1;
}

void enqueue(Queue *q, int val) {
    if (isFull(*q)) {
        printf("Queue overflow!\n");
        return;
    }
    if (q -> front == -1) {
        q -> front = 0;
    }
    q -> rear++;
    q -> arr[q -> rear] = val;
}

int dequeue(Queue *q) {
    if (isEmpty(*q)) {
        printf("Queue underflow!\n");
        return -1;
    }
    int val = q -> arr[q -> front];
    if (q -> front == q -> rear) {
        q -> front = -1;
        q -> rear = -1;
    }
    else {
        q -> front++;
    }
    return val;
}

void display(Queue q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.arr[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initialize(&q);
    int choice, val;
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 2:
                val = dequeue(&q);
                if (val != -1) {
                    printf("Successfully dequeued element: %d\n", val);
                }
                break;
            case 3:
                display(q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}