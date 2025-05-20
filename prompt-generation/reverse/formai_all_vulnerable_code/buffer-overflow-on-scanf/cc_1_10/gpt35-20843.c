//FormAI DATASET v1.0 Category: Queue Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 10

int front = -1;
int rear = -1;
int queue[MAX_CAPACITY];

int isFull() {
    return rear == MAX_CAPACITY - 1 ? 1 : 0;
}

int isEmpty() {
    return front == -1 ? 1 : 0;
}

void enqueue(int value) {
    if (isFull()) {
        printf("The queue is full. Cannot insert %d\n", value);
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}

int dequeue() {
    int deletedValue;
    if (isEmpty()) {
        printf("The queue is empty. Cannot perform dequeue operation.\n");
    } else {
        deletedValue = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        printf("Deleted %d from the queue.\n", deletedValue);
        return deletedValue;
    }
}

int peek() {
    if (isEmpty()) {
        printf("The queue is empty. Cannot perform peek operation.\n");
        return -1;
    } else {
        printf("The front element of the queue is %d.\n", queue[front]);
        return queue[front];
    }
}

void display() {
    int i;
    if (isEmpty()) {
        printf("The queue is empty. Nothing to display.\n");
    } else {
        printf("The elements of the queue are:\n");
        for (i = front; i <= rear; i++) {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}

void main() {
    int choice, value, deletedValue;

    printf("Welcome to the post-apocalyptic C Queue Implementation program!\n");

    while (1) {
        printf("\nChoose an operation: \n1. Insert\n2. Delete\n3. Peek\n4. Display\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to be inserted into the queue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                deletedValue = dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Thank you for using the post-apocalyptic C Queue Implementation program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
}