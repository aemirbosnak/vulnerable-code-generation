//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

bool isFull(Queue* q) {
    return q->size == MAX_SIZE;
}

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

int dequeue(Queue* q) {
    int data;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        exit(0);
    }
    Node* temp = q->front;
    data = temp->data;
    q->front = q->front->next;
    free(temp);
    q->size--;
    return data;
}

int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        exit(0);
    }
    return q->front->data;
}

void printQueue(Queue* q) {
    Node* temp = q->front;
    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    printQueue(q);
    int deqData = dequeue(q);
    printf("Dequeued element: %d\n", deqData);
    printQueue(q);
    int peekData = peek(q);
    printf("Peeked element: %d\n", peekData);
    return 0;
}