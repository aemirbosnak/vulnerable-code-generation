//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

// Node structure for the queue
typedef struct {
    int data;
    struct node* next;
} Node;

// Queue structure
typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Function to check if the queue is full
bool isFull(Queue* queue) {
    return queue->size == MAX_QUEUE_SIZE;
}

// Function to enqueue an element
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    
    queue->size++;
}

// Function to dequeue an element
int dequeue(Queue* queue) {
    int data;
    Node* tempNode;
    
    if (isEmpty(queue)) {
        printf("Queue is empty.");
        return -1;
    }
    
    tempNode = queue->front;
    data = tempNode->data;
    queue->front = tempNode->next;
    
    if (isEmpty(queue)) {
        queue->rear = NULL;
    }
    
    free(tempNode);
    queue->size--;
    
    return data;
}

// Function to display the queue
void display(Queue* queue) {
    Node* tempNode = queue->front;
    
    if (isEmpty(queue)) {
        printf("Queue is empty.");
        return;
    }
    
    printf("Queue: ");
    while (tempNode!= NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

int main() {
    Queue* queue = createQueue();
    
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    
    display(queue);
    
    int dequeuedData;
    
    dequeuedData = dequeue(queue);
    printf("Dequeued data: %d\n", dequeuedData);
    
    dequeuedData = dequeue(queue);
    printf("Dequeued data: %d\n", dequeuedData);
    
    display(queue);
    
    dequeuedData = dequeue(queue);
    printf("Dequeued data: %d\n", dequeuedData);
    
    dequeuedData = dequeue(queue);
    printf("Dequeued data: %d\n", dequeuedData);
    
    display(queue);
    
    return 0;
}