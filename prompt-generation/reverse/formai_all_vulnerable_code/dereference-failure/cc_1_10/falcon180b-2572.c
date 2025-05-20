//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function prototypes
Queue* createQueue();
void enqueue(Queue* queue, int data);
int dequeue(Queue* queue);
int isEmpty(Queue* queue);
int size(Queue* queue);
void printQueue(Queue* queue);

// Create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Add an element to the rear of the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Remove an element from the front of the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = queue->front->data;
    Node* temp = queue->front;
    queue->front = queue->front->next;

    free(temp);

    if (isEmpty(queue)) {
        queue->rear = NULL;
    }

    return data;
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == NULL && queue->rear == NULL);
}

// Get the size of the queue
int size(Queue* queue) {
    int count = 0;
    Node* temp = queue->front;

    while (temp!= NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Print the elements of the queue
void printQueue(Queue* queue) {
    Node* temp = queue->front;

    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Main function
int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

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

    return 0;
}