//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

int isEmpty() {
    return front == NULL;
}

int isFull() {
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
    int data = -1;

    if (!isEmpty()) {
        Node* temp = front;
        data = temp->data;
        front = front->next;
        free(temp);
    }

    return data;
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
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display();

    int dequeuedData = dequeue();
    printf("Dequeued data: %d\n", dequeuedData);

    display();

    enqueue(6);
    enqueue(7);

    display();

    return 0;
}