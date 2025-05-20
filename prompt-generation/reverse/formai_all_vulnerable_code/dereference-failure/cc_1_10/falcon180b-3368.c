//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    void *data;
    size_t size;
    int id;
} QueueItem;

typedef struct {
    QueueItem *items;
    size_t front;
    size_t rear;
    size_t count;
} Queue;

Queue *queue_create() {
    Queue *q = malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Error: Failed to allocate memory for queue.\n");
        exit(1);
    }
    q->items = malloc(MAX_SIZE * sizeof(QueueItem));
    if (q->items == NULL) {
        printf("Error: Failed to allocate memory for queue items.\n");
        exit(1);
    }
    q->front = 0;
    q->rear = 0;
    q->count = 0;
    return q;
}

void queue_destroy(Queue *q) {
    free(q->items);
    free(q);
}

bool queue_is_empty(Queue *q) {
    return q->count == 0;
}

bool queue_is_full(Queue *q) {
    return q->count == MAX_SIZE;
}

void queue_enqueue(Queue *q, void *data, size_t size, int id) {
    if (queue_is_full(q)) {
        printf("Error: Queue is full.\n");
        return;
    }
    q->rear++;
    q->items[q->rear].data = data;
    q->items[q->rear].size = size;
    q->items[q->rear].id = id;
    q->count++;
}

QueueItem *queue_dequeue(Queue *q) {
    if (queue_is_empty(q)) {
        printf("Error: Queue is empty.\n");
        return NULL;
    }
    QueueItem *item = &q->items[q->front];
    q->front++;
    q->count--;
    return item;
}

int main() {
    Queue *q = queue_create();
    queue_enqueue(q, "Hello", 6, 1);
    queue_enqueue(q, "World", 5, 2);
    QueueItem *item = queue_dequeue(q);
    printf("Dequeued item: %s\n", (char*)item->data);
    queue_destroy(q);
    return 0;
}