//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newNode;
    }
    else if (rear == NULL) {
        rear = newNode;
        rear->next = front;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    Node* temp = front;
    if (front == NULL && rear == NULL) {
        printf("Queue is empty.\n");
    }
    else if (front == rear) {
        front = rear = NULL;
        free(temp);
    }
    else {
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display() {
    Node* temp = front;
    if (front == NULL) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue elements are: ");
        while (temp!= rear) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}

int main() {
    int choice, data;

    do {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data to enqueue: ");
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
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}