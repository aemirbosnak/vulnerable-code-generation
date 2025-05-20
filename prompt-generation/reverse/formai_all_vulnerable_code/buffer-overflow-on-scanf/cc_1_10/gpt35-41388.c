//FormAI DATASET v1.0 Category: Queue ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Define the maximum size of the queue

int queue[MAX_SIZE]; // Declare the queue array
int rear = -1, front = -1; // Initially set the rear and front pointers to -1

// Function to check if the queue is full
int isFull() {
    if (rear == MAX_SIZE - 1) {
        return 1; // Return 1 (true) if the queue is full
    }
    return 0; // Return 0 (false) if the queue is not full
}

// Function to check if the queue is empty
int isEmpty() {
    if (front == -1 && rear == -1) {
        return 1; // Return 1 (true) if the queue is empty
    }
    return 0; // Return 0 (false) if the queue is not empty
}

// Function to add an element to the rear end of the queue
void enqueue(int item) {
    if (isFull()) {
        printf("Cannot insert element, Queue is full.\n");
        return;
    }
    else if (isEmpty()) {
        front = rear = 0;
    }
    else {
        rear++;
    }
    queue[rear] = item;
    printf("Element inserted successfully.\n");
}

// Function to remove an element from the front end of the queue
void dequeue() {
    if (isEmpty()) {
        printf("Cannot remove element, Queue is empty.\n");
        return;
    }
    else if (front == rear) {
        front = rear = -1;
    }
    else {
        front++;
    }
    printf("Element removed successfully.\n");
}

// Function to display the elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements in the queue are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, item;

    while (1) {
        printf("Choose an option -\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}