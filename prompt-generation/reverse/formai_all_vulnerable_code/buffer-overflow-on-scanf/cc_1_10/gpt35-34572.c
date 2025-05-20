//FormAI DATASET v1.0 Category: QR code reader ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int head;
    int tail;
} Queue;

void initQueue(Queue *queue) {
    queue->head = 0;
    queue->tail = 0;
}

bool isQueueFull(Queue *queue) {
    return (queue->tail + 1) % MAX_QUEUE_SIZE == queue->head;
}

bool isQueueEmpty(Queue *queue) {
    return queue->head == queue->tail;
}

void enqueue(Queue *queue, int data) {
    if (isQueueFull(queue)) {
        return;
    }
    queue->data[queue->tail] = data;
    queue->tail = (queue->tail + 1) % MAX_QUEUE_SIZE;
}

int dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        return -1;
    }
    int result = queue->data[queue->head];
    queue->head = (queue->head + 1) % MAX_QUEUE_SIZE;
    return result;
}

Queue q;
pthread_mutex_t lock;
bool reader_running = true;

void *readerThread(void *arg) {
    while (reader_running) {
        printf("Waiting for QR code input...\n");
        int input;
        scanf("%d", &input);
        pthread_mutex_lock(&lock);
        enqueue(&q, input);
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
}

void *processingThread(void *arg) {
    while (reader_running) {
        pthread_mutex_lock(&lock);
        if (!isQueueEmpty(&q)) {
            int input = dequeue(&q);
            printf("Processing QR code input: %d\n", input);
        }
        pthread_mutex_unlock(&lock);
        usleep(1000); // sleep 1 millisecond to avoid busy wait
    }
    pthread_exit(NULL);
}

int main() {
    initQueue(&q);
    pthread_t reader, processor;
    pthread_mutex_init(&lock, NULL);
    pthread_create(&reader, NULL, readerThread, NULL);
    pthread_create(&processor, NULL, processingThread, NULL);
    sleep(5); // run the program for 5 seconds
    reader_running = false;
    pthread_join(reader, NULL);
    pthread_join(processor, NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}