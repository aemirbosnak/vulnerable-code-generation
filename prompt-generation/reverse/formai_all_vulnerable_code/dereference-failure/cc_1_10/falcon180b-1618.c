//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_MAX 1000

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
    int size;
};

struct queue *create_queue() {
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

int is_empty(struct queue *q) {
    if (q->front == NULL && q->rear == NULL)
        return 1;
    else
        return 0;
}

void enqueue(struct queue *q, int data) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    if (is_empty(q)) {
        q->front = node;
        q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
    q->size++;
}

int dequeue(struct queue *q) {
    if (is_empty(q))
        return -1;
    struct node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    free(temp);
    q->size--;
    if (is_empty(q))
        q->rear = NULL;
    return data;
}

void display(struct queue *q) {
    struct node *temp = q->front;
    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct queue *q = create_queue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);
    printf("Size of queue: %d\n", q->size);
    printf("Dequeued element: %d\n", dequeue(q));
    display(q);
    printf("Size of queue: %d\n", q->size);
    return 0;
}