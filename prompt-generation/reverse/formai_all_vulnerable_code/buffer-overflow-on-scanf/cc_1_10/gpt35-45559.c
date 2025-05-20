//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100 // Maximum size of the queue

// Start of Queue implementation
int queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;

// Function to check if the queue is empty
int is_empty() {
    if (front == -1 || front > rear) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the queue is full
int is_full() {
    if (rear == MAX_QUEUE_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to add an element to the queue
void enqueue(int data) {
    if (is_full()) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = data;
}

// Function to remove an element from the queue
int dequeue() {
    int data;
    if (is_empty()) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        data = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return data;
    }
}

// Function to display the queue
void display() {
    int i;
    if (is_empty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are:\n");
    for (i = front; i <= rear; i++) {
        printf("%d\n", queue[i]);
    }
}

int main() {
    int choice, data;
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
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
                exit(1);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}