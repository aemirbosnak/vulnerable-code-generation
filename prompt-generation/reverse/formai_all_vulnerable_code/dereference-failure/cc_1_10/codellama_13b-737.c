//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: irregular
/*
 * Queue Implementation in C
 *
 * This program shows how to implement a queue in C using an array.
 * A queue is a data structure that allows elements to be added to the back
 * and removed from the front.
 *
 * Author: 
 * Date:
 */

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a queue
typedef struct {
    int *array;
    int front;
    int rear;
    int count;
} Queue;

// Function to create a new queue
Queue *createQueue(int size) {
    Queue *q = malloc(sizeof(Queue));
    q->array = malloc(sizeof(int) * size);
    q->front = -1;
    q->rear = -1;
    q->count = 0;
    return q;
}

// Function to add an element to the queue
void enqueue(Queue *q, int element) {
    if (q->rear == q->count - 1) {
        printf("Queue is full.\n");
        return;
    }
    q->array[++q->rear] = element;
    q->count++;
}

// Function to remove an element from the queue
int dequeue(Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty.\n");
        return -1;
    }
    int element = q->array[++q->front];
    q->count--;
    return element;
}

// Function to print the queue
void printQueue(Queue *q) {
    printf("Queue: ");
    for (int i = q->front + 1; i <= q->rear; i++) {
        printf("%d ", q->array[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    // Create a queue with capacity 5
    Queue *q = createQueue(5);

    // Add elements to the queue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    // Remove an element from the queue
    int element = dequeue(q);
    printf("Removed element: %d\n", element);

    // Print the queue
    printQueue(q);

    // Add another element to the queue
    enqueue(q, 60);

    // Print the queue again
    printQueue(q);

    // Remove remaining elements from the queue
    element = dequeue(q);
    printf("Removed element: %d\n", element);
    element = dequeue(q);
    printf("Removed element: %d\n", element);
    element = dequeue(q);
    printf("Removed element: %d\n", element);
    element = dequeue(q);
    printf("Removed element: %d\n", element);

    return 0;
}