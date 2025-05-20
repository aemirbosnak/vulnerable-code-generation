//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure definition
struct node {
    int data;
    struct node *next;
};

// Queue structure definition
struct queue {
    struct node *front;
    struct node *rear;
};

// Function to create an empty queue
struct queue* createQueue() {
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
bool isEmpty(struct queue *q) {
    if (q->front == NULL)
        return true;
    else
        return false;
}

// Function to add an element to the rear of the queue
void enqueue(struct queue *q, int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newnode;
        return;
    }

    q->rear->next = newnode;
    q->rear = newnode;
}

// Function to remove an element from the front of the queue
int dequeue(struct queue *q) {
    int data = 0;

    if (isEmpty(q))
        return -1;

    data = q->front->data;
    struct node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);

    return data;
}

// Function to display the current state of the queue
void display(struct queue *q) {
    if (isEmpty(q))
        printf("Queue is empty\n");
    else {
        struct node *temp = q->front;
        printf("Queue: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    struct queue *q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    display(q);

    dequeue(q);

    display(q);

    dequeue(q);

    display(q);

    dequeue(q);

    display(q);

    dequeue(q);

    return 0;
}