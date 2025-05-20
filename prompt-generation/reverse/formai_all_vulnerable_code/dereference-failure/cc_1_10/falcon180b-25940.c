//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data;
    int index;
} QueueNode;

typedef struct {
    QueueNode data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int isFull(Queue* queue) {
    return ((queue->rear + 1) % MAX_QUEUE_SIZE == queue->front);
}

void enqueue(Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    }
    QueueNode node = {data, queue->rear};
    queue->data[queue->rear] = node;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = queue->data[queue->front].data;
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    return data;
}

void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    int i = queue->front;
    while (i!= queue->rear) {
        printf("%d ", queue->data[i].data);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
    printf("%d\n", queue->data[queue->rear].data);
}

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);

    int dequeued = dequeue(queue);
    printf("Dequeued: %d\n", dequeued);
    display(queue);

    enqueue(queue, 40);
    enqueue(queue, 50);
    display(queue);

    return 0;
}