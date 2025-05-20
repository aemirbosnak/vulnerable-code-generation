//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUEUE_SIZE 10

typedef struct {
    int front;
    int rear;
    int items[QUEUE_SIZE];
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isFull(Queue *q) {
    return ((q->rear + 1) % QUEUE_SIZE == q->front);
}

int isEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

void enqueue(Queue *q, int item) {
    if (isFull(q)) {
        fprintf(stderr, "Queue overflow\n");
        exit(EXIT_FAILURE);
    }

    q->items[++(q->rear) % QUEUE_SIZE] = item;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        fprintf(stderr, "Queue underflow\n");
        exit(EXIT_FAILURE);
    }

    int item = q->items[q->front++ % QUEUE_SIZE];
    if (q->front > q->rear)
        q->front = q->rear;

    return item;
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 'a');
    enqueue(&q, 'b');
    enqueue(&q, 'c');
    enqueue(&q, 'd');

    printf("Queue: ");
    for (int i = 0; i < QUEUE_SIZE; ++i) {
        if (!isEmpty(&q))
            printf("%c ", q.items[q.front % QUEUE_SIZE]);
        dequeue(&q);
    }

    return 0;
}