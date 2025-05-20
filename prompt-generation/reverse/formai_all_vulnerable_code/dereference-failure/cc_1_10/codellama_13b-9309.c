//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: optimized
// Queue Implementation using Linked List

#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to insert an element at the end of the queue
void enqueue(Queue* queue, int element) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }

    queue->rear = newNode;
}

// Function to remove an element from the front of the queue
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return -1;
    }

    Node* temp = queue->front;
    int element = temp->data;

    queue->front = temp->next;
    free(temp);

    return element;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return queue->rear == NULL;
}

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    int element = dequeue(queue);
    printf("%d\n", element);

    element = dequeue(queue);
    printf("%d\n", element);

    element = dequeue(queue);
    printf("%d\n", element);

    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }

    if (isFull(queue)) {
        printf("Queue is full\n");
    } else {
        printf("Queue is not full\n");
    }

    free(queue);

    return 0;
}