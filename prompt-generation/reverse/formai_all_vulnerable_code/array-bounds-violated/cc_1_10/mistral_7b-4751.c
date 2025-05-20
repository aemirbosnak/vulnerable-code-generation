//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 10

typedef struct CircularQueue {
    int data[MAX_SIZE];
    int head;
    int tail;
    int count;
} CircularQueue;

void init_queue(CircularQueue *queue) {
    memset(queue, 0, sizeof(CircularQueue));
    queue->head = queue->tail = -1;
}

bool is_empty(CircularQueue *queue) {
    return queue->count == 0;
}

bool is_full(CircularQueue *queue) {
    return queue->count == MAX_SIZE;
}

int size(CircularQueue *queue) {
    return queue->count;
}

void enqueue(CircularQueue *queue, int data) {
    if (is_full(queue)) {
        fprintf(stderr, "Circular queue is full. Cannot enqueue %d.\n", data);
        return;
    }

    if (queue->head == -1) {
        queue->head = 0;
    }

    queue->tail = (queue->tail + 1) % MAX_SIZE;
    queue->data[queue->tail] = data;
    queue->count++;
}

int dequeue(CircularQueue *queue) {
    if (is_empty(queue)) {
        fprintf(stderr, "Circular queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int data = queue->data[queue->head];

    if (queue->head == queue->tail) {
        queue->head = queue->tail = -1;
    } else {
        queue->head = (queue->head + 1) % MAX_SIZE;
    }
    queue->count--;

    return data;
}

int main(void) {
    CircularQueue queue;
    init_queue(&queue);

    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("Enqueueing elements...\n");
    for (int i = 0; i < 11; i++) {
        enqueue(&queue, numbers[i]);
        printf("Enqueued %d. Current size: %d\n", numbers[i], size(&queue));
    }

    printf("\nDequeueing elements...\n");
    while (!is_empty(&queue)) {
        int data = dequeue(&queue);
        printf("Dequeued %d. Current size: %d\n", data, size(&queue));
    }

    return 0;
}