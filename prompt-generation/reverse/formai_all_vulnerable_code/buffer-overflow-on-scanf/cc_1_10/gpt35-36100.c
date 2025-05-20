//FormAI DATASET v1.0 Category: Queue ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

int front = -1;
int rear = -1;
int queue[MAX_QUEUE_SIZE];

void enqueue(int element) {
    if (rear == MAX_QUEUE_SIZE-1) {
        printf("Queue is full\n");
        return;
    }
    else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = element;
        printf("%d has been enqueued\n", element);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    else {
        printf("%d has been dequeued\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    }
    else {
        printf("Front = %d, Rear = %d\n", front, rear);
        for (int i=front; i<=rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, element;

    while (1) {
        printf("Press 1 to enqueue, 2 to dequeue, 3 to display, or 4 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
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
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}