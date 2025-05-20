//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a node in the queue
struct node {
    int data;
    struct node* next;
};

// Define a structure for the queue
struct queue {
    struct node* front;
    struct node* rear;
};

// Function to create a new queue
struct queue* create_queue() {
    struct queue* q = malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to enqueue an element in the queue
void enqueue(struct queue* q, int data) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (q->rear == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

// Function to dequeue an element from the queue
int dequeue(struct queue* q) {
    if (q->front == NULL) {
        return -1;
    }
    struct node* temp = q->front;
    q->front = temp->next;
    int data = temp->data;
    free(temp);
    return data;
}

// Function to check if the queue is empty
bool is_empty(struct queue* q) {
    return (q->front == NULL);
}

int main() {
    struct queue* q = create_queue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));
    return 0;
}