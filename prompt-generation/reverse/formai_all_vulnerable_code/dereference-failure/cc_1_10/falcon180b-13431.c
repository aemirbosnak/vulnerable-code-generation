//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100

// Node structure
struct node {
    int data;
    struct node* next;
};

// Queue structure
struct queue {
    struct node* front;
    struct node* rear;
    int count;
};

// Function to create an empty queue
struct queue* createQueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    q->count = 0;
    return q;
}

// Function to check if the queue is empty
bool isEmpty(struct queue* q) {
    return q->front == NULL;
}

// Function to add an element to the rear of the queue
void enqueue(struct queue* q, int value) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = value;
    node->next = NULL;

    if (isEmpty(q)) {
        q->front = node;
        q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }

    q->count++;
}

// Function to remove an element from the front of the queue
int dequeue(struct queue* q) {
    int value = -1;

    if (!isEmpty(q)) {
        struct node* temp = q->front;
        value = temp->data;
        q->front = q->front->next;
        free(temp);
        q->count--;
    }

    return value;
}

// Function to display the elements in the queue
void display(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
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

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

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

    free(q);
    return 0;
}