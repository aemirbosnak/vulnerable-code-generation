//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

void enqueue(Queue* q, int data) {
    if (q->size == 0) {
        q->front = (Node*)malloc(sizeof(Node));
        q->rear = q->front;
        q->front->data = data;
        q->front->next = NULL;
        q->size++;
    } else {
        q->rear->next = (Node*)malloc(sizeof(Node));
        q->rear->next->data = data;
        q->rear->next->next = NULL;
        q->rear = q->rear->next;
        q->size++;
    }
}

int dequeue(Queue* q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->front->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(q->front);
    q->size--;
    return data;
}

int main() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printf("Front element: %d\n", dequeue(q));
    printf("Rear element: %d\n", dequeue(q));
    printf("Front element: %d\n", dequeue(q));
    printf("Rear element: %d\n", dequeue(q));
    printf("Front element: %d\n", dequeue(q));
    printf("Rear element: %d\n", dequeue(q));
    printf("Queue is empty\n");
    return 0;
}