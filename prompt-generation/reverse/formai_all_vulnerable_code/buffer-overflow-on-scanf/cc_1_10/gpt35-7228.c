//FormAI DATASET v1.0 Category: Queue Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Maximum size of the queue

// Structure for queue
struct queue {
    int front;
    int rear;
    int data[MAX_SIZE];
} Q;

// Function to insert an element into the queue
void enqueue(int item) {
    if(Q.rear == MAX_SIZE - 1) {
        printf("\nQueue is full.\n");
        return;
    }else {
        if(Q.front == -1) 
            Q.front = 0;
        Q.rear++;
        Q.data[Q.rear] = item;
        printf("\nInserted %d into the queue.\n", item);
    }
}

// Function to remove an element from the queue
void dequeue() {
    if(Q.front == -1) {
        printf("\nQueue is empty.\n");
        return;
    }else {
        printf("\nDeleted %d from the queue.\n", Q.data[Q.front]);
        Q.front++;
        if(Q.front > Q.rear)
            Q.front = Q.rear = -1;
    }
}

// Function to display the elements of the queue
void display() {
    if(Q.front == -1) {
        printf("\nQueue is empty.\n");
        return;
    }else {
        printf("\nQueue elements are:\n");
        for(int i = Q.front; i <= Q.rear; i++)
            printf("%d ", Q.data[i]);
        printf("\n");
    }
}

int main() {
    Q.front = -1; // Initialize front of queue to -1 (empty)
    Q.rear = -1; // Initialize rear of queue to -1 (empty)
    int choice, item;

    do {
        printf("\n------------------------\n");
        printf("Queue Implementation Menu\n");
        printf("------------------------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: { // Enqueue
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            }
            case 2: { // Dequeue
                dequeue();
                break;
            }
            case 3: { // Display
                display();
                break;
            }
            case 4: { // Exit
                printf("\nExiting...\n");
                exit(0);
            }
            default: {
                printf("\nInvalid choice. Please try again.\n");
            }
        }
    }while(choice != 4);

    return 0;
}