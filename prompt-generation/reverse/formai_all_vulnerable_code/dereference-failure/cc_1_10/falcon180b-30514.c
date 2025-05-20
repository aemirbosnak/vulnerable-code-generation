//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->arr = (int*)malloc(size * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = size;
    return q;
}

bool isEmpty(Queue* q) {
    return (q->front == -1 && q->rear == -1);
}

bool isFull(Queue* q) {
    return ((q->rear + 1) % q->size == q->front);
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->size;
    }
    q->arr[q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    return value;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = q->front; i <= q->rear; i = (i + 1) % q->size) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue(MAX_SIZE);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    display(q);
    dequeue(q);
    dequeue(q);
    enqueue(q, 50);
    display(q);
    return 0;
}