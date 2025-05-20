//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: puzzling
// Unique C Queue Implementation example program in a puzzling style

#include <stdio.h>
#include <stdlib.h>

// Define a struct for a node in the queue
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Define a struct for the queue
typedef struct Queue {
    Node *front;
    Node *rear;
    int size;
} Queue;

// Function to create a new queue
Queue *create_queue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to add an element to the queue
void enqueue(Queue *queue, int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (queue->front == NULL) {
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

// Function to check if the queue is empty
int is_empty(Queue *queue) {
    return queue->front == NULL;
}

// Function to print the queue
void print_queue(Queue *queue) {
    Node *node = queue->front;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Queue *queue = create_queue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    print_queue(queue);
    int data = dequeue(queue);
    printf("Dequeued element: %d\n", data);
    print_queue(queue);
    return 0;
}