//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: Dennis Ritchie
/*
 * A Queue Implementation in C
 *
 * A queue is a data structure that allows elements to be inserted and removed in a
 * first-in-first-out (FIFO) order. This implementation uses an array as the
 * underlying data structure.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to create a new queue
Queue* create_queue() {
    Queue* queue = malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
int is_empty(Queue* queue) {
    return queue->front == queue->rear;
}

// Function to check if the queue is full
int is_full(Queue* queue) {
    return queue->rear == MAX_SIZE - 1;
}

// Function to add an element to the queue
void enqueue(Queue* queue, int element) {
    if (is_full(queue)) {
        printf("Queue is full\n");
    } else {
        queue->rear++;
        queue->data[queue->rear] = element;
    }
}

// Function to remove an element from the queue
int dequeue(Queue* queue) {
    if (is_empty(queue)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int element = queue->data[queue->front];
        queue->front++;
        return element;
    }
}

// Function to print the queue
void print_queue(Queue* queue) {
    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

int main() {
    Queue* queue = create_queue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    print_queue(queue);
    dequeue(queue);
    print_queue(queue);
    dequeue(queue);
    print_queue(queue);
    dequeue(queue);
    print_queue(queue);
    return 0;
}