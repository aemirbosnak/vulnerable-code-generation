//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
} Queue;

void init(Queue *q) {
    q->data = (int *)malloc(MAX_SIZE * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

int is_empty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

int is_full(Queue *q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

void enqueue(Queue *q, int data) {
    if (is_full(q)) {
        printf("Queue is full. Cannot enqueue %d.\n", data);
        return;
    }
    if (is_empty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->data[q->rear] = data;
    q->size++;
}

int dequeue(Queue *q) {
    int data;
    if (is_empty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    data = q->data[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    q->size--;
    return data;
}

void display(Queue *q) {
    int i;
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    for (i = q->front; i <= q->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    enqueue(&q, 40);
    display(&q);
    return 0;
}