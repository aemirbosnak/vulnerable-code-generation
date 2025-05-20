//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: relaxed
/*
 * Queue Implementation Example Program
 *
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the queue
struct node {
    int data;
    struct node *next;
};

// Structure to represent the queue
struct queue {
    struct node *front;
    struct node *rear;
};

// Function to create a new node
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create an empty queue
struct queue *create_queue() {
    struct queue *new_queue = (struct queue *)malloc(sizeof(struct queue));
    new_queue->front = NULL;
    new_queue->rear = NULL;
    return new_queue;
}

// Function to enqueue an element
void enqueue(struct queue *queue, int data) {
    struct node *new_node = create_node(data);
    if (queue->rear == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

// Function to dequeue an element
int dequeue(struct queue *queue) {
    if (queue->front == NULL) {
        return -1;
    }
    struct node *temp = queue->front;
    queue->front = temp->next;
    int data = temp->data;
    free(temp);
    return data;
}

// Function to check if the queue is empty
int is_empty(struct queue *queue) {
    return (queue->front == NULL);
}

// Driver code
int main() {
    struct queue *queue = create_queue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    return 0;
}