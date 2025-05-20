//FormAI DATASET v1.0 Category: Queue Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

int front = -1, rear = -1;
int queue[QUEUE_SIZE];

// function to check if the queue is empty
int is_empty() {
    if (front == -1 && rear == -1) {
        return 1;
    }
    return 0;
}

// function to check if the queue is full
int is_full() {
    if ((rear+1)%QUEUE_SIZE == front) {
        return 1;
    }
    return 0;
}

// function to add an element to the queue
void enqueue(int value) {
    if (is_full()) {
        printf("\nQueue is full!");
        return;
    } else if (is_empty()) {
        front = rear = 0;
    } else {
        rear = (rear+1)%QUEUE_SIZE;
    }
    queue[rear] = value;
    printf("\n%d enqueued successfully!", value);
}

// function to remove an element from the queue
void dequeue() {
    if (is_empty()) {
        printf("\nQueue is empty!");
        return;
    } else if (front == rear) {
        front = rear = -1;
    } else {
        front = (front+1)%QUEUE_SIZE;
    }
    printf("\n%d dequeued successfully!", queue[(front-1)%QUEUE_SIZE]);
}

// function to display the elements in the queue
void display() {
    int i;
    if (is_empty()) {
        printf("\nQueue is empty!");
        return;
    }
    printf("\nElements in the queue: ");
    for (i=front; i!=rear; i=(i+1)%QUEUE_SIZE) {
        printf("%d ", queue[i]);
    }
    printf("%d", queue[i]);
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\n\n------Queue Implementation------");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\nEnter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting the program...");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a valid choice.");
        }
    }
    
    return 0;
}