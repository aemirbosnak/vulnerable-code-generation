//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: interoperable
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

int isEmpty(queue* q) {
    return q->front == NULL;
}

void enqueue(queue* q, int data) {
    node* temp = (node*) malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    if (isEmpty(q)) {
        q->front = temp;
        q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

int dequeue(queue* q) {
    node* temp = q->front;
    int data;

    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        data = temp->data;
        q->front = temp->next;
        free(temp);
        return data;
    }
}

void display(queue* q) {
    node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    } else {
        printf("Queue: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    int data = dequeue(&q);
    printf("Dequeued element: %d\n", data);

    display(&q);

    enqueue(&q, 40);
    enqueue(&q, 50);

    display(&q);

    return 0;
}