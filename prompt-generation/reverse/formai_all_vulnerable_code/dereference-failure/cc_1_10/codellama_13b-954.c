//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: complete
/*
 * Queue Implementation in C
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
    int size;
};

void init(struct queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

int isEmpty(struct queue *q) {
    return q->size == 0;
}

int isFull(struct queue *q) {
    return q->size == MAX_SIZE;
}

void enqueue(struct queue *q, int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;

    if (isEmpty(q)) {
        q->front = new_node;
    } else {
        q->rear->next = new_node;
    }
    q->rear = new_node;
    q->size++;
}

int dequeue(struct queue *q) {
    if (isEmpty(q)) {
        return -1;
    }
    struct node *temp = q->front;
    int value = temp->data;
    q->front = temp->next;
    free(temp);
    q->size--;
    return value;
}

int main() {
    struct queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Queue: ");
    while (!isEmpty(&q)) {
        printf("%d ", dequeue(&q));
    }
    printf("\n");

    return 0;
}