//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: active
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
    int size;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Error: Memory not allocated\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

bool isEmpty(Queue* q) {
    return (q->front == NULL && q->rear == NULL);
}

bool isFull(Queue* q) {
    return (q->size == MAX_SIZE);
}

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory not allocated\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

int dequeue(Queue* q) {
    int data;
    if (isEmpty(q)) {
        printf("Error: Queue is empty\n");
        exit(1);
    }
    Node* tempNode = q->front;
    data = tempNode->data;
    q->front = tempNode->next;
    free(tempNode);
    q->size--;
    return data;
}

int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Error: Queue is empty\n");
        exit(1);
    }
    return q->front->data;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        Node* tempNode = q->front;
        while (tempNode!= NULL) {
            printf("%d ", tempNode->data);
            tempNode = tempNode->next;
        }
        printf("\n");
    }
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);
    int dequeuedData = dequeue(q);
    printf("Dequeued element: %d\n", dequeuedData);
    display(q);
    int peekedData = peek(q);
    printf("Peeked element: %d\n", peekedData);
    return 0;
}