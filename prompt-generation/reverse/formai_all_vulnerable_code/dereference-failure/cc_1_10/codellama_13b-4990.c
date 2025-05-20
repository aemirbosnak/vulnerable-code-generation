//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: relaxed
/*
 * queue.c
 *
 * A simple queue implementation in C.
 *
 * (C) 2022, Your Name.
 */

#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int front;
    int rear;
    int *data;
};

void enqueue(struct queue *q, int item) {
    if (q->rear == q->size) {
        q->rear = 0;
    }
    q->data[q->rear] = item;
    q->rear++;
}

int dequeue(struct queue *q) {
    if (q->front == q->rear) {
        return -1;
    }
    int item = q->data[q->front];
    q->front++;
    return item;
}

int is_empty(struct queue *q) {
    return (q->front == q->rear);
}

int is_full(struct queue *q) {
    return ((q->rear + 1) % q->size == q->front);
}

void print_queue(struct queue *q) {
    printf("[");
    for (int i = q->front; i < q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("]\n");
}

int main() {
    struct queue *q = malloc(sizeof(struct queue));
    q->size = 5;
    q->front = 0;
    q->rear = 0;
    q->data = malloc(q->size * sizeof(int));

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    print_queue(q);

    int item = dequeue(q);
    printf("Dequeued item: %d\n", item);

    enqueue(q, 4);
    enqueue(q, 5);

    print_queue(q);

    free(q->data);
    free(q);

    return 0;
}