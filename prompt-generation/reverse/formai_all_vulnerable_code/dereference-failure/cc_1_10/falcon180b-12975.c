//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: imaginative
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

struct queue* createQueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(struct queue* q) {
    return q->front == NULL;
}

void enqueue(struct queue* q, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(struct queue* q) {
    int data = -1;
    if (!isEmpty(q)) {
        struct node* temp = q->front;
        data = temp->data;
        q->front = q->front->next;
        free(temp);
    }
    return data;
}

void display(struct queue* q) {
    struct node* temp = q->front;
    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    printf("Dequeued element: %d\n", dequeue(q));
    display(q);
    printf("Dequeued element: %d\n", dequeue(q));
    display(q);
    printf("Dequeued element: %d\n", dequeue(q));
    display(q);
    return 0;
}