//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct queue {
    struct node* front;
    struct node* rear;
};

void enqueue(struct queue* q, int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = temp;
        q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

int dequeue(struct queue* q) {
    if (q->front == NULL) {
        return -1;
    }

    struct node* temp = q->front;
    int data = temp->data;
    q->front = temp->next;
    free(temp);

    if (q->front == NULL) {
        q->rear = NULL;
    }

    return data;
}

int main() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    printf("Dequeued data: %d\n", dequeue(q));
    printf("Dequeued data: %d\n", dequeue(q));
    printf("Dequeued data: %d\n", dequeue(q));

    free(q);

    return 0;
}