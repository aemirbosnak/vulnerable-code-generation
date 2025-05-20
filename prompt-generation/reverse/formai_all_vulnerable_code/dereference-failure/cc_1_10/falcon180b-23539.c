//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int data;
    struct node* next;
};

struct queue {
    struct node* front;
    struct node* rear;
};

void init(struct queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int is_empty(struct queue* q) {
    return (q->front == NULL);
}

int is_full(struct queue* q) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;
    else {
        free(temp);
        return 0;
    }
}

void enqueue(struct queue* q, int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Queue is full!");
        exit(0);
    }
    temp->data = data;
    temp->next = NULL;
    if (is_empty(q)) {
        q->front = temp;
        q->rear = temp;
    }
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

int dequeue(struct queue* q) {
    int data;
    struct node* temp = q->front;
    if (is_empty(q)) {
        printf("Queue is empty!");
        exit(0);
    }
    else if (q->front == q->rear) {
        data = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    }
    else {
        data = q->front->data;
        q->front = q->front->next;
        free(temp);
    }
    return data;
}

void display(struct queue* q) {
    struct node* temp = q->front;
    if (is_empty(q)) {
        printf("Queue is empty!");
    }
    else {
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    display(&q);
    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));
    display(&q);
    return 0;
}