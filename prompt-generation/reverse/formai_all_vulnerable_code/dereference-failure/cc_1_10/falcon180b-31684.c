//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 10

typedef struct {
    int data;
    struct node* next;
} node;

node* front = NULL;
node* rear = NULL;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
int count = 0;

void enqueue(int data) {
    node* new = (node*) malloc(sizeof(node));
    new->data = data;
    new->next = NULL;

    pthread_mutex_lock(&mutex);
    if (rear == NULL) {
        front = new;
        rear = new;
    }
    else {
        rear->next = new;
        rear = new;
    }
    count++;
    printf("Enqueued %d\n", data);
    pthread_cond_signal(&condition);
    pthread_mutex_unlock(&mutex);
}

void dequeue() {
    int data;
    node* temp;

    pthread_mutex_lock(&mutex);
    if (front == NULL) {
        printf("Queue is empty\n");
        pthread_mutex_unlock(&mutex);
        return;
    }
    temp = front;
    data = temp->data;
    front = front->next;
    free(temp);
    count--;
    printf("Dequeued %d\n", data);
    pthread_cond_signal(&condition);
    pthread_mutex_unlock(&mutex);
}

void* consumer(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (count == 0 && rear!= NULL) {
            printf("Consumer is waiting...\n");
            pthread_cond_wait(&condition, &mutex);
        }
        if (rear == NULL) {
            printf("Consumer is done\n");
            pthread_mutex_unlock(&mutex);
            break;
        }
        dequeue();
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void* producer(void* arg) {
    int i;

    for (i = 0; i < 10; i++) {
        enqueue(i);
        sleep(1);
    }

    pthread_exit(0);
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