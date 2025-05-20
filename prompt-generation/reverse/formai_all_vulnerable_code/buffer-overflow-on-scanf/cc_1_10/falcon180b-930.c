//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: happy
#include <stdio.h>

#define SIZE 100

int front = -1, rear = -1;

int queue[SIZE];

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else
        rear++;
    queue[rear] = value;
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("The dequeued element is %d\n", queue[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else
        front++;
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("The elements in the queue are: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, value;
    do {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be enqueued: ");
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
    } while (choice!= 4);
    return 0;
}