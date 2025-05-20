//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *head;
    struct Node *tail;
    int size;
};

void enqueue(struct Queue *q, int data) {
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (q->size == 0) {
        q->head = q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }

    q->size++;
}

int dequeue(struct Queue *q) {
    if (q->size == 0) {
        return -1;
    }

    struct Node *node = q->head;
    int data = node->data;

    q->head = node->next;
    free(node);

    q->size--;

    return data;
}

void print_queue(struct Queue *q) {
    struct Node *node = q->head;

    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }

    printf("\n");
}

int main() {
    struct Queue q;
    q.head = NULL;
    q.tail = NULL;
    q.size = 0;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    print_queue(&q);

    int data = dequeue(&q);
    printf("Dequeued data: %d\n", data);

    print_queue(&q);

    return 0;
}