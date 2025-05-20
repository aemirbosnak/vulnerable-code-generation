//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the queue
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure of the queue
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
Queue* createQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    if (!newQueue) {
        printf("Memory error\n");
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
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(1);
    }
    Node* tempNode = queue->front;
    int data = tempNode->data;
    queue->front = tempNode->next;
    free(tempNode);
    return data;
}

// Function to display the elements in the queue
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    }
    else {
        printf("Elements in the queue are: ");
        Node* tempNode = queue->front;
        while (tempNode!= NULL) {
            printf("%d ", tempNode->data);
            tempNode = tempNode->next;
        }
        printf("\n");
    }
}

// Main function to test the implementation
int main() {
    Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    int data = dequeue(queue);
    printf("Dequeued element is: %d\n", data);
    display(queue);
    enqueue(queue, 40);
    display(queue);
    return 0;
}