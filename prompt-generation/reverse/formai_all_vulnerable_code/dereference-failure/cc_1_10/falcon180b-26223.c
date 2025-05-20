//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int data) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = newnode;
        rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue() {
    if (front == NULL && rear == NULL)
        printf("Queue is empty\n");
    else if (front == rear) {
        Node *temp = front;
        front = NULL;
        rear = NULL;
        free(temp);
    } else {
        Node *temp = front;
        front = front->next;
        free(temp);
    }
}

void display() {
    if (front == NULL && rear == NULL)
        printf("Queue is empty\n");
    else {
        Node *temp = front;
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int choice, data;

    do {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to be enqueued: ");
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
            printf("Program terminated\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}