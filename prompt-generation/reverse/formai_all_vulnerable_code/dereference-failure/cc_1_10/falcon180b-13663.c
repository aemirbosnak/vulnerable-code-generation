//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL) {
        printf("\n Memory Error ");
        exit(0);
    }

    newNode->data = data;
    newNode->next = NULL;

    if(front == NULL && rear == NULL) {
        front = rear = newNode;
    }
    else if(rear == NULL) {
        rear = newNode;
        front->next = rear;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("\n %d Enqueued to the Queue", data);
}

void dequeue() {
    if(front == NULL && rear == NULL) {
        printf("\n Queue is Empty");
        return;
    }

    Node* temp = front;
    front = front->next;

    if(front == NULL)
        rear = NULL;

    printf("\n %d Dequeued from the Queue", temp->data);
    free(temp);
}

void display() {
    if(front == NULL && rear == NULL) {
        printf("\n Queue is Empty");
        return;
    }

    Node* temp = front;

    printf("\n Elements in the Queue are : ");
    while(temp!= NULL) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
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

    dequeue();
    dequeue();

    if(front == NULL && rear == NULL)
        printf("\n Queue is Empty");

    return 0;
}