//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the queue

// Node structure for the queue
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return queue->size == MAX_SIZE;
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
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

// Function to remove an element from the front of the queue
int dequeue(struct Queue* queue) {
    int data;
    struct Node* temp = queue->front;

    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }

    data = temp->data;
    queue->front = temp->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    queue->size--;

    return data;
}

// Function to display the elements of the queue
void display(struct Queue* queue) {
    struct Node* temp = queue->front;

    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();

    // Enqueue elements
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    // Display the queue
    printf("Queue after enqueueing elements:\n");
    display(queue);

    // Dequeue elements
    int data = dequeue(queue);
    int data2 = dequeue(queue);

    // Display the queue
    printf("Queue after dequeueing elements:\n");
    display(queue);

    // Free the memory allocated to the queue
    free(queue);

    return 0;
}