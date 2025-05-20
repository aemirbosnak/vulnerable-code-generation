//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct queue {
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(Queue *q, int data) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;

    if (q->front == NULL) {
        q->front = newnode;
        q->rear = newnode;
    } else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

int dequeue(Queue *q) {
    int data;
    Node *temp = q->front;

    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    data = temp->data;
    q->front = temp->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return data;
}

int peek(Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    return q->front->data;
}

int isEmpty(Queue *q) {
    if (q->front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int size(Queue *q) {
    Node *temp = q->front;
    int count = 0;

    while (temp!= NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

void display(Queue *q) {
    Node *temp = q->front;

    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue *q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    display(q);

    printf("Size of queue: %d\n", size(q));

    int dequeued_data = dequeue(q);
    printf("Dequeued data: %d\n", dequeued_data);

    display(q);

    printf("Front data: %d\n", peek(q));

    return 0;
}