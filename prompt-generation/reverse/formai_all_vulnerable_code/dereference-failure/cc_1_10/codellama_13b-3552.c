//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: romantic
// A romantic C Queue Implementation example program

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Node structure
typedef struct node {
    int data;
    struct node *next;
} Node;

// Queue structure
typedef struct {
    Node *front;
    Node *rear;
    int size;
} Queue;

// Function to create a new node
Node* newNode(int data) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new queue
Queue* newQueue() {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to add an element to the queue
void enqueue(Queue *queue, int data) {
    Node *node = newNode(data);
    if (queue->rear == NULL) {
        queue->front = node;
    } else {
        queue->rear->next = node;
    }
    queue->rear = node;
    queue->size++;
}

// Function to remove an element from the queue
int dequeue(Queue *queue) {
    if (queue->front == NULL) {
        return -1;
    }
    Node *node = queue->front;
    int data = node->data;
    queue->front = node->next;
    free(node);
    queue->size--;
    return data;
}

// Function to print the queue
void printQueue(Queue *queue) {
    Node *node = queue->front;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    // Create a new queue
    Queue *queue = newQueue();

    // Add elements to the queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    // Print the queue
    printQueue(queue);

    // Remove elements from the queue
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));

    // Print the queue again
    printQueue(queue);

    return 0;
}