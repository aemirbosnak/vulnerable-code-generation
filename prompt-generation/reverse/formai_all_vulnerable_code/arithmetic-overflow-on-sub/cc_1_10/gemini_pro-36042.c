//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define a custom queue structure using an array
typedef struct Queue {
    int *elements;  // Pointer to the array of elements
    int front;      // Index of the front element
    int rear;       // Index of the rear element
    int capacity;   // Maximum number of elements in the queue
} Queue;

// Function to create a new queue of the given size
Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL;  // Unable to allocate memory for the queue
    }

    queue->elements = (int *)malloc(size * sizeof(int));
    if (queue->elements == NULL) {
        free(queue);  // Unable to allocate memory for the array
        return NULL;
    }

    queue->front = 0;
    queue->rear = -1;
    queue->capacity = size;

    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->front > queue->rear;
}

// Function to check if the queue is full
int isFull(Queue *queue) {
    return queue->rear == queue->capacity - 1;
}

// Function to insert an element into the queue
void enqueue(Queue *queue, int element) {
    if (isFull(queue)) {
        return;  // Queue is full, cannot insert element
    }

    queue->rear++;
    queue->elements[queue->rear] = element;
}

// Function to remove an element from the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        return -1;  // Queue is empty, cannot remove element
    }

    int element = queue->elements[queue->front];
    queue->front++;

    return element;
}

// Function to print the elements of the queue
void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->elements[i]);
    }
    printf("\n");
}

// Driver code to test the queue implementation
int main() {
    // Create a new queue of size 5
    Queue *queue = createQueue(5);

    // Insert elements into the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the elements of the queue
    printQueue(queue);

    // Remove an element from the queue
    int element = dequeue(queue);
    printf("Removed element: %d\n", element);

    // Print the elements of the queue after removing an element
    printQueue(queue);

    // Free the memory allocated for the queue
    free(queue->elements);
    free(queue);

    return 0;
}