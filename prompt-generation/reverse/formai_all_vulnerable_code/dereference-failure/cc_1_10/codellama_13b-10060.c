//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: irregular
// Queue Implementation Example Program

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a queue
struct Queue {
    int *arr;
    int front;
    int rear;
    int size;
};

// Function to create a new queue
struct Queue* createQueue(int size) {
    struct Queue *queue = malloc(sizeof(struct Queue));
    queue->arr = malloc(sizeof(int) * size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) {
    return queue->front == -1;
}

// Function to enqueue an element
void enqueue(struct Queue *queue, int data) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = data;
}

// Function to dequeue an element
int dequeue(struct Queue *queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue->arr[queue->front];
    queue->front++;
    return data;
}

// Function to peek at the front element
int peek(struct Queue *queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->arr[queue->front];
}

// Function to display the queue
void displayQueue(struct Queue *queue) {
    printf("Queue: ");
    for (int i = queue->front + 1; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

// Driver Code
int main() {
    struct Queue *queue = createQueue(5);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    displayQueue(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    displayQueue(queue);
    printf("Peeked element: %d\n", peek(queue));
    displayQueue(queue);
    return 0;
}