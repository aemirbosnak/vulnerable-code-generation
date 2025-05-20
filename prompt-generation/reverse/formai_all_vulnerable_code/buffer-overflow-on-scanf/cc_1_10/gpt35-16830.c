//FormAI DATASET v1.0 Category: Queue Implementation ; Style: authentic
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 5

int front = -1, rear = -1;
int queue[MAX_SIZE];

int isFull() {
    return rear == MAX_SIZE - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int element) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }
    rear++;
    queue[rear] = element;
    if (front == -1) {
        front = 0;
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Dequeued element: %d\n", queue[front]);
    front++;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d\t", queue[i]);
    }
    printf("\n");
}

int main() {
    int option, element;
    do {
        printf("\n\nC Queue Implementation\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) {
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    } while (option != 0);
    return 0;
}