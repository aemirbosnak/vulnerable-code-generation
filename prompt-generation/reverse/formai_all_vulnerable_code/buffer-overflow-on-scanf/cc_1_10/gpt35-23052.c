//FormAI DATASET v1.0 Category: Queue Implementation ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 10

int queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

int isQueueFull() {
    if ((front == rear + 1) || (front == 0 && rear == MAX_QUEUE_SIZE - 1)) {
        return 1;
    }
    return 0;
}

int isQueueEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(int val) {
    if (isQueueFull()) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX_QUEUE_SIZE;
        queue[rear] = val;
        printf("Enqueued %d\n", val);
    }
}

void dequeue() {
    if (isQueueEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Dequeued %d\n", queue[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_QUEUE_SIZE;
        }
    }
}

void display() {
    if (isQueueEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        int i;
        for (i = front; i != rear; i = (i + 1) % MAX_QUEUE_SIZE) {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    int choice, val;
    do {
        printf("Menu:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}