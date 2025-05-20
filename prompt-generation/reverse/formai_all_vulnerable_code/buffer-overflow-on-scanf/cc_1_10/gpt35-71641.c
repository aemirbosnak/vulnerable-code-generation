//FormAI DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int val) {
    if ((front == 0 && rear == MAX_SIZE - 1) || rear == front - 1) {
        printf("\nQueue is full, cannot insert anymore!\n");
        return;
    } else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    } else if (rear == MAX_SIZE - 1 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = val;
    printf("\nInserted %d in the queue\n", val);
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("\nQueue is empty, cannot delete anymore!\n");
        return;
    } else if (front == rear) {
        printf("\nDeleted %d from the queue\n", queue[front]);
        front = -1;
        rear = -1;
    } else if (front == MAX_SIZE - 1) {
        printf("\nDeleted %d from the queue\n", queue[front]);
        front = 0;
    } else {
        printf("\nDeleted %d from the queue\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("\nQueue is empty, nothing to display!\n");
        return;
    }
    printf("\nQueue elements: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (int i = front; i < MAX_SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
}

int main() {
    int option, val;
    printf("Welcome to the Medieval Queue!");
    do {
        printf("\nChoose an option:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("\nEnter the value to insert: ");
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
                printf("\nExiting Medieval Queue... Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid option! Please try again.\n");
        }
    } while (option != 4);
    return 0;
}