//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE], front = -1, rear = -1;

void enqueue(int element) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
        printf("Queue Overflow!\n");
        return;
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
    }
    else if (rear == MAX_SIZE - 1 && front != 0) {
        rear = 0;
    }
    else {
        rear++;
    }
    queue[rear] = element;
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Dequeued Element : %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (front == MAX_SIZE - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue elements are : ");
    if (rear >= front) {
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    else {
        for (i = front; i < MAX_SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

void main() {
    printf("****************** C Queue Implementation using Circular Array ******************\n");

    char choice;
    int element;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            printf("Enter the element to enqueue : ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case '2':
            dequeue();
            break;
        case '3':
            display();
            break;
        case '4':
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
}