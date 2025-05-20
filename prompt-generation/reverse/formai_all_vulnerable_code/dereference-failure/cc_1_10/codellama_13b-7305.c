//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: satisfied
/*
 * A unique C Queue Implementation example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Queue structure
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == queue->rear + 1);
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

// Function to add an item to the queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full");
        return;
    }
    queue->rear++;
    queue->items[queue->rear] = item;
}

// Function to remove an item from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty");
        return -1;
    }
    int item = queue->items[queue->front];
    queue->front++;
    return item;
}

// Function to display the queue
void display(Queue* queue) {
    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

int main() {
    // Create a new queue
    Queue* queue = createQueue();

    // Add items to the queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    // Display the queue
    display(queue);

    // Remove an item from the queue
    int item = dequeue(queue);
    printf("Item removed from queue: %d\n", item);

    // Display the queue again
    display(queue);

    return 0;
}