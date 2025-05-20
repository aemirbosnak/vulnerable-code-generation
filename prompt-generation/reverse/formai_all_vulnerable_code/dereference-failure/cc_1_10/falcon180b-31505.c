//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a node in the queue
typedef struct node {
    int data;
    struct node* next;
} Node;

// Queue structure
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
int isEmpty(Queue* q) {
    return (q->front == NULL && q->rear == NULL);
}

// Function to enqueue an element
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to dequeue an element
int dequeue(Queue* q) {
    int data = -1;

    if (!isEmpty(q)) {
        Node* temp = q->front;
        data = temp->data;
        q->front = q->front->next;

        if (q->front == NULL) {
            q->rear = NULL;
        }

        free(temp);
    }

    return data;
}

// Function to display the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    Node* temp = q->front;
    printf("Queue elements are: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    display(q);

    int dequeuedData = dequeue(q);
    printf("Dequeued element is: %d\n", dequeuedData);

    display(q);

    return 0;
}