//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
} Queue;

// Function to create a new empty queue
Queue* createQueue() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Error: Failed to create queue\n");
        exit(1);
    }
    q->data = (int*) malloc(MAX_QUEUE_SIZE * sizeof(int));
    if (q->data == NULL) {
        printf("Error: Failed to allocate memory for queue\n");
        exit(1);
    }
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

// Function to destroy a queue and free its memory
void destroyQueue(Queue *q) {
    free(q->data);
    free(q);
}

// Function to check if a queue is empty
int isEmpty(Queue *q) {
    return q->size == 0;
}

// Function to check if a queue is full
int isFull(Queue *q) {
    return q->size == MAX_QUEUE_SIZE;
}

// Function to add an element to the rear of the queue
void enqueue(Queue *q, int element) {
    if (isFull(q)) {
        printf("Error: Queue is full\n");
        exit(1);
    }
    q->rear++;
    q->data[q->rear] = element;
    q->size++;
}

// Function to remove an element from the front of the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Error: Queue is empty\n");
        exit(1);
    }
    int element = q->data[q->front];
    q->front++;
    q->size--;
    return element;
}

// Function to display the elements in the queue
void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    Queue *q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    displayQueue(q);
    int element = dequeue(q);
    printf("Dequeued element: %d\n", element);
    displayQueue(q);
    destroyQueue(q);
    return 0;
}