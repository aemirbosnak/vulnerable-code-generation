//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: paranoid
// Paranoid Queue Implementation Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int size;
    int capacity;
    void **data;
} Queue;

Queue *create_queue(int capacity) {
    Queue *queue = malloc(sizeof(Queue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->data = malloc(capacity * sizeof(void *));
    return queue;
}

void enqueue(Queue *queue, void *item) {
    if (queue->size == queue->capacity) {
        printf("Queue is full\n");
        return;
    }
    queue->data[queue->size++] = item;
}

void *dequeue(Queue *queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
        return NULL;
    }
    void *item = queue->data[0];
    for (int i = 1; i < queue->size; i++) {
        queue->data[i - 1] = queue->data[i];
    }
    queue->size--;
    return item;
}

int is_empty(Queue *queue) {
    return queue->size == 0;
}

int main() {
    Queue *queue = create_queue(10);
    enqueue(queue, "item1");
    enqueue(queue, "item2");
    enqueue(queue, "item3");
    printf("Front item: %s\n", (char *)dequeue(queue));
    printf("Front item: %s\n", (char *)dequeue(queue));
    enqueue(queue, "item4");
    enqueue(queue, "item5");
    enqueue(queue, "item6");
    enqueue(queue, "item7");
    enqueue(queue, "item8");
    printf("Front item: %s\n", (char *)dequeue(queue));
    printf("Front item: %s\n", (char *)dequeue(queue));
    printf("Front item: %s\n", (char *)dequeue(queue));
    return 0;
}