//FormAI DATASET v1.0 Category: Queue Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // Maximum size of the queue

int queue[MAX_SIZE];
int front = -1; // Front pointer of the queue
int rear = -1; // Rear pointer of the queue

// Function to add elements to the queue
void enqueue(int data) {
    if(rear == MAX_SIZE - 1) {
        printf("Queue Overflow\n");
    }
    else {
        rear++;
        queue[rear] = data;
        if(front == -1) {
            front = 0;
        }
    }
}

// Function to remove an element from the queue
void dequeue() {
    if(front == -1) {
        printf("Queue Underflow\n");
    }
    else {
        printf("The element %d is removed from the queue\n", queue[front]);
        if(front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front++;
        }
    }
}

// Function to display all the elements of the queue
void display() {
    if(front == -1) {
        printf("The queue is empty\n");
    }
    else {
        printf("The elements of the queue are: ");
        for(int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function to test the implementation
int main() {
    int choice, data;

    while(1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element you want to enqueue: ");
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
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}