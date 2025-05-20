//FormAI DATASET v1.0 Category: Queue Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

/* Initializing a queue with the maximum size of 5 */
int queue[MAX_QUEUE_SIZE];

/* Initializing the front and back pointers of the queue */
int front = -1;
int rear = -1;

/* Function to check if the queue is full */
int isFull() {
    if ((front == 0 && rear == MAX_QUEUE_SIZE - 1) || (rear == front - 1)) {
        return 1;
    }
    else {
        return 0;
    }
}

/* Function to check if the queue is empty */
int isEmpty() {
    if (front == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

/* Function to add an element to the rear of the queue */
void enqueue(int element) {
    if (isFull()) {
        printf("Queue is full!\n");
    }
    else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX_QUEUE_SIZE;
        queue[rear] = element;
        printf("%d added to the queue!\n", element);
    }
}

/* Function to remove an element from the front of the queue */
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    }
    else {
        printf("%d removed from the queue!\n", queue[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % MAX_QUEUE_SIZE;
        }
    }
}

/* Function to display the elements in the queue */
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    }
    else {
        int i;
        printf("Elements in the queue are: ");
        for (i = front; i != rear; i = (i + 1) % MAX_QUEUE_SIZE) {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[i]);
    }
}

int main() {
    int choice = 0, element = 0;

    printf("C Queue Implementation\n");

    while (choice != 4) {
        printf("\n1. Enqueue Element\n2. Dequeue Element\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be enqueued: ");
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    }

    return 0;
}