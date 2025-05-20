//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

typedef struct {
    node* front;
    node* rear;
} queue;

void init(queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int is_empty(queue* q) {
    return q->front == NULL;
}

int is_full(queue* q) {
    return (q->rear->next == q->front);
}

void enqueue(queue* q, int data) {
    node* temp = (node*) malloc(sizeof(node));
    if (temp == NULL) {
        printf("Queue overflow\n");
        exit(0);
    }
    temp->data = data;
    temp->next = NULL;
    if (is_empty(q)) {
        q->front = temp;
        q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

int dequeue(queue* q) {
    int data = 0;
    node* temp = q->front;
    if (is_empty(q)) {
        printf("Queue underflow\n");
        exit(0);
    } else if (q->front == q->rear) {
        data = q->front->data;
        q->front = NULL;
        q->rear = NULL;
    } else {
        data = q->front->data;
        q->front = q->front->next;
    }
    free(temp);
    return data;
}

void display(queue* q) {
    node* temp = q->front;
    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    return 0;
}