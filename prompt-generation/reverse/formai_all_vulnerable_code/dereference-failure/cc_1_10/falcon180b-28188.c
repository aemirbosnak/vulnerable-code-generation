//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Queue data structure
struct Queue {
    int front;
    int rear;
    int *arr;
};

// Create a new queue
struct Queue *createQueue() {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->arr = (int *)malloc(MAX_SIZE * sizeof(int));
    return queue;
}

// Check if the queue is empty
int isEmpty(struct Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Check if the queue is full
int isFull(struct Queue *queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Enqueue an element to the queue
void enqueue(struct Queue *queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    queue->arr[queue->rear] = element;
}

// Dequeue an element from the queue
int dequeue(struct Queue *queue) {
    int element;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    element = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return element;
}

// Display the contents of the queue
void display(struct Queue *queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (i = queue->front; i <= queue->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    struct Queue *queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    display(queue);
    dequeue(queue);
    dequeue(queue);
    display(queue);
    return 0;
}