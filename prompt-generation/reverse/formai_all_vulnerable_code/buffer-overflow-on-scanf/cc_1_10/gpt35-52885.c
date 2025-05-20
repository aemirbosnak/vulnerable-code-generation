//FormAI DATASET v1.0 Category: Queue ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

int front = -1, rear = -1;
int queue[MAX_QUEUE_SIZE];

void enqueue(int element) {
    if ((front == 0 && rear == MAX_QUEUE_SIZE - 1) || front == rear + 1) {
        printf("Queue Overflow! Sorry, could not add element %d\n", element);
    } else if (rear == -1) {
        front = rear = 0;
        queue[rear] = element;
        printf("Element %d added to the queue\n", element);
    } else if (rear == MAX_QUEUE_SIZE - 1 && front != 0) {
        rear = 0;
        queue[rear] = element;
        printf("Element %d added to the queue\n", element);
    } else {
        rear++;
        queue[rear] = element;
        printf("Element %d added to the queue\n", element);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow! Sorry, could not remove element\n");
    } else {
        printf("Element %d removed from the queue\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX_QUEUE_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        int i;
        printf("Current Queue:\n");
        if (rear >= front) {
            for (i = front; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
            printf("\n");
        } else {
            for (i = front; i < MAX_QUEUE_SIZE; i++) {
                printf("%d ", queue[i]);
            }
            for (i = 0; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
            printf("\n");
        }
    }
}

int main() {
    int choice, element;
    printf("Welcome to the Cheerful Queue Program! Let's have some fun with Queues today!\n");
    do {
        printf("1. Enqueue an element\n");
        printf("2. Dequeue an element\n");
        printf("3. Display the Queue\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the element to add: ");
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
                printf("Thanks for playing today! Have a joyful day!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please choose again\n");
                break;
        }
    } while (choice != 4);

    return 0;
}