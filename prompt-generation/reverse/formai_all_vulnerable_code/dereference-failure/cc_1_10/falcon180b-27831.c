//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the queue
#define MAX_SIZE 100

// Define the structure of a node in the queue
typedef struct {
    int data;
    struct node* next;
} Node;

// Define the structure of the queue
typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->size == 0;
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return q->size == MAX_SIZE;
}

// Function to add an element to the rear of the queue
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if(isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

// Function to remove an element from the front of the queue
int dequeue(Queue* q) {
    if(isEmpty(q)) {
        printf("Error: Queue is empty\n");
        exit(1);
    }
    int data = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->size--;
    return data;
}

// Function to display the elements of the queue
void display(Queue* q) {
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Elements of the queue are:\n");
    Node* temp = q->front;
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the implementation
int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    display(&q);
    int dequeuedData = dequeue(&q);
    printf("Dequeued element is: %d\n", dequeuedData);
    display(&q);
    return 0;
}