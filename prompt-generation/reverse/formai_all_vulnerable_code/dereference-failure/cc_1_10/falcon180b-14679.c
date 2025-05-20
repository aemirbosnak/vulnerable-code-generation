//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} element;

typedef struct {
    element *queue_array;
    int front, rear;
    int size;
} queue;

void initialize_queue(queue *q) {
    q->queue_array = (element *)malloc(MAX_SIZE * sizeof(element));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

int is_empty(queue *q) {
    if (q->front == -1 && q->rear == -1)
        return 1;
    else
        return 0;
}

int is_full(queue *q) {
    if ((q->rear + 1) % MAX_SIZE == q->front)
        return 1;
    else
        return 0;
}

void enqueue(queue *q, int value) {
    if (is_full(q)) {
        printf("Queue is full\n");
        return;
    }
    if (is_empty(q)) {
        q->front = 0;
        q->rear = 0;
    }
    else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->queue_array[q->rear].data = value;
    q->queue_array[q->rear].index = q->size;
    q->size++;
}

int dequeue(queue *q) {
    int value;
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    value = q->queue_array[q->front].data;
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return value;
}

void display(queue *q) {
    int i;
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (i = q->front; i <= q->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", q->queue_array[i].data);
    }
    printf("\n");
}

int main() {
    queue q;
    initialize_queue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    return 0;
}