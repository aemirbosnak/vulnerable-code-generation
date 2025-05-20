//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10

typedef struct queue_t {
    int size;
    int front;
    int rear;
    int *data;
} Queue;

Queue *create_queue() {
    Queue *queue = malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL;
    }
    queue->size = MAX_QUEUE_SIZE;
    queue->front = -1;
    queue->rear = -1;
    queue->data = malloc(queue->size * sizeof(int));
    if (queue->data == NULL) {
        free(queue);
        return NULL;
    }
    return queue;
}

void enqueue(Queue *queue, int value) {
    if (queue == NULL) {
        return;
    }
    if (queue->rear == queue->size - 1) {
        return;
    }
    queue->rear++;
    queue->data[queue->rear] = value;
}

int dequeue(Queue *queue) {
    if (queue == NULL) {
        return -1;
    }
    if (queue->front == queue->rear) {
        return -1;
    }
    int value = queue->data[queue->front];
    queue->front++;
    return value;
}

void print_queue(Queue *queue) {
    if (queue == NULL) {
        return;
    }
    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

int main() {
    Queue *queue = create_queue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    print_queue(queue);
    int value = dequeue(queue);
    printf("Dequeued value: %d\n", value);
    print_queue(queue);
    return 0;
}