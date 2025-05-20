//FormAI DATASET v1.0 Category: Queue Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

int queue[QUEUE_SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((front == 0 && rear == QUEUE_SIZE - 1) || rear == front - 1) {
        printf("\nQueue is full. Cannot enqueue %d", value);
        return;
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
    }
    else if (rear == QUEUE_SIZE - 1) {
        rear = 0;
    }
    else {
        rear++;
    }
    queue[rear] = value;
    printf("\nEnqueued %d", value);
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("\nQueue is empty. Cannot dequeue.");
        return;
    }
    printf("\nDequeued %d", queue[front]);
    if (front == rear) {
        front = rear = -1;
    }
    else if (front == QUEUE_SIZE - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("\nQueue is empty.");
        return;
    }
    printf("\nQueue: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    else {
        for (int i = front; i < QUEUE_SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("\nEnter the value: ");
                    scanf("%d", &value);
                    enqueue(value);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("\nInvalid choice. Please try again.");
        }
    }
}