//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Define the size of the queue
#define QUEUE_SIZE 10

// Define the structure of the queue
typedef struct {
    int data;
    struct node* next;
} Node;

// Declare the front and rear pointers
Node* front = NULL;
Node* rear = NULL;

// Function to check if the queue is empty
int isEmpty() {
    return (front == NULL && rear == NULL);
}

// Function to check if the queue is full
int isFull() {
    Node* temp = front;
    int count = 0;
    while (temp!= NULL) {
        count++;
        temp = temp->next;
    }
    return (count == QUEUE_SIZE);
}

// Function to enqueue an element
void enqueue(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Function to dequeue an element
int dequeue() {
    int value;
    if (isEmpty()) {
        printf("Queue is empty\n");
        exit(0);
    }
    else if (front == rear) {
        value = front->data;
        free(front);
        front = NULL;
        rear = NULL;
    }
    else {
        value = front->data;
        Node* temp = front;
        front = front->next;
        free(temp);
    }
    return value;
}

// Function to display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    }
    else {
        Node* temp = front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function to test the queue implementation
int main() {
    int choice, value;
    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                printf("Dequeued value: %d\n", value);
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