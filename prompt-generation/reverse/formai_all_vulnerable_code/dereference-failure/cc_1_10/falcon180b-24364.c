//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (q->rear == NULL) {
        q->front = node;
        q->rear = node;
        return;
    }
    q->rear->next = node;
    q->rear = node;
    return;
}

int dequeue(Queue* q) {
    Node* node = q->front;
    int data = node->data;
    q->front = node->next;
    free(node);
    if (q->front == NULL) {
        q->rear = NULL;
        return -1;
    }
    return data;
}

int peek(Queue* q) {
    if (q->front == NULL) {
        return -1;
    }
    return q->front->data;
}

int isEmpty(Queue* q) {
    if (q->front == NULL) {
        return 1;
    }
    return 0;
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printf("%d\n", peek(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", peek(q));
    free(q);
    return 0;
}