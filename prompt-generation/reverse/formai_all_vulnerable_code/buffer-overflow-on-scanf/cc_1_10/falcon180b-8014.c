//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the queue
#define MAX_SIZE 100

// Define the structure of the queue
typedef struct {
    int data;
    struct node *next;
} Node;

// Declare the front and rear pointers of the queue
Node *front = NULL;
Node *rear = NULL;

// Function to create a new node
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the queue is empty
int isEmpty() {
    return front == NULL;
}

// Function to check if the queue is full
int isFull() {
    return rear == NULL;
}

// Function to add an element to the rear of the queue
void enqueue(int data) {
    Node *newNode = createNode(data);
    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d added to the queue\n", data);
}

// Function to remove an element from the front of the queue
int dequeue() {
    int data;
    if (isEmpty()) {
        printf("Queue is empty\n");
        exit(0);
    }
    else {
        Node *temp = front;
        data = front->data;
        front = front->next;
        free(temp);
    }
    return data;
}

// Function to display the elements of the queue
void display() {
    Node *temp = front;
    if (isEmpty()) {
        printf("Queue is empty\n");
    }
    else {
        printf("Elements of the queue are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, data;
    while (1) {
        printf("Enter your choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to be added: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                printf("Removed element is: %d\n", data);
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