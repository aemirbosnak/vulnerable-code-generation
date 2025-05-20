//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;
int count = 0;

// Function to create a new node with given data
Node *createNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an element to the rear of the queue
void enqueue(int data) {
    Node *newNode = createNode(data);
    if (rear == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    count++;
}

// Function to remove an element from the front of the queue
int dequeue() {
    int data;
    Node *temp = front;
    if (front == NULL) {
        printf("Queue is empty\n");
        exit(0);
    } else {
        data = front->data;
        front = front->next;
        free(temp);
        count--;
    }
    return data;
}

// Function to display the current state of the queue
void display() {
    Node *temp = front;
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Current state of the queue:\n");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function to test the implementation
int main() {
    int choice, data;
    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                printf("Dequeued element is: %d\n", data);
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