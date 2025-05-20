//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool isQueueEmpty(Queue *q) {
    return q->front == NULL && q->rear == NULL;
}

bool isQueueFull(Queue *q) {
    Node *temp = q->rear;
    while (temp!= NULL) {
        temp = temp->next;
    }
    return temp == NULL;
}

void enqueue(Queue *q, int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (isQueueEmpty(q)) {
        q->front = node;
        q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
}

int dequeue(Queue *q) {
    int data = -1;
    if (!isQueueEmpty(q)) {
        Node *temp = q->front;
        data = temp->data;
        q->front = temp->next;
        free(temp);
        if (isQueueEmpty(q)) {
            q->rear = NULL;
        }
    }
    return data;
}

void printQueue(Queue *q) {
    Node *temp = q->front;
    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue *q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printQueue(q);
    int data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    printQueue(q);
    enqueue(q, 40);
    printQueue(q);
    return 0;
}