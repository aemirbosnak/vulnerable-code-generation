//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = value;
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
    int value = -1;
    if (q->front == NULL) {
        printf("Queue is empty\n");
    } else {
        Node* temp = q->front;
        value = temp->data;
        q->front = temp->next;
        free(temp);
        if (q->front == NULL) {
            q->rear = NULL;
        }
    }
    return value;
}

void display(Queue* q) {
    Node* temp = q->front;
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
    int value = dequeue(q);
    printf("Dequeued value: %d\n", value);
    display(q);
    value = dequeue(q);
    printf("Dequeued value: %d\n", value);
    display(q);
    value = dequeue(q);
    printf("Dequeued value: %d\n", value);
    display(q);
    value = dequeue(q);
    printf("Dequeued value: %d\n", value);
    display(q);
    value = dequeue(q);
    printf("Dequeued value: %d\n", value);
    display(q);
    return 0;
}