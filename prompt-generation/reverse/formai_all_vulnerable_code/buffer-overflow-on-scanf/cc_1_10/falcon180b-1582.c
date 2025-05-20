//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued to the queue\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        Node* temp = front;
        printf("%d dequeued from the queue\n", temp->data);
        front = front->next;
        free(temp);
        if (front == NULL)
            rear = NULL;
    }
}

void display() {
    if (front == NULL)
        printf("Queue is empty\n");
    else {
        printf("Elements in the queue are: ");
        Node* temp = front;
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
        printf("Enter 1 to enqueue\n");
        printf("Enter 2 to dequeue\n");
        printf("Enter 3 to display\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}