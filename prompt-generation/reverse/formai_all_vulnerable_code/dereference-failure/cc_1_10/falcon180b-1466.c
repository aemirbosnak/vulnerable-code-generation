//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    if (q->front == NULL)
        return -1;
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

void display(Queue* q) {
    Node* temp = q->front;
    printf("Queue elements are: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);
    printf("Dequeued element is: %d\n", dequeue(q));
    display(q);
    printf("Dequeued element is: %d\n", dequeue(q));
    display(q);
    printf("Dequeued element is: %d\n", dequeue(q));
    display(q);
    printf("Dequeued element is: %d\n", dequeue(q));
    display(q);
    printf("Dequeued element is: %d\n", dequeue(q));
    display(q);
    printf("Dequeued element is: %d\n", dequeue(q));
    display(q);
    return 0;
}