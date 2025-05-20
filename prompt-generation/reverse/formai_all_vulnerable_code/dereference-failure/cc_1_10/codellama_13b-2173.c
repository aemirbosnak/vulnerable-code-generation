//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: dynamic
/*
 * C Queue Implementation Example Program in a Dynamic Style
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

void enqueue(Queue *q, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;

    if (q->front == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(Queue *q) {
    if (q->front == NULL) {
        return -1;
    }

    int value = q->front->value;
    Node *temp = q->front;
    q->front = q->front->next;
    free(temp);

    return value;
}

int main() {
    Queue q;
    q.front = NULL;
    q.rear = NULL;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);

    printf("Dequeued value: %d\n", dequeue(&q));
    printf("Dequeued value: %d\n", dequeue(&q));
    printf("Dequeued value: %d\n", dequeue(&q));
    printf("Dequeued value: %d\n", dequeue(&q));

    return 0;
}