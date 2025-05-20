//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Queue structure definition
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    if (queue->front == NULL)
        return 1;
    else
        return 0;
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to remove an element from the front of the queue
int dequeue(struct Queue* queue) {
    int data = -1;
    struct Node* temp = NULL;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    }
    else {
        temp = queue->front;
        data = temp->data;
        queue->front = temp->next;
        free(temp);
    }
    return data;
}

// Function to display the contents of the queue
void display(struct Queue* queue) {
    struct Node* temp = queue->front;
    printf("Queue: ");
    if (isEmpty(queue))
        printf("Empty\n");
    else {
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    display(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    display(queue);
    return 0;
}