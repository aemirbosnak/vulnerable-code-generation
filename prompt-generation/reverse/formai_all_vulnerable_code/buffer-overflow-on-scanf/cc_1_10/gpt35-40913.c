//FormAI DATASET v1.0 Category: Queue Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // Change this value to adjust the maximum size of the queue

int queue[MAX_SIZE];
int front = -1, rear = -1;

/**
 * Checks whether the queue is full or not
 */
int isFull() {
    return rear == MAX_SIZE - 1;
}

/**
 * Checks whether the queue is empty or not
 */
int isEmpty() {
    return (front == -1 && rear == -1);
}

/**
 * Inserts an element into the queue
 */
void enqueue(int x) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    } else if (isEmpty()) {
        front = 0;
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = x;
    printf("Inserted %d at position %d\n", x, rear+1);
}

/**
 * Removes an element from the queue
 */
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    } else if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

/**
 * Displays the elements of the queue
 */
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

/**
 * Main function to run the program
 */
int main() {
    int choice, x;
    while(1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the element to insert: ");
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
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}