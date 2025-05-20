//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Node structure for the queue
typedef struct node {
    int data;
    struct node* next;
} Node;

// Declare the queue
Node* queue = NULL;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an element to the end of the queue
void enqueue(int data) {
    Node* newNode = createNode(data);
    if (queue == NULL) {
        queue = newNode;
    }
    else {
        Node* temp = queue;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to remove an element from the front of the queue
int dequeue() {
    if (queue == NULL) {
        printf("Queue is empty\n");
        exit(0);
    }
    int data = queue->data;
    Node* temp = queue;
    queue = queue->next;
    free(temp);
    return data;
}

// Function to display the elements in the queue
void display() {
    if (queue == NULL) {
        printf("Queue is empty\n");
    }
    else {
        Node* temp = queue;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, data;

    do {
        printf("Enter your choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be added: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                printf("The element removed from the queue is %d\n", data);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (choice!= 4);

    return 0;
}