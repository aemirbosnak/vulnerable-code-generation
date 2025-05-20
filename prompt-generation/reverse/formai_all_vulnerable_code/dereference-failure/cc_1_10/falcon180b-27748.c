//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

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
    if (q->front == NULL) {
        printf("Queue is empty\n");
        exit(1);
    }

    Node* temp = q->front;
    int data = temp->data;
    q->front = temp->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->count--;

    return data;
}

int peek(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        exit(1);
    }

    return q->front->data;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

int main() {
    Queue* q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    printf("Front element is: %d\n", peek(q));

    int dequeuedData = dequeue(q);
    printf("Dequeued element is: %d\n", dequeuedData);

    printf("Front element after dequeue is: %d\n", peek(q));

    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }

    return 0;
}