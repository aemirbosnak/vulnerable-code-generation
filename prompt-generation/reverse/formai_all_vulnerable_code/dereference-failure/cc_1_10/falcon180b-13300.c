//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define structure for a node in the queue
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define structure for the queue
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    if (q->front == NULL)
        return true;
    else
        return false;
}

// Function to add an element to the rear of the queue
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to remove an element from the front of the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    else {
        int value = q->front->data;
        Node* temp = q->front;
        q->front = q->front->next;
        free(temp);
        if (isEmpty(q))
            q->rear = NULL;
        return value;
    }
}

// Function to display the elements in the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    }
    else {
        Node* temp = q->front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function to test the queue implementation
int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    display(q);
    printf("Dequeued element: %d\n", dequeue(q));
    display(q);
    printf("Dequeued element: %d\n", dequeue(q));
    display(q);
    printf("Dequeued element: %d\n", dequeue(q));
    display(q);
    printf("Dequeued element: %d\n", dequeue(q));
    display(q);
    return 0;
}