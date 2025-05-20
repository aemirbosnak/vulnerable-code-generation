//FormAI DATASET v1.0 Category: Queue Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define max_size 100

int queue[max_size];
int front = -1, rear = -1;

// Function to check if the queue is empty or not
int is_empty() {
    if (front == -1 && rear == -1) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is full or not
int is_full() {
    if (rear == max_size - 1) {
        return 1;
    }
    return 0;
}

// Function to insert elements into the queue
void enqueue(int x) {
    if (is_full()) {
        printf("Queue is full!\n");
        return;
    }
    if (is_empty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = x;
    printf("%d has been enqueued!\n", x);
}

// Function to remove elements from the queue
void dequeue() {
    if (is_empty()) {
        printf("Queue is empty!\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    printf("%d has been dequeued!\n", queue[front-1]);
}

// Function to display the queue
void display() {
    if (is_empty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Elements in the queue are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function to test the queue implementation
int main() {
    int choice = 0, x;
    while (1) {
        printf("Choose an operation:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}