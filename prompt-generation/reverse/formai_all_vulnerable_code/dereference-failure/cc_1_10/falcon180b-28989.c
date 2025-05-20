//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the queue
#define MAX_SIZE 100

// Define the node structure for the queue
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the queue structure
typedef struct {
    Node* front;
    Node* rear;
    int count;
} Queue;

// Initialize an empty queue
void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->count = 0;
}

// Check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Check if the queue is full
bool isFull(Queue* queue) {
    return queue->count == MAX_SIZE;
}

// Enqueue an element to the rear of the queue
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

    queue->count++;
}

// Dequeue an element from the front of the queue
int dequeue(Queue* queue) {
    int data;
    Node* temp = queue->front;

    if (isEmpty(queue)) {
        printf("Error: Queue is empty\n");
        return -1;
    }

    data = temp->data;
    queue->front = temp->next;
    free(temp);

    if (isEmpty(queue)) {
        queue->rear = NULL;
    }

    queue->count--;

    return data;
}

// Display the elements of the queue
void display(Queue* queue) {
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

// Main function to test the queue implementation
int main() {
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);

    display(&queue);

    int dequeuedData = dequeue(&queue);
    printf("Dequeued data: %d\n", dequeuedData);

    display(&queue);

    enqueue(&queue, 50);
    enqueue(&queue, 60);

    printf("Queue is full: %s\n", isFull(&queue)? "Yes" : "No");

    return 0;
}