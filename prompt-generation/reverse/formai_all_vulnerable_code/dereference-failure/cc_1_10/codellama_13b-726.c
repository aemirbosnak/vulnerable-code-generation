//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Queue structure
struct Queue {
    int *arr;
    int front;
    int rear;
    int size;
};

// Function to create a new Queue
struct Queue* createQueue(int size) {
    struct Queue *q = malloc(sizeof(struct Queue));
    q->arr = malloc(sizeof(int) * size);
    q->front = 0;
    q->rear = 0;
    q->size = size;
    return q;
}

// Function to add an element to the Queue
void enqueue(struct Queue *q, int element) {
    if (q->rear == q->size) {
        printf("Queue is full.\n");
        return;
    }
    q->arr[q->rear] = element;
    q->rear++;
}

// Function to remove an element from the Queue
int dequeue(struct Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty.\n");
        return -1;
    }
    int element = q->arr[q->front];
    q->front++;
    return element;
}

// Function to display the elements of the Queue
void displayQueue(struct Queue *q) {
    printf("The elements of the Queue are:\n");
    for (int i = q->front; i < q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    struct Queue *q = createQueue(10);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    displayQueue(q);
    int element = dequeue(q);
    printf("Element removed from the Queue: %d\n", element);
    displayQueue(q);
    return 0;
}