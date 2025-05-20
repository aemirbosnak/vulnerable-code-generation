//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (front == NULL && rear == NULL) {
        front = rear = newNode;
    }
    else if (rear == NULL) {
        rear = newNode;
        front->next = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued to the queue\n", data);
}

void dequeue() {
    if (front == NULL || front == rear) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = front;
    printf("%d dequeued from the queue\n", front->data);
    if (front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->next;
    }
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue elements are: ");
        Node* temp = front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    dequeue();
    display();
    return 0;
}