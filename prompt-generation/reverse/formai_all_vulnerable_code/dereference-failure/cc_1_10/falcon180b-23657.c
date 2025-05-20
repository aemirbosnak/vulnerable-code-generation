//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 100

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_empty = PTHREAD_COND_INITIALIZER;

void enqueue(int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    pthread_mutex_lock(&mutex);

    if (rear == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }

    printf("Enqueued value: %d\n", value);

    pthread_cond_signal(&cond_empty);
    pthread_mutex_unlock(&mutex);
}

void dequeue() {
    int value;
    Node *temp_node;

    pthread_mutex_lock(&mutex);

    if (front == NULL) {
        printf("Queue is empty\n");
        pthread_cond_wait(&cond_full, &mutex);
    } else {
        temp_node = front;
        front = front->next;
        value = temp_node->data;
        free(temp_node);

        if (front == NULL) {
            rear = NULL;
        }

        printf("Dequeued value: %d\n", value);
    }

    pthread_mutex_unlock(&mutex);
}

void *consumer(void *arg) {
    int i;

    for (i = 0; i < 10; i++) {
        dequeue();
        sleep(1);
    }

    return NULL;
}

void *producer(void *arg) {
    int i;

    for (i = 0; i < 10; i++) {
        enqueue(i);
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t thread_id[2];

    int i;
    for (i = 0; i < 2; i++) {
        pthread_create(&thread_id[i], NULL, (i == 0)? producer : consumer, NULL);
    }

    for (i = 0; i < 2; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}