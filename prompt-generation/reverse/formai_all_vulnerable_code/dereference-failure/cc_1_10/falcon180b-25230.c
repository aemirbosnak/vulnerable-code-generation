//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int data;
    struct node *next;
} node;

typedef struct {
    node *front;
    node *rear;
} queue;

queue *createQueue() {
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(queue *q) {
    return q->front == NULL;
}

void enqueue(queue *q, int data) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if (isEmpty(q)) {
        q->front = newnode;
        q->rear = newnode;
    } else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

int dequeue(queue *q) {
    int data;
    node *temp = q->front;
    data = temp->data;
    q->front = temp->next;
    free(temp);
    return data;
}

void display(queue *q) {
    node *temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue *q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    display(q);
    printf("Dequeued element: %d\n", dequeue(q));
    display(q);
    printf("Dequeued element: %d\n", dequeue(q));
    display(q);
    printf("Dequeued element: %d\n", dequeue(q));
    display(q);
    printf("Dequeued element: %d\n", dequeue(q));
    display(q);
    return 0;
}