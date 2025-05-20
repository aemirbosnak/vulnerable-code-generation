//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == NULL && queue->rear == NULL;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    struct Node* temp = queue->front;
    int count = 0;
    while (temp!= NULL) {
        count++;
        temp = temp->next;
    }
    return count == MAX_SIZE;
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue* queue, int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
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
int dequeue(struct Queue* queue) {
    int value = -1;
    if (!isEmpty(queue)) {
        struct Node* temp = queue->front;
        value = temp->data;
        queue->front = temp->next;
        free(temp);
    }
    return value;
}

// Function to display the elements of the queue
void display(struct Queue* queue) {
    struct Node* temp = queue->front;
    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    display(queue);
    int value = dequeue(queue);
    printf("Dequeued value: %d\n", value);
    display(queue);
    enqueue(queue, 50);
    display(queue);
    return 0;
}