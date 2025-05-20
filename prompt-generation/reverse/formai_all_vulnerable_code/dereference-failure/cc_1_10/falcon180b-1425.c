//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000 // maximum size of the queue

// Node structure for the queue
struct node {
    int data;
    struct node *next;
};

// Queue structure
struct queue {
    struct node *front;
    struct node *rear;
    int size;
};

// Function to create a new node with given data
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create an empty queue
struct queue* createQueue() {
    struct queue* queue = (struct queue*)malloc(sizeof(struct queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct queue* queue) {
    return queue->size == 0;
}

// Function to add an element to the rear of the queue
void enqueue(struct queue* queue, int data) {
    struct node* node = newNode(data);
    if (isEmpty(queue)) {
        queue->front = node;
        queue->rear = node;
    }
    else {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->size++;
}

// Function to remove and return the element from the front of the queue
int dequeue(struct queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(0);
    }
    int data = queue->front->data;
    struct node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    queue->size--;
    return data;
}

// Function to print the elements of the queue
void printQueue(struct queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    struct node* temp = queue->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the queue implementation
int main() {
    struct queue* queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    printQueue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue); // This should print "Queue is empty"
    return 0;
}