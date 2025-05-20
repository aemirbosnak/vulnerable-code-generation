//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int front;
    int rear;
    int arr[MAX_QUEUE_SIZE];
} Queue;

void enqueue(Queue *q, int data) {
    if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front) {
        printf("Queue is full. Cannot enqueue %d.\n", data);
        return;
    }
    q->arr[q->rear] = data;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

int dequeue(Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = q->arr[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return data;
}

void print_queue(Queue q) {
    int i;
    for (i = q.front; i != q.rear; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("%d ", q.arr[i]);
    }
    printf("%d\n", q.arr[i]);
}

int main() {
    Queue q;
    q.front = q.rear = -1;

    int i;
    for (i = 0; i < 15; i++) {
        enqueue(&q, i);
        printf("Enqueued %d.\n", i);
    }

    printf("Queue after enqueueing 15 elements:\n");
    print_queue(q);

    for (i = 0; i < 5; i++) {
        int data = dequeue(&q);
        printf("Dequeued %d.\n", data);
    }

    printf("Queue after dequeueing 5 elements:\n");
    print_queue(q);

    for (i = 0; i < 5; i++) {
        int data = -1;
        if ((data = dequeue(&q)) == -1) {
            printf("Dequeued %d.\n", data);
            break;
        }
        printf("Dequeued %d.\n", data);
    }

    return 0;
}