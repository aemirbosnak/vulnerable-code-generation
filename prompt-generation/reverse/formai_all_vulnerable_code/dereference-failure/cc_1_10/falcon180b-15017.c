//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

// Node structure for the Queue
typedef struct {
    int data;
    struct node* next;
} Node;

// Queue structure
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function to create an empty Queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if the Queue is empty
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

// Function to add an element to the rear of the Queue
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
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

// Function to remove an element from the front of the Queue
int dequeue(Queue* q) {
    int data = -1;
    if (!isEmpty(q)) {
        Node* temp = q->front;
        data = temp->data;
        q->front = q->front->next;
        free(temp);
    }
    return data;
}

// Function to display the contents of the Queue
void display(Queue* q) {
    Node* temp = q->front;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);
    dequeue(q);
    dequeue(q);
    display(q);
    return 0;
}