//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int value) {
    Node *newNode = (Node*) malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Queue is full!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d enqueued to the queue\n", value);
}

int dequeue() {
    int value = -1;

    if (front == NULL) {
        printf("Queue is empty!\n");
        exit(1);
    }

    Node *tempNode = front;
    value = tempNode->data;
    front = tempNode->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(tempNode);

    printf("%d dequeued from the queue\n", value);

    return value;
}

void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        exit(1);
    }

    Node *tempNode = front;

    printf("Queue elements are: ");

    while (tempNode!= NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }

    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                value = dequeue();
                printf("Dequeued value is: %d\n", value);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}