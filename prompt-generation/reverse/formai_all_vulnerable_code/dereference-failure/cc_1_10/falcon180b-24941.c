//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Queue structure
typedef struct {
    int data;
    struct node* next;
} Node;

// Queue structure
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
Queue* createQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

// Function to add an element to the rear of the queue
void enqueue(Queue* q, int data) {
    Node* newNode = createNode(data);
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to remove an element from the front of the queue
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    if (q->front == NULL) {
        q->rear = NULL;
    }
    return data;
}

// Function to display the elements in the queue
void display(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    Node* temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    display(q);
    int dequeuedData = dequeue(q);
    printf("Dequeued element: %d\n", dequeuedData);
    display(q);
    dequeuedData = dequeue(q);
    printf("Dequeued element: %d\n", dequeuedData);
    display(q);
    dequeuedData = dequeue(q);
    printf("Dequeued element: %d\n", dequeuedData);
    display(q);
    dequeuedData = dequeue(q);
    printf("Dequeued element: %d\n", dequeuedData);
    display(q);
    dequeuedData = dequeue(q);
    printf("Dequeued element: %d\n", dequeuedData);
    display(q);
    return 0;
}