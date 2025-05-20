//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int size;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void init() {
    front = NULL;
    rear = NULL;
}

bool isEmpty() {
    return front == NULL;
}

bool isFull() {
    Node* temp = front;
    int count = 0;
    while (temp!= NULL) {
        count++;
        temp = temp->next;
    }
    return count == MAX_SIZE;
}

void enqueue(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->size = 1;
    newNode->next = NULL;

    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else if (front == rear) {
        Node* temp = front;
        front = NULL;
        rear = NULL;
        free(temp);
    } else {
        Node* temp = front;
        front = front->next;
        free(temp);
    }
}

void display() {
    Node* temp = front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    init();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    dequeue();
    dequeue();
    display();
    dequeue();
    dequeue();
    dequeue();
    return 0;
}