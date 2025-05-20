//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: standalone
/*
 * A unique C Queue Implementation example program in a standalone style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Queue structure
typedef struct {
    int front;
    int rear;
    int size;
    int capacity;
    int *array;
} Queue;

// Function to create a queue of given capacity
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Function to add an element to the queue
void enqueue(Queue* queue, int element) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = element;
    queue->size++;
}

// Function to remove an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int element = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return element;
}

// Function to display the queue elements
void display(Queue* queue) {
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->array[i]);
        i = (i + 1) % queue->capacity;
    }
    printf("\n");
}

int main() {
    // Create a queue of capacity 5
    Queue* queue = createQueue(5);

    // Add elements to the queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60);

    // Display the queue elements
    display(queue);

    // Remove an element from the queue
    int element = dequeue(queue);
    printf("Dequeued element: %d\n", element);

    // Display the queue elements
    display(queue);

    // Free memory
    free(queue->array);
    free(queue);

    return 0;
}