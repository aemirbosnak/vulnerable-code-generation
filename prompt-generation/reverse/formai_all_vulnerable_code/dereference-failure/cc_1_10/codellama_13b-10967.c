//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: Cryptic
// Cryptic C Queue Implementation Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Queue structure
typedef struct Queue {
    int front;
    int rear;
    int size;
    int *array;
} Queue;

// Function to create a new queue
Queue* createQueue(int size) {
    Queue *q = malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    q->size = size;
    q->array = malloc(size * sizeof(int));
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == q->rear;
}

// Function to add an element to the queue
void enqueue(Queue *q, int data) {
    if (q->rear == q->size - 1) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->array[q->rear] = data;
}

// Function to remove an element from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    q->front++;
    return q->array[q->front];
}

// Function to print the queue
void printQueue(Queue *q) {
    printf("Queue: ");
    for (int i = q->front + 1; i <= q->rear; i++) {
        printf("%d ", q->array[i]);
    }
    printf("\n");
}

// Main function
int main() {
    Queue *q = createQueue(10);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printQueue(q);
    int data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    printQueue(q);
    return 0;
}