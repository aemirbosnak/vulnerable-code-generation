//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue() {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(Queue *q) {
    if (q->front == NULL)
        return 1;
    else
        return 0;
}

int enqueue(Queue *q, int x) {
    Node *newnode = (Node *) malloc(sizeof(Node));
    if (newnode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newnode->data = x;
    newnode->next = NULL;
    if (isEmpty(q))
        q->front = newnode;
    else
        q->rear->next = newnode;
    q->rear = newnode;
    return 0;
}

int dequeue(Queue *q) {
    Node *temp = q->front;
    if (isEmpty(q))
        printf("Queue is empty\n");
    else {
        q->front = q->front->next;
        free(temp);
    }
    return 0;
}

int display(Queue *q) {
    Node *temp = q->front;
    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    Queue *q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    display(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    display(q);
    return 0;
}