//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Queue structure definition
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(!newNode) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Function to create an empty queue
Queue* createQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));

    if(!newQueue) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }

    newQueue->front = NULL;
    newQueue->rear = NULL;

    return newQueue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Function to add an element to the rear of the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);

    if(isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("Element %d added to the queue.\n", data);
}

// Function to remove an element from the front of the queue
int dequeue(Queue* queue) {
    int data;
    Node* tempNode;

    if(isEmpty(queue)) {
        printf("Error: Queue is empty.\n");
        exit(1);
    }

    tempNode = queue->front;
    data = tempNode->data;
    queue->front = tempNode->next;

    if(queue->front == NULL)
        queue->rear = NULL;

    free(tempNode);

    return data;
}

// Function to display the current state of the queue
void display(Queue* queue) {
    Node* tempNode = queue->front;

    if(isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");

    while(tempNode!= NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
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

    dequeue(queue);
    dequeue(queue);

    display(queue);

    return 0;
}