//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 10

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void enqueue(int data) {
    pthread_mutex_lock(&mutex);
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (rear == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
    printf("Enqueued %d\n", data);
    pthread_mutex_unlock(&mutex);
}

void dequeue() {
    pthread_mutex_lock(&mutex);
    if (front == NULL) {
        printf("Queue is empty\n");
        pthread_mutex_unlock(&mutex);
        return;
    }
    struct node* temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    printf("Dequeued %d\n", temp->data);
    free(temp);
    pthread_mutex_unlock(&mutex);
}

void* consumer(void* arg) {
    int i;
    for (i = 0; i < 5; i++) {
        sleep(1);
        dequeue();
    }
    return NULL;
}

void* producer(void* arg) {
    int i;
    for (i = 0; i < 5; i++) {
        enqueue(i*2);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t thread_id[2];
    int i;
    for (i = 0; i < 2; i++) {
        if (i == 0) {
            pthread_create(&thread_id[i], NULL, producer, NULL);
        } else {
            pthread_create(&thread_id[i], NULL, consumer, NULL);
        }
    }
    for (i = 0; i < 2; i++) {
        pthread_join(thread_id[i], NULL);
    }
    return 0;
}