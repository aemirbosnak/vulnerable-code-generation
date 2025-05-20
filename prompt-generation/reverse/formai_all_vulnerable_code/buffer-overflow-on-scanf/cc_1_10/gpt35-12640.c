//FormAI DATASET v1.0 Category: Queue Implementation ; Style: high level of detail
/**
* This program is an implementation of a queue data structure in C. The program provides the
* functionality of inserting elements into the queue, removing elements from the queue and
* displaying the elements of the queue.
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = 0, rear = 0;

// Function to insert an element into the queue
void insert(int data) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is full!\n");
        return;
    }
    queue[rear] = data;
    rear = (rear + 1) % SIZE;
}

// Function to remove an element from the queue
void remove_element() {
    if (front == rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Removed %d from the queue.\n", queue[front]);
    front = (front + 1) % SIZE;
}

// Function to display the elements of the queue
void display() {
    int i;
    if (front == rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements:\n");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("1. Insert element into the queue.\n");
        printf("2. Remove element from the queue.\n");
        printf("3. Display the elements of the queue.\n");
        printf("4. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                remove_element();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}