//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Queue structure definition
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    if (q->front == NULL)
        return true;
    else
        return false;
}

// Function to add an element to the rear of the queue
void enqueue(Queue* q, int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    temp->data = value;
    temp->next = NULL;
    if (isEmpty(q)) {
        q->front = temp;
        q->rear = temp;
    }
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

// Function to remove an element from the front of the queue
int dequeue(Queue* q) {
    int value;
    Node* temp = q->front;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        exit(0);
    }
    value = temp->data;
    q->front = q->front->next;
    free(temp);
    return value;
}

// Function to display the elements in the queue
void display(Queue* q) {
    Node* temp = q->front;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        exit(0);
    }
    printf("Queue elements are: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    dequeue(q);
    dequeue(q);
    display(q);
    return 0;
}