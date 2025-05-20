//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int size;
} Queue;

Queue *createQueue() {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue *q, int data) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
    
    q->size++;
}

int dequeue(Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    
    int data = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    q->size--;
    
    return data;
}

int peek(Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    
    return q->front->data;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

int isFull(Queue *q) {
    return q->size == MAX_SIZE;
}

int main() {
    Queue *q = createQueue();
    
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    
    printf("Front element: %d\n", peek(q));
    printf("Queue size: %d\n", q->size);
    
    dequeue(q);
    dequeue(q);
    
    printf("Front element after dequeue: %d\n", peek(q));
    printf("Queue size after dequeue: %d\n", q->size);
    
    while (!isEmpty(q)) {
        printf("Dequeued element: %d\n", dequeue(q));
    }
    
    free(q);
    
    return 0;
}