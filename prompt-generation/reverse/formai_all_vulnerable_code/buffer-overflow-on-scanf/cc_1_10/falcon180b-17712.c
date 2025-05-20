//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: safe
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

void init() {
    front = NULL;
    rear = NULL;
}

bool isEmpty() {
    if (front == NULL && rear == NULL)
        return true;
    else
        return false;
}

bool isFull() {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL)
        return true;
    else {
        free(temp);
        return false;
    }
}

void enqueue(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    int value = 0;
    Node* temp = front;

    if (isEmpty()) {
        printf("Queue is empty\n");
        exit(0);
    } else {
        value = front->data;
        front = front->next;
        free(temp);
    }

    return value;
}

void display() {
    Node* temp = front;

    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice, value;

    init();

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            value = dequeue();
            printf("The dequeued value is: %d\n", value);
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