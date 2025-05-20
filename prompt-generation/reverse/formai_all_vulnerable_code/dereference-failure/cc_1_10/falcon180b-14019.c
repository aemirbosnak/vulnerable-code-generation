//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Queue structure definition
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == NULL && q->rear == NULL);
}

// Function to add an element to the rear of the queue
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to remove an element from the front of the queue
int dequeue(Queue* q) {
    int value = -1;

    if (!isEmpty(q)) {
        Node* temp = q->front;
        value = temp->data;
        q->front = q->front->next;

        if (isEmpty(q))
            q->rear = NULL;

        free(temp);
    }

    return value;
}

// Function to display the elements of the queue
void display(Queue* q) {
    Node* temp = q->front;

    if (isEmpty(q))
        printf("Queue is empty\n");
    else {
        printf("Queue elements are: ");
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

    printf("Queue elements after enqueue operations:\n");
    display(q);

    int value = dequeue(q);
    printf("Dequeued element: %d\n", value);

    printf("Queue elements after dequeue operation:\n");
    display(q);

    return 0;
}