//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

int isEmpty() {
    if (front == NULL)
        return 1;
    else
        return 0;
}

int isFull() {
    Node *temp = front;
    int count = 0;
    while (temp!= rear) {
        temp = temp->next;
        count++;
    }
    if (count == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}

void enqueue(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else if (isFull()) {
        printf("Queue is full\n");
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else if (front == rear) {
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
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        Node *temp = front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    dequeue();
    dequeue();
    enqueue(4);
    enqueue(5);
    display();
    return 0;
}