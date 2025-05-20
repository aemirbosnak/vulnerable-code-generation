//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 1000

typedef struct {
    int data;
    int priority;
    int index;
} queueElement;

typedef struct {
    queueElement *elements;
    int size;
    int front;
    int rear;
} queue;

queue *createQueue() {
    queue *q = (queue *) malloc(sizeof(queue));
    q->elements = (queueElement *) malloc(MAX_QUEUE_SIZE * sizeof(queueElement));
    q->size = MAX_QUEUE_SIZE;
    q->front = 0;
    q->rear = -1;
    return q;
}

void enqueue(queue *q, int data, int priority) {
    if (q->rear == q->size - 1) {
        printf("Queue is full!\n");
        return;
    }
    q->rear++;
    q->elements[q->rear].data = data;
    q->elements[q->rear].priority = priority;
    q->elements[q->rear].index = q->rear;
}

int dequeue(queue *q) {
    if (q->front == q->rear + 1) {
        printf("Queue is empty!\n");
        return -1;
    }
    int index = q->front;
    q->front++;
    return q->elements[index].data;
}

int peek(queue *q) {
    if (q->front == q->rear + 1) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->elements[q->front].data;
}

int size(queue *q) {
    return q->size;
}

void printQueue(queue *q) {
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->elements[i].data);
    }
    printf("\n");
}

int main() {
    queue *q = createQueue();
    enqueue(q, 10, 1);
    enqueue(q, 20, 2);
    enqueue(q, 30, 3);
    enqueue(q, 40, 4);
    enqueue(q, 50, 5);
    printQueue(q);
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Peeked element: %d\n", peek(q));
    printQueue(q);
    printf("Size of queue: %d\n", size(q));
    return 0;
}