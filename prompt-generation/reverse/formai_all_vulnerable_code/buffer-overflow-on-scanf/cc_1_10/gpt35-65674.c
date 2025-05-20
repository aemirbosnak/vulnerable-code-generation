//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int data) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1 && rear == -1)
        front = rear = 0;
    else
        rear++;
    queue[rear] = data;
    printf("%d enqueued to the queue.\n", data);
}

int dequeue() {
    int data;
    if (front == -1) {
        printf("Queue underflow\n");
        return -1;
    }
    data = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    printf("%d dequeued from the queue.\n", data);
    return data;
}

void display() {
    int i;
    if (front == -1)
        printf("Queue is empty\n");
    else {
        printf("Queue elements are:\n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, data;

    while (1) {
        printf("1. Enqueue element to queue\n");
        printf("2. Dequeue element from queue\n");
        printf("3. Display all elements of queue\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
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
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}