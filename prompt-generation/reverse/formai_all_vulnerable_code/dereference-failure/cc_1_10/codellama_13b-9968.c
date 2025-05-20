//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: complete
// Queue Implementation in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *array;
};

// Function to create a queue of given size
struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->size = size;
    queue->front = -1;
    queue->rear = -1;
    queue->array = (int*)malloc(sizeof(int) * size);
    return queue;
}

// Function to insert an element into the queue
void enqueue(struct Queue* queue, int element) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full");
        return;
    }
    queue->rear++;
    queue->array[queue->rear] = element;
}

// Function to remove an element from the queue
int dequeue(struct Queue* queue) {
    if (queue->front == queue->rear) {
        printf("Queue is empty");
        return -1;
    }
    queue->front++;
    int element = queue->array[queue->front];
    return element;
}

// Function to display the queue
void displayQueue(struct Queue* queue) {
    printf("Queue: ");
    for (int i = queue->front + 1; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

// Driver program to test the queue
int main() {
    struct Queue* queue = createQueue(5);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    displayQueue(queue);
    int element = dequeue(queue);
    printf("Dequeued element is %d\n", element);
    displayQueue(queue);
    return 0;
}