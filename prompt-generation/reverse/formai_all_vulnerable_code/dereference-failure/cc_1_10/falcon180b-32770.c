//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0
#define THREADS 5
#define QUEUE_SIZE 100
#define PACKET_SIZE 1500

typedef struct {
    char *data;
    int len;
} packet;

packet *packets[QUEUE_SIZE];
int front = 0, rear = -1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void enqueue(packet *p) {
    pthread_mutex_lock(&mutex);
    if ((rear + 1) % QUEUE_SIZE == front) {
        printf("Queue is full. Packet dropped.\n");
        pthread_mutex_unlock(&mutex);
        return;
    }
    if (rear == -1)
        front = 0;
    rear = (rear + 1) % QUEUE_SIZE;
    packets[rear] = p;
    pthread_mutex_unlock(&mutex);
}

packet *dequeue() {
    packet *p;
    pthread_mutex_lock(&mutex);
    if (front == -1 || front > rear) {
        pthread_mutex_unlock(&mutex);
        return NULL;
    }
    p = packets[front];
    front = (front + 1) % QUEUE_SIZE;
    pthread_mutex_unlock(&mutex);
    return p;
}

void *monitor(void *arg) {
    int i, j;
    char *data;
    packet *p;

    for (i = 0; i < PACKET_SIZE; i++) {
        data = (char *)malloc(PACKET_SIZE * sizeof(char));
        for (j = 0; j < PACKET_SIZE; j++)
            data[j] = rand() % 256;
        p = (packet *)malloc(sizeof(packet));
        p->data = data;
        p->len = PACKET_SIZE;
        enqueue(p);
    }

    return NULL;
}

int main() {
    int i;
    pthread_t threads[THREADS];

    srand(time(NULL));

    for (i = 0; i < THREADS; i++) {
        pthread_create(&threads[i], NULL, monitor, NULL);
    }

    for (i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}