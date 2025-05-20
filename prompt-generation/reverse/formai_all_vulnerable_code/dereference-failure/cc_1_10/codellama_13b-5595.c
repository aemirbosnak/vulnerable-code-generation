//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Queue structure
struct Queue {
    int size;
    int front;
    int rear;
    int *data;
};

// Create a new queue
struct Queue* createQueue(int size) {
    struct Queue *q = malloc(sizeof(struct Queue));
    q->size = size;
    q->front = 0;
    q->rear = 0;
    q->data = malloc(sizeof(int) * size);
    return q;
}

// Enqueue an item
void enqueue(struct Queue *q, int item) {
    if (q->rear == q->size - 1) {
        printf("Queue is full");
        return;
    }
    q->data[q->rear] = item;
    q->rear++;
}

// Dequeue an item
int dequeue(struct Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty");
        return -1;
    }
    int item = q->data[q->front];
    q->front++;
    return item;
}

// Print queue
void printQueue(struct Queue *q) {
    printf("Queue: ");
    for (int i = q->front; i < q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    struct Queue *q = createQueue(10);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printQueue(q);
    dequeue(q);
    printQueue(q);
    return 0;
}