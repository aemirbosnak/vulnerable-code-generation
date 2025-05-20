//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

// Function to check if the queue is empty
int isEmpty() {
    if (front == NULL)
        return 1;
    else
        return 0;
}

// Function to check if the queue is full
int isFull() {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL)
        return 1;
    else {
        free(temp);
        return 0;
    }
}

// Function to add an element to the queue
void enqueue(int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL)
        printf("Queue is Full\n");
    else {
        temp->data = value;
        temp->next = NULL;
        if (isEmpty()) {
            front = temp;
            rear = temp;
        }
        else {
            rear->next = temp;
            rear = temp;
        }
    }
}

// Function to remove an element from the queue
int dequeue() {
    int value;
    Node* temp;
    if (isEmpty())
        printf("Queue is Empty\n");
    else {
        temp = front;
        value = temp->data;
        front = front->next;
        free(temp);
        if (front == NULL)
            rear = NULL;
    }
    return value;
}

// Function to display the elements in the queue
void display() {
    Node* temp = front;
    if (isEmpty())
        printf("Queue is Empty\n");
    else {
        printf("Elements in the Queue are:\n");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("Enter 1 to Enqueue\n");
        printf("Enter 2 to Dequeue\n");
        printf("Enter 3 to Display\n");
        printf("Enter 4 to Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to be enqueued: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                printf("Value dequeued: %d\n", value);
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