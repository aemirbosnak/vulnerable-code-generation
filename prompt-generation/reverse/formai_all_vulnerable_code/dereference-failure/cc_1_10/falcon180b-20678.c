//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Queue structure definition
typedef struct {
    struct Node* front;
    struct Node* rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Function to add an element to the rear of the queue
void enqueue(Queue* queue, int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;

    if (isEmpty(queue)) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

// Function to remove an element from the front of the queue
int dequeue(Queue* queue) {
    int data;
    struct Node* temp = queue->front;

    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }

    data = temp->data;
    queue->front = temp->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);

    return data;
}

// Function to display the elements in the queue
void display(Queue* queue) {
    struct Node* temp = queue->front;

    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Elements in the queue are: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    display(queue);

    dequeue(queue);
    dequeue(queue);

    display(queue);

    return 0;
}