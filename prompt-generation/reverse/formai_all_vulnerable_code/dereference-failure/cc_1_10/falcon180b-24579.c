//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

// Node structure for queue
typedef struct node {
    int data;
    struct node* next;
} Node;

// Queue structure
typedef struct queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    if (newQueue == NULL) {
        printf("Queue creation failed\n");
        exit(1);
    }
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return (queue->front == NULL && queue->rear == NULL);
}

// Function to add an element to the rear of the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Enqueue failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to remove an element from the front of the queue
int dequeue(Queue* queue) {
    Node* temp = queue->front;
    int data = temp->data;
    if (isEmpty(queue)) {
        printf("Dequeue failed: Queue is empty\n");
        exit(1);
    }
    if (queue->front == queue->rear) {
        free(temp);
        queue->front = NULL;
        queue->rear = NULL;
    }
    else {
        queue->front = temp->next;
        free(temp);
    }
    return data;
}

// Function to display the elements in the queue
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = queue->front;
    printf("Queue elements: ");
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
    display(queue);
    int dequeuedData = dequeue(queue);
    printf("Dequeued data: %d\n", dequeuedData);
    display(queue);
    enqueue(queue, 40);
    display(queue);
    dequeue(queue);
    display(queue);
    dequeue(queue);
    display(queue);
    return 0;
}