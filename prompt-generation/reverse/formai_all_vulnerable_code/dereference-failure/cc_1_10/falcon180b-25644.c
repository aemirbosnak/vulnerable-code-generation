//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

typedef struct {
    node* front;
    node* rear;
    int count;
} queue;

void initQueue(queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
}

bool isEmpty(queue* q) {
    return q->front == NULL && q->rear == NULL;
}

bool isFull(queue* q) {
    return q->count == MAX_SIZE;
}

void enqueue(queue* q, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    if(isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->count++;
}

int dequeue(queue* q) {
    int data;
    node* temp = q->front;
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        exit(0);
    }
    data = temp->data;
    q->front = temp->next;
    if(q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->count--;
    return data;
}

int peek(queue* q) {
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        exit(0);
    }
    return q->front->data;
}

void display(queue* q) {
    node* temp = q->front;
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        exit(0);
    }
    printf("Queue elements are: ");
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue* q = (queue*)malloc(sizeof(queue));
    initQueue(q);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    int data = dequeue(q);
    printf("Dequeued element is: %d\n", data);
    display(q);
    printf("Peek element is: %d\n", peek(q));
    return 0;
}