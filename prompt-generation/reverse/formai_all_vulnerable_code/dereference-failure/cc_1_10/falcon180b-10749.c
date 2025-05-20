//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the queue

// Node structure definition
struct node {
    int data;
    struct node* next;
};

// Queue structure definition
struct queue {
    struct node* front;
    struct node* rear;
};

// Function to create an empty queue
struct queue* createQueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(struct queue* q) {
    if (q->front == NULL && q->rear == NULL)
        return 1;
    else
        return 0;
}

// Function to check if the queue is full
int isFull(struct queue* q) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;
    else {
        free(temp);
        return 0;
    }
}

// Function to add an element to the rear of the queue
void enqueue(struct queue* q, int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Queue is full\n");
        return;
    }
    temp->data = data;
    temp->next = NULL;
    if (isEmpty(q)) {
        q->front = temp;
        q->rear = temp;
    }
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

// Function to remove an element from the front of the queue
int dequeue(struct queue* q) {
    int data;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    struct node* temp = q->front;
    data = temp->data;
    q->front = q->front->next;
    free(temp);
    return data;
}

// Function to display the current state of the queue
void display(struct queue* q) {
    if (isEmpty(q))
        printf("Queue is empty\n");
    else {
        printf("Queue elements are: ");
        struct node* temp = q->front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    struct queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    dequeue(q);
    dequeue(q);
    display(q);
    return 0;
}