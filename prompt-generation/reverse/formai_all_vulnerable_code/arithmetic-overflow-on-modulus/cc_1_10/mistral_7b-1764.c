//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_QUEUE_SIZE 100
#define QUEUE_NAME "MyQueue"

typedef struct {
    int front;
    int rear;
    int queue_size;
    int items[MAX_QUEUE_SIZE];
} CircularQueue;

void initQueue(CircularQueue *queue) {
    queue->front = 0;
    queue->rear = 0;
    queue->queue_size = MAX_QUEUE_SIZE;
}

int isFull(CircularQueue *queue) {
    return (queue->rear + 1) % queue->queue_size == queue->front;
}

int isEmpty(CircularQueue *queue) {
    return queue->front == queue->rear;
}

void enqueue(CircularQueue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d.\n", item);
        return;
    }
    queue->items[queue->rear] = item;
    queue->rear = (queue->rear + 1) % queue->queue_size;
}

int dequeue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int item = queue->items[queue->front];
    queue->front = (queue->front + 1) % queue->queue_size;
    return item;
}

void printQueue(CircularQueue *queue) {
    int i = queue->front;
    printf("Queue: [");
    do {
        printf("%d, ", queue->items[i]);
        i = (i + 1) % queue->queue_size;
    } while (i != queue->rear);
    printf("]\n");
}

int main() {
    key_t key = ftok("shm.txt", 65);
    int shmid = shmget(key, sizeof(CircularQueue), IPC_CREAT | 0666);
    CircularQueue *queue = (CircularQueue *) shmat(shmid, NULL, 0);

    initQueue(queue);

    printf("Enqueueing items: 1, 2, 3, 4, 5...\n");
    for (int i = 1; i <= 5; i++) {
        enqueue(queue, i);
        printf("Enqueued %d.\n", i);
    }

    printf("Printing queue:\n");
    printQueue(queue);

    printf("Dequeueing items: ");
    for (int i = 0; i < 5; i++) {
        int dequeued_item = dequeue(queue);
        printf("%d ", dequeued_item);
    }

    printf("\b\b]\n");
    printf("Printing queue after dequeuing:\n");
    printQueue(queue);

    shmdt(queue);
    shmctl(shmid, IPC_RMID, 0);

    return 0;
}