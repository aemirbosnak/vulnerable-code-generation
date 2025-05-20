//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: standalone
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
};

void initQueue(struct queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(struct queue *q) {
    return q->front == NULL;
}

int isFull(struct queue *q) {
    struct node *temp = q->rear;
    while (temp!= NULL) {
        temp = temp->next;
    }
    return temp == q->front;
}

void enqueue(struct queue *q, int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
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

int dequeue(struct queue *q) {
    int data;
    struct node *temp = q->front;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        q->front = q->front->next;
        data = temp->data;
        free(temp);
    }
    return data;
}

int peek(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return q->front->data;
    }
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
    struct queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(&q);

    int dequeued = dequeue(&q);
    printf("Dequeued: %d\n", dequeued);

    display(&q);

    int peeked = peek(&q);
    printf("Peeked: %d\n", peeked);

    return 0;
}