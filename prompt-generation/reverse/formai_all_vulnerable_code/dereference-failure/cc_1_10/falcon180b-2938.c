//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Queue structure
typedef struct queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Initialize queue
void init(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

// Check if queue is empty
bool isEmpty(Queue* q) {
    return q->front == NULL;
}

// Check if queue is full
bool isFull(Queue* q) {
    return q->size == 100; // maximum size of 100 nodes
}

// Enqueue operation
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

// Dequeue operation
void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Error: Queue is empty\n");
        return;
    }
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
}

// Display queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    Queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    return 0;
}