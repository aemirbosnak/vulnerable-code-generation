//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Node structure definition
struct node {
    int data;
    struct node* next;
};

// Queue structure definition
typedef struct {
    struct node* front;
    struct node* rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    if (queue->front == NULL)
        return 1;
    else
        return 0;
}

// Function to add an element to the rear of the queue
void enqueue(Queue* queue, int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    temp->data = value;
    temp->next = NULL;
    if (isEmpty(queue)) {
        queue->front = temp;
        queue->rear = temp;
    }
    else {
        queue->rear->next = temp;
        queue->rear = temp;
    }
}

// Function to remove an element from the front of the queue
int dequeue(Queue* queue) {
    int value;
    struct node* temp = queue->front;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(0);
    }
    value = temp->data;
    queue->front = temp->next;
    free(temp);
    return value;
}

// Function to display the elements of the queue
void display(Queue* queue) {
    struct node* temp = queue->front;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(0);
    }
    printf("Queue elements are: ");
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