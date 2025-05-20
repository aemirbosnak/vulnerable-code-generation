//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: protected
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

void init(queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int is_empty(queue* q) {
    if (q->front == NULL && q->rear == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(queue* q, int data) {
    node* new_node = (node*) malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    if (is_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(queue* q) {
    int data;
    node* temp = q->front;
    if (is_empty(q)) {
        printf("Queue is empty\n");
        exit(0);
    } else if (q->front == q->rear) {
        data = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    } else {
        data = q->front->data;
        q->front = q->front->next;
        free(temp);
    }
    return data;
}

void display(queue* q) {
    node* temp = q->front;
    if (is_empty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
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
    printf("Dequeued element is: %d\n", dequeue(&q));
    display(&q);
    printf("Dequeued element is: %d\n", dequeue(&q));
    display(&q);
    printf("Dequeued element is: %d\n", dequeue(&q));
    return 0;
}