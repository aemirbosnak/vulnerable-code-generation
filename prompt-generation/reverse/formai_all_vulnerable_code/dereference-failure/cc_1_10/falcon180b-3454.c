//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define a node structure for the queue
struct node {
    int data;
    struct node* next;
};

// Define the queue struct
struct queue {
    struct node* front;
    struct node* rear;
    int size;
};

// Initialize the queue
void initQueue(struct queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

// Check if the queue is empty
int isEmpty(struct queue* q) {
    return q->size == 0;
}

// Check if the queue is full
int isFull(struct queue* q) {
    return q->size == MAX_SIZE;
}

// Enqueue an element
void enqueue(struct queue* q, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory error\n");
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

// Dequeue an element
int dequeue(struct queue* q) {
    struct node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    return data;
}

// Display the queue
void display(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is: ");
        struct node* temp = q->front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    enqueue(&q, 40);
    display(&q);
    return 0;
}