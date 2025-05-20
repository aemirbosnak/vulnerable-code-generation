//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: Donald Knuth
// Donald Knuth Queue Implementation Example
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

typedef struct {
    node_t* front;
    node_t* back;
    size_t size;
} queue_t;

void queue_init(queue_t* q) {
    q->front = NULL;
    q->back = NULL;
    q->size = 0;
}

void queue_enqueue(queue_t* q, int data) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;

    if (q->size == 0) {
        q->front = node;
        q->back = node;
    } else {
        q->back->next = node;
        q->back = node;
    }

    q->size++;
}

int queue_dequeue(queue_t* q) {
    if (q->size == 0) {
        return -1;
    }

    node_t* node = q->front;
    int data = node->data;

    if (q->size == 1) {
        q->front = NULL;
        q->back = NULL;
    } else {
        q->front = q->front->next;
    }

    free(node);

    q->size--;

    return data;
}

void queue_print(queue_t* q) {
    node_t* node = q->front;

    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }

    printf("\n");
}

int main() {
    queue_t q;
    queue_init(&q);

    queue_enqueue(&q, 1);
    queue_enqueue(&q, 2);
    queue_enqueue(&q, 3);
    queue_enqueue(&q, 4);

    queue_print(&q);

    printf("Dequeued element: %d\n", queue_dequeue(&q));

    queue_print(&q);

    return 0;
}