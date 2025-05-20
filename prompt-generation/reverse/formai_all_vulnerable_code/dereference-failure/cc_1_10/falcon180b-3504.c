//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Node structure for the queue
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* newQueue = (struct Queue*) malloc(sizeof(struct Queue));
    if (!newQueue) {
        printf("Memory error\n");
        exit(0);
    }
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    if (queue->front == NULL)
        return 1;
    else
        return 0;
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
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
int dequeue(struct Queue* queue) {
    int data;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(0);
    }
    else {
        struct Node* temp = queue->front;
        data = temp->data;
        queue->front = temp->next;
        free(temp);
        if (isEmpty(queue))
            queue->rear = NULL;
    }
    return data;
}

// Function to display the elements of the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(0);
    }
    else {
        printf("Elements in the queue are:\n");
        struct Node* temp = queue->front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    int dequeuedData = dequeue(queue);
    printf("Dequeued element is: %d\n", dequeuedData);
    display(queue);
    return 0;
}