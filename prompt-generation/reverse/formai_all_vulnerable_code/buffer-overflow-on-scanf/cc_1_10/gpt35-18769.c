//FormAI DATASET v1.0 Category: Queue Implementation ; Style: recursive
#include<stdio.h>

#define MAX_SIZE 100

int q[MAX_SIZE], front = 0, rear = -1;

// Function to check if queue is full
int isFull() {
    if (rear == MAX_SIZE - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to check if queue is empty
int isEmpty() {
    if (front > rear) {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to add element to queue
void enqueue(int data) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    else {
        rear++;
        q[rear] = data;
        printf("%d added to the queue\n", data);
    }
}

// Function to remove element from queue
int dequeue() {
    int data;
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return 0;
    }
    else {
        data = q[front];
        front++;
        printf("%d removed from the queue\n", data);
        return data;
    }
}

// Function to display the queue
void display() {
    int i;
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }
    else {
        printf("Queue elements are: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, data;
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        printf("Enter the data to be added to the queue: ");
        scanf("%d", &data);
        enqueue(data);
        main(); // call main recursively
        break;
    case 2:
        dequeue();
        main(); // call main recursively
        break;
    case 3:
        display();
        main(); // call main recursively
        break;
    case 4:
        printf("Exiting...");
        return 0;
    default:
        printf("Invalid Choice\n");
        main(); // call main recursively
    }
    return 0;
}