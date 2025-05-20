//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 5

typedef struct {
    int data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_empty = PTHREAD_COND_INITIALIZER;

void push(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    pthread_mutex_lock(&mutex);

    if (rear == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }

    pthread_cond_signal(&cond_empty);
    pthread_mutex_unlock(&mutex);
}

void pop() {
    pthread_mutex_lock(&mutex);

    while (front == NULL) {
        pthread_cond_wait(&cond_empty, &mutex);
    }

    Node* temp = front;
    front = front->next;

    pthread_mutex_unlock(&mutex);

    free(temp);
}

void* consumer(void* arg) {
    int i;

    for (i = 0; i < 10; i++) {
        pop();
        printf("%d consumed by consumer %d\n", i, (int) arg);
        sleep(1);
    }

    return NULL;
}

void* producer(void* arg) {
    int i;

    for (i = 0; i < 10; i++) {
        push(i);
        printf("%d produced by producer %d\n", i, (int) arg);
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t thread_id[2];

    int i;
    for (i = 0; i < 2; i++) {
        pthread_create(&thread_id[i], NULL, (i == 0)? producer : consumer, (void*) i);
    }

    for (i = 0; i < 2; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}