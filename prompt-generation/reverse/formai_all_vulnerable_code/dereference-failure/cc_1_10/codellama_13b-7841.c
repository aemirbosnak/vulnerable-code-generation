//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: mind-bending
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct {
        int front;
        int rear;
        int size;
        int *arr;
    } Queue;

    void initQueue(Queue *q, int size) {
        q->front = -1;
        q->rear = -1;
        q->size = size;
        q->arr = (int *)malloc(size * sizeof(int));
    }

    int isEmpty(Queue *q) {
        return (q->front == -1);
    }

    int isFull(Queue *q) {
        return (q->rear == q->size - 1);
    }

    void enqueue(Queue *q, int data) {
        if (isFull(q)) {
            printf("Queue is full\n");
            return;
        }
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = data;
        if (q->front == -1) {
            q->front = 0;
        }
    }

    int dequeue(Queue *q) {
        if (isEmpty(q)) {
            printf("Queue is empty\n");
            return -1;
        }
        int data = q->arr[q->front];
        q->front = (q->front + 1) % q->size;
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        }
        return data;
    }

    void printQueue(Queue *q) {
        int i;
        if (isEmpty(q)) {
            printf("Queue is empty\n");
            return;
        }
        printf("Queue: ");
        for (i = q->front; i != q->rear; i = (i + 1) % q->size) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }

    int main() {
        Queue q;
        initQueue(&q, 5);
        enqueue(&q, 1);
        enqueue(&q, 2);
        enqueue(&q, 3);
        printQueue(&q);
        dequeue(&q);
        printQueue(&q);
        dequeue(&q);
        printQueue(&q);
        enqueue(&q, 4);
        enqueue(&q, 5);
        printQueue(&q);
        return 0;
    }