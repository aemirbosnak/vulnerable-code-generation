//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    void **data;
    int size;
    int front;
    int rear;
} Queue;

Queue *createQueue(int size) {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->data = (void **) malloc(size * sizeof(void *));
    q->size = size;
    q->front = q->rear = -1;
    return q;
}

int isEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

int isFull(Queue *q) {
    return ((q->rear + 1) % q->size == q->front);
}

void enqueue(Queue *q, void *data) {
    if (isFull(q)) {
        printf("Queue is full, cannot enqueue\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->size;
    }
    q->data[q->rear] = data;
}

void *dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty, cannot dequeue\n");
        return NULL;
    }
    void *data = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    return data;
}

void display(Queue *q) {
    int i;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:\n");
    for (i = q->front; i <= q->rear; i = (i + 1) % q->size) {
        printf("%d -> %p\n", i, q->data[i]);
    }
}

int main() {
    Queue *q = createQueue(5);
    enqueue(q, "Hello");
    enqueue(q, 123);
    enqueue(q, "world");
    display(q);
    printf("Dequeued element: %s\n", (char *) dequeue(q));
    printf("Dequeued element: %d\n", *(int *) dequeue(q));
    display(q);
    return 0;
}