//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: all-encompassing
/*
 * A queue implementation using a singly-linked list
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a queue
typedef struct Queue {
    int size; // number of elements in the queue
    int front; // front element
    int rear; // rear element
    int* elements; // array of elements
} Queue;

// Function to create a new queue
Queue* createQueue(int size) {
    Queue* queue = malloc(sizeof(Queue));
    queue->size = size;
    queue->front = -1;
    queue->rear = -1;
    queue->elements = malloc(sizeof(int) * size);
    return queue;
}

// Function to enqueue an element
void enqueue(Queue* queue, int element) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full.\n");
        return;
    }
    queue->rear++;
    queue->elements[queue->rear] = element;
    if (queue->front == -1) {
        queue->front = 0;
    }
}

// Function to dequeue an element
int dequeue(Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty.\n");
        return -1;
    }
    int element = queue->elements[queue->front];
    queue->front++;
    if (queue->front == queue->size) {
        queue->front = 0;
    }
    return element;
}

// Function to print the queue
void printQueue(Queue* queue) {
    printf("Queue: ");
    for (int i = queue->front; i < queue->rear; i++) {
        printf("%d ", queue->elements[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    Queue* queue = createQueue(5);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    printQueue(queue);
    int element = dequeue(queue);
    printf("Dequeued element: %d\n", element);
    printQueue(queue);
    return 0;
}