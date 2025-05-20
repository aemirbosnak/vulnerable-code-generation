//FormAI DATASET v1.0 Category: Queue Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int value);
void dequeue();
void display();

int main() {
    int choice, value;

    printf("Welcome to the Surrealist Queue implementation program!\n");

    do {
        printf("\nChoose an option:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}

void enqueue(int value) {
    if (front == 0 && rear == MAX_SIZE - 1) {
        printf("The Surrealist Queue is full and overflowing...\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX_SIZE - 1 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }

    queue[rear] = value;

    printf("The value %d has been enqueued in the surrealist queue...\n", value);
}

void dequeue() {
    if (front == -1) {
        printf("The Surrealist Queue is empty and there's nothing to dequeue...\n");
        return;
    }

    printf("The value %d has been dequeued from the surrealist queue...\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX_SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("The Surrealist Queue is empty and there's nothing to display...\n");
        return;
    }

    printf("The surrealistic queue contains:\n");

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

    printf("\n");
}