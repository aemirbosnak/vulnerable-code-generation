//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 5

typedef struct {
    int data;
    struct node* next;
} node;

node* front = NULL;
node* rear = NULL;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void enqueue(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    pthread_mutex_lock(&mutex);

    if (rear == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    pthread_mutex_unlock(&mutex);
}

void dequeue() {
    pthread_mutex_lock(&mutex);

    if (front == NULL) {
        printf("Queue is empty\n");
        pthread_mutex_unlock(&mutex);
        return;
    }

    node* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    pthread_mutex_unlock(&mutex);

    printf("Dequeued element is %d\n", temp->data);
    free(temp);
}

void* producer(void* arg) {
    int i;

    for (i = 0; i < 10; i++) {
        enqueue(i);
        sleep(1);
    }

    return NULL;
}

void* consumer(void* arg) {
    int i;

    for (i = 0; i < 10; i++) {
        dequeue();
        sleep(2);
    }

    return NULL;
}

int main() {
    pthread_t thread_id[2];

    pthread_create(&thread_id[0], NULL, producer, NULL);
    pthread_create(&thread_id[1], NULL, consumer, NULL);

    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);

    return 0;
}