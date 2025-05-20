//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure definition
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure definition
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    return q->front == NULL;
}

// Function to add an element to the rear of the queue
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to remove an element from the front of the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        exit(1);
    }
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    free(temp);
    return value;
}

// Function to display the elements of the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    Node* temp = q->front;
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
    int value = dequeue(q);
    printf("Dequeued value: %d\n", value);
    display(q);
    value = dequeue(q);
    printf("Dequeued value: %d\n", value);
    display(q);
    value = dequeue(q);
    printf("Dequeued value: %d\n", value);
    display(q);
    return 0;
}