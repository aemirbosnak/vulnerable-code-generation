//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

typedef struct {
    node* front;
    node* rear;
} queue;

void enqueue(queue* q, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (q->front == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

void dequeue(queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}

void display(queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    node* temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue q;
    q.front = NULL;
    q.rear = NULL;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    dequeue(&q);

    display(&q);

    dequeue(&q);

    display(&q);

    dequeue(&q);

    display(&q);

    return 0;
}