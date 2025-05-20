//FormAI DATASET v1.0 Category: Queue Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

int queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

void enqueue(int value);
int dequeue(void);
void printQueue(void);

int main(void) {
    int option, value;

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a value to the queue\n");
        printf("2. Remove a value from the queue\n");
        printf("3. Print the queue\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        printf("\n");

        switch (option) {
            case 1:
                printf("Enter a value to add to the queue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                printQueue();
                break;

            case 4:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid option, try again.\n");
        }

    } while (option != 4);

    return 0;
}

void enqueue(int value) {
    if ((front == 0 && rear == MAX_QUEUE_SIZE-1) || (rear == (front-1)%(MAX_QUEUE_SIZE-1))) {
        printf("Queue is full, cannot add new value.\n");
        return;
    }

    if (front == -1) front = rear = 0;
    else if (rear == MAX_QUEUE_SIZE-1 && front != 0) rear = 0;
    else rear++;

    queue[rear] = value;
    printf("%d added to the queue.\n", value);
}

int dequeue(void) {
    if (front == -1) {
        printf("Queue is empty, cannot remove value.\n");
        return -1;
    }

    int value = queue[front];
    queue[front] = -1;

    if (front == rear) front = rear = -1;
    else if (front == MAX_QUEUE_SIZE-1) front = 0;
    else front++;

    printf("%d removed from the queue.\n", value);

    return value;
}

void printQueue(void) {
    printf("Queue: ");

    if (front <= rear) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (int i = front; i < MAX_QUEUE_SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }

    printf("\n");
}