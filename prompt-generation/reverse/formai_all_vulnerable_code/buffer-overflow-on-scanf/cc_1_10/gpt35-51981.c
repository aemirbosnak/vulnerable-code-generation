//FormAI DATASET v1.0 Category: Queue Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int data) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1))) {
        printf("Queue is full.\n");
        return;
    } else if (front == -1) {
        front = rear = 0;
        queue[rear] = data;
    } else if (rear == MAX_SIZE - 1 && front != 0) {
        rear = 0;
        queue[rear] = data;
    } else {
        rear++;
        queue[rear] = data;
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Dequeued item: %d\n", queue[front]);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == MAX_SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements are: ");

    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (int i = front; i < MAX_SIZE; i++)
            printf("%d ", queue[i]);

        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }

    printf("\n");
}

int main() {
    int option, data;

    do {
        printf("\n\n********* Menu *********\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");

        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
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
                printf("Invalid option. Please enter again.\n");
        }
    } while (option != 4);

    return 0;
}