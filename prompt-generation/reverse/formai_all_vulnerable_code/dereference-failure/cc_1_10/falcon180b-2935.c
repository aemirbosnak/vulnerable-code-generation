//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the queue
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the queue structure
typedef struct queue {
    Node* front;
    Node* rear;
} Queue;

// Create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Enqueue an element to the end of the queue
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Dequeue an element from the front of the queue
int dequeue(Queue* q) {
    int data = -1;

    if (q->front == NULL) {
        printf("Queue is empty.\n");
    } else {
        Node* temp = q->front;
        data = temp->data;
        q->front = temp->next;
        free(temp);
    }

    return data;
}

// Display the elements in the queue
void display(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
    } else {
        Node* temp = q->front;
        printf("Queue: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
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
    printf("Dequeued data: %d\n", dequeuedData);

    display(q);

    dequeuedData = dequeue(q);
    printf("Dequeued data: %d\n", dequeuedData);

    display(q);

    dequeuedData = dequeue(q);
    printf("Dequeued data: %d\n", dequeuedData);

    display(q);

    dequeuedData = dequeue(q);
    printf("Dequeued data: %d\n", dequeuedData);

    display(q);

    return 0;
}