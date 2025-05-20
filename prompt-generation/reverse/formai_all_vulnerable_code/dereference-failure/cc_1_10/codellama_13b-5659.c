//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int data;
    struct node *next;
} node_t;

typedef struct {
    node_t *head;
    node_t *tail;
    int size;
} queue_t;

void enqueue(queue_t *q, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (q->head == NULL) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }

    q->size++;
}

int dequeue(queue_t *q) {
    if (q->head == NULL) {
        return -1;
    }

    node_t *temp = q->head;
    int data = temp->data;
    q->head = temp->next;
    free(temp);
    q->size--;

    return data;
}

int main() {
    queue_t *q = (queue_t *)malloc(sizeof(queue_t));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    int data = dequeue(q);
    printf("Dequeued data: %d\n", data);

    data = dequeue(q);
    printf("Dequeued data: %d\n", data);

    data = dequeue(q);
    printf("Dequeued data: %d\n", data);

    free(q);

    return 0;
}