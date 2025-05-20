//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: standalone
/*
 * A unique C Queue Implementation example program in a standalone style
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

/*
 * Struct to represent a queue
 */
typedef struct {
    int size;
    int front;
    int rear;
    int *arr;
} Queue;

/*
 * Function to create a new queue
 */
Queue* createQueue() {
    Queue *queue = malloc(sizeof(Queue));
    queue->size = MAX_QUEUE_SIZE;
    queue->front = -1;
    queue->rear = -1;
    queue->arr = malloc(queue->size * sizeof(int));
    return queue;
}

/*
 * Function to check if the queue is empty
 */
bool isEmpty(Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

/*
 * Function to add an element to the queue
 */
void enqueue(Queue *queue, int element) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full\n");
        return;
    }

    queue->rear++;
    queue->arr[queue->rear] = element;

    if (queue->front == -1) {
        queue->front = 0;
    }
}

/*
 * Function to remove an element from the queue
 */
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }

    int element = queue->arr[queue->front];
    queue->front++;

    if (queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }

    return element;
}

/*
 * Function to display the elements of the queue
 */
void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    int i;
    for (i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }

    printf("\n");
}

int main() {
    Queue *queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    display(queue);

    int element = dequeue(queue);
    printf("Dequeued element: %d\n", element);

    display(queue);

    return 0;
}