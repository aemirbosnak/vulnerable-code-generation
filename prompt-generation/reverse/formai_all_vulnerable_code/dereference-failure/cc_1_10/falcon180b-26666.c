//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Node structure for queue
typedef struct {
    int data;
    struct node* next;
} node;

// Queue structure
typedef struct {
    node* front;
    node* rear;
    int size;
} queue;

// Function to create a new node with given data
node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
queue* createQueue() {
    queue* newQueue = (queue*)malloc(sizeof(queue));
    if (!newQueue) {
        printf("Memory error\n");
        exit(0);
    }
    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->size = 0;
    return newQueue;
}

// Function to check if the queue is empty
bool isEmpty(queue* queue) {
    return (queue->front == NULL && queue->rear == NULL);
}

// Function to check if the queue is full
bool isFull(queue* queue) {
    return (queue->size == MAX_SIZE);
}

// Function to add an element to the rear of the queue
void enqueue(queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = createNode(data);
        queue->rear = queue->front;
    } else {
        queue->rear->next = createNode(data);
        queue->rear = queue->rear->next;
    }
    queue->size++;
}

// Function to remove an element from the front of the queue
int dequeue(queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue->front->data;
    node* tempNode = queue->front;
    queue->front = queue->front->next;
    free(tempNode);
    queue->size--;
    return data;
}

// Function to display the elements in the queue
void display(queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    node* tempNode = queue->front;
    while (tempNode!= NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

int main() {
    queue* myQueue = createQueue();
    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    display(myQueue);
    int dequeuedData = dequeue(myQueue);
    printf("Dequeued data: %d\n", dequeuedData);
    display(myQueue);
    enqueue(myQueue, 40);
    enqueue(myQueue, 50);
    printf("Size of queue: %d\n", myQueue->size);
    return 0;
}