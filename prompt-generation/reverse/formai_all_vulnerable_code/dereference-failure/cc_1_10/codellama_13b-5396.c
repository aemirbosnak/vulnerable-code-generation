//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: shocked
// Shocked Queue Implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure for a node in the queue
struct node {
    int value;
    struct node *next;
};

// Structure for the queue
struct queue {
    struct node *front;
    struct node *rear;
};

// Function to create a new node
struct node *new_node(int value) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->value = value;
    node->next = NULL;
    return node;
}

// Function to create a new queue
struct queue *new_queue() {
    struct queue *queue = (struct queue *)malloc(sizeof(struct queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to enqueue an element in the queue
void enqueue(struct queue *queue, int value) {
    struct node *node = new_node(value);
    if (queue->front == NULL) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

// Function to dequeue an element from the queue
int dequeue(struct queue *queue) {
    if (queue->front == NULL) {
        return -1;
    }
    struct node *node = queue->front;
    int value = node->value;
    queue->front = node->next;
    free(node);
    return value;
}

// Function to print the queue
void print_queue(struct queue *queue) {
    struct node *node = queue->front;
    while (node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}

// Function to free the queue
void free_queue(struct queue *queue) {
    struct node *node = queue->front;
    while (node != NULL) {
        struct node *next = node->next;
        free(node);
        node = next;
    }
    free(queue);
}

// Driver code
int main() {
    struct queue *queue = new_queue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    print_queue(queue);
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    free_queue(queue);
    return 0;
}