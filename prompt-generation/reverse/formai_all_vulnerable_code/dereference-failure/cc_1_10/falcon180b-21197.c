//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure of a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the structure of a queue
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Initialize an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Check if the queue is empty
bool isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Add an element to the rear of the queue
void enqueue(Queue* queue, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (isEmpty(queue)) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->size++;
}

// Remove an element from the front of the queue
int dequeue(Queue* queue) {
    int data;
    Node* node = queue->front;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        data = node->data;
        queue->front = node->next;
        if (queue->front == NULL) {
            queue->rear = NULL;
        }
        free(node);
        queue->size--;
        return data;
    }
}

// Print the elements of the queue
void printQueue(Queue* queue) {
    Node* node = queue->front;
    printf("Queue: ");
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function
int main() {
    Queue* queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    printQueue(queue);
    int data = dequeue(queue);
    printf("Dequeued element: %d\n", data);
    printQueue(queue);
    data = dequeue(queue);
    printf("Dequeued element: %d\n", data);
    printQueue(queue);
    data = dequeue(queue);
    printf("Dequeued element: %d\n", data);
    printQueue(queue);
    data = dequeue(queue);
    printf("Dequeued element: %d\n", data);
    printQueue(queue);
    data = dequeue(queue);
    printf("Dequeued element: %d\n", data);
    printQueue(queue);
    return 0;
}