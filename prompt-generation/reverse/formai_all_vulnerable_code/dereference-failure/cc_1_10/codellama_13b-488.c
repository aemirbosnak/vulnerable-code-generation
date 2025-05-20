//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int front;
    int rear;
    int size;
    char *arr[MAX_QUEUE_SIZE];
} Queue;

Queue* createQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    return queue;
}

void enqueue(Queue *queue, char *data) {
    if (queue->size == MAX_QUEUE_SIZE) {
        printf("Queue is full\n");
        return;
    }
    queue->arr[queue->rear] = data;
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->size++;
}

char* dequeue(Queue *queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
        return NULL;
    }
    char *data = queue->arr[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->size--;
    return data;
}

int main() {
    Queue *queue = createQueue();
    enqueue(queue, "A");
    enqueue(queue, "B");
    enqueue(queue, "C");
    enqueue(queue, "D");
    enqueue(queue, "E");
    char *data = dequeue(queue);
    printf("%s\n", data);
    data = dequeue(queue);
    printf("%s\n", data);
    data = dequeue(queue);
    printf("%s\n", data);
    data = dequeue(queue);
    printf("%s\n", data);
    data = dequeue(queue);
    printf("%s\n", data);
    return 0;
}