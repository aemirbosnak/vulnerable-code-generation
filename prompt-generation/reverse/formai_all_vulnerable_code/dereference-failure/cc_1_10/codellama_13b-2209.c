//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: satisfied
/*
 * queue.c
 *
 * A simple implementation of a queue data structure
 * using a dynamic array
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int *arr;
    int size;
    int capacity;
} Queue;

Queue* create_queue() {
    Queue *q = malloc(sizeof(Queue));
    q->arr = malloc(MAX_SIZE * sizeof(int));
    q->size = 0;
    q->capacity = MAX_SIZE;
    return q;
}

void enqueue(Queue *q, int value) {
    if (q->size == q->capacity) {
        printf("Queue is full\n");
        return;
    }
    q->arr[q->size] = value;
    q->size++;
}

int dequeue(Queue *q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->arr[0];
    for (int i = 0; i < q->size - 1; i++) {
        q->arr[i] = q->arr[i + 1];
    }
    q->size--;
    return value;
}

int main() {
    Queue *q = create_queue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    int value = dequeue(q);
    printf("Dequeued value: %d\n", value);

    value = dequeue(q);
    printf("Dequeued value: %d\n", value);

    value = dequeue(q);
    printf("Dequeued value: %d\n", value);

    value = dequeue(q);
    printf("Dequeued value: %d\n", value);

    value = dequeue(q);
    printf("Dequeued value: %d\n", value);

    return 0;
}