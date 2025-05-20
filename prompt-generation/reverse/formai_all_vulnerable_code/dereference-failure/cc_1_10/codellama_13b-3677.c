//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: authentic
// A unique C Queue Implementation example program in an authentic style

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a queue
struct Queue {
    int size;
    int front;
    int rear;
    int *arr;
};

// Function to create a queue of given size
struct Queue* createQueue(int size) {
    struct Queue *q = (struct Queue*) malloc(sizeof(struct Queue));
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->arr = (int*) malloc(q->size * sizeof(int));
    return q;
}

// Function to enqueue an element
void enqueue(struct Queue* q, int element) {
    if (q->rear == q->size - 1) {
        printf("Queue is full");
        return;
    }
    q->rear++;
    q->arr[q->rear] = element;
}

// Function to dequeue an element
int dequeue(struct Queue* q) {
    if (q->front == q->rear) {
        printf("Queue is empty");
        return -1;
    }
    int element = q->arr[q->front];
    q->front++;
    return element;
}

// Function to check if queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == q->rear);
}

// Function to check if queue is full
int isFull(struct Queue* q) {
    return (q->rear == q->size - 1);
}

// Function to display the queue
void displayQueue(struct Queue* q) {
    printf("Front -> ");
    for (int i = q->front + 1; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("<- Rear");
}

int main() {
    struct Queue* q = createQueue(10);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    displayQueue(q);
    printf("\nDequeued element is %d", dequeue(q));
    displayQueue(q);
    return 0;
}