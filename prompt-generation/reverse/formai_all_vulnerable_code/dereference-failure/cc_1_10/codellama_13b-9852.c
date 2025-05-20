//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: sophisticated
/*
 * C Queue Implementation Example Program
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *head;
    struct node *tail;
};

void enqueue(struct queue *q, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (q->tail == NULL) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

int dequeue(struct queue *q) {
    if (q->head == NULL) {
        return -1;
    }

    struct node *temp = q->head;
    int data = temp->data;
    q->head = temp->next;
    free(temp);
    return data;
}

int main() {
    struct queue q;
    q.head = NULL;
    q.tail = NULL;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    int data = dequeue(&q);
    printf("Dequeued data: %d\n", data);

    data = dequeue(&q);
    printf("Dequeued data: %d\n", data);

    data = dequeue(&q);
    printf("Dequeued data: %d\n", data);

    return 0;
}