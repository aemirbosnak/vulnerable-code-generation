//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data;
    struct node* link;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    if(newNode == NULL) {
        printf("Memory Error\n");
        exit(0);
    }

    newNode->data = data;
    newNode->link = NULL;

    if(front == NULL && rear == NULL) {
        front = newNode;
        rear = newNode;
    }
    else if(rear == NULL) {
        rear = newNode;
        front->link = newNode;
    }
    else {
        rear->link = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if(front == NULL && rear == NULL) {
        printf("Queue is empty\n");
    }
    else if(front == rear) {
        Node* temp = front;
        front = NULL;
        rear = NULL;
        free(temp);
    }
    else {
        Node* temp = front;
        front = front->link;
        free(temp);
    }
}

void display() {
    if(front == NULL && rear == NULL) {
        printf("Queue is empty\n");
    }
    else {
        Node* temp = front;
        printf("Queue elements are: ");
        while(temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

int main() {
    int choice, data;

    while(1) {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
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
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}