//FormAI DATASET v1.0 Category: Queue Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    if ((rear == MAX_SIZE - 1 && front == 0) || (rear == front - 1))
        return 1;
    return 0;
}

// Function to check if the queue is empty
int isEmpty() {
    if (front == -1 && rear == -1)
        return 1;
    return 0;
}

// Function to add an element to the queue
void enqueue(int element) {
    if (isFull())
        printf("Queue is full. Cannot insert element.\n");
    else {
        if (front == -1 && rear == -1) {
            front = rear = 0;
            queue[rear] = element;
        }
        else if (rear == MAX_SIZE - 1 && front != 0) {
            rear = 0;
            queue[rear] = element;
        }
        else {
            rear++;
            queue[rear] = element;
        }
        printf("Element %d has been enqueued.\n", element);
    }
}

// Function to remove an element from the queue
void dequeue() {
    if (isEmpty())
        printf("Queue is empty. Cannot remove any element.\n");
    else {
        printf("Element %d has been dequeued.\n", queue[front]);
        if (front == rear)
            front = rear = -1;
        else if (front == MAX_SIZE - 1)
            front = 0;
        else
            front++;
    }
}

// Function to display the queue
void display() {
    if (isEmpty())
        printf("Queue is empty. Cannot display elements.\n");
    else {
        int i = front, j = 0;
        printf("Elements in the queue are: ");
        if (front <= rear) {
            for (i = front; i <= rear; i++)
                printf("%d ", queue[i]);
        }
        else {
            for (i = front; i < MAX_SIZE; i++)
                printf("%d ", queue[i]);
            for (j = 0; j <= rear; j++)
                printf("%d ", queue[j]);
        }
        printf("\n");
    }
}

int main() {
    int choice, element;
    printf(":: Queue Operation ::\n");
    do {
        printf("Enter 1 to enqueue an element.\n");
        printf("Enter 2 to dequeue an element.\n");
        printf("Enter 3 to display the queue.\n");
        printf("Enter 4 to exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
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
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid input. Try again.\n");
        }
    } while (choice != 4);
    return 0;
}