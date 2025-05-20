//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int count;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
    return q;
}

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->count++;
}

int dequeue(Queue* q) {
    int data;
    Node* temp = q->front;

    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    data = q->front->data;
    q->front = q->front->next;

    free(temp);
    q->count--;

    return data;
}

int isEmpty(Queue* q) {
    if (q->front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int size(Queue* q) {
    return q->count;
}

void destroyQueue(Queue* q) {
    Node* temp = q->front;

    while (temp!= NULL) {
        q->front = temp->next;
        free(temp);
        temp = q->front;
    }

    free(q);
}

int main() {
    Queue* q = createQueue();

    int i;

    for (i = 0; i < MAX_QUEUE_SIZE; i++) {
        enqueue(q, i);
    }

    printf("Size of Queue: %d\n", size(q));

    for (i = 0; i < MAX_QUEUE_SIZE; i++) {
        dequeue(q);
    }

    printf("Size of Queue: %d\n", size(q));

    destroyQueue(q);

    return 0;
}