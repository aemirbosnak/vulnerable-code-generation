//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: creative
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct queue {
        int *array;
        int size;
        int front;
        int rear;
    } Queue;

    Queue* createQueue(int size) {
        Queue *queue = malloc(sizeof(Queue));
        queue->array = malloc(size * sizeof(int));
        queue->size = size;
        queue->front = 0;
        queue->rear = 0;
        return queue;
    }

    void enqueue(Queue *queue, int value) {
        if (queue->rear == queue->size) {
            printf("Queue is full");
            return;
        }
        queue->array[queue->rear] = value;
        queue->rear++;
    }

    int dequeue(Queue *queue) {
        if (queue->front == queue->rear) {
            printf("Queue is empty");
            return -1;
        }
        int value = queue->array[queue->front];
        queue->front++;
        return value;
    }

    void printQueue(Queue *queue) {
        for (int i = queue->front; i < queue->rear; i++) {
            printf("%d ", queue->array[i]);
        }
        printf("\n");
    }

    int main() {
        Queue *queue = createQueue(10);

        enqueue(queue, 1);
        enqueue(queue, 2);
        enqueue(queue, 3);
        enqueue(queue, 4);
        enqueue(queue, 5);

        printQueue(queue);

        dequeue(queue);
        dequeue(queue);
        dequeue(queue);

        printQueue(queue);

        return 0;
    }