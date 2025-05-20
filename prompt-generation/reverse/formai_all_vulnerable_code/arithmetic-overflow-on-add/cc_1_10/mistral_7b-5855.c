//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_QUEUE_SIZE 10
#define QUEUE_KEY 1234

typedef struct {
    int front;
    int rear;
    int size;
    int queue[MAX_QUEUE_SIZE];
} MyQueue;

void initQueue(MyQueue *queue) {
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
}

int isFull(MyQueue *queue) {
    return queue->size == MAX_QUEUE_SIZE;
}

int isEmpty(MyQueue *queue) {
    return queue->size == 0;
}

void enqueue(MyQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full, cannot enqueue %d\n", value);
        return;
    }
    queue->queue[queue->rear] = value;
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->size++;
}

int dequeue(MyQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    }
    int value = queue->queue[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->size--;
    return value;
}

int main() {
    int shmid;
    MyQueue *queue;
    key_t key = QUEUE_KEY;

    if ((shmid = shmget(key, sizeof(MyQueue), IPC_CREAT | 0666)) < 0) {
        perror("shmget failed");
        exit(EXIT_FAILURE);
    }

    if ((queue = shmat(shmid, NULL, 0)) == (MyQueue *) -1) {
        perror("shmat failed");
        exit(EXIT_FAILURE);
    }

    initQueue(queue);

    // Producer
    for (int i = 0; i < 15; i++) {
        enqueue(queue, i);
        printf("Produced %d, queue size %d\n", i, queue->size);
        sleep(1);
    }

    // Consumer
    while (!isEmpty(queue)) {
        int value = dequeue(queue);
        printf("Consumed %d, queue size %d\n", value, queue->size);
    }

    shmdt(queue);
    shmctl(shmid, IPC_RMID, 0);

    return EXIT_SUCCESS;
}