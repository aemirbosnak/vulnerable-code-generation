//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 100

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *front = NULL, *rear = NULL;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void enqueue(int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    new_node->data = data;
    new_node->next = NULL;

    pthread_mutex_lock(&mutex);

    if (front == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }

    pthread_mutex_unlock(&mutex);
}

void dequeue() {
    Node *temp_node;

    pthread_mutex_lock(&mutex);

    if (front == NULL) {
        printf("Queue is empty\n");
        pthread_mutex_unlock(&mutex);
        return;
    }

    temp_node = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    pthread_mutex_unlock(&mutex);

    printf("Dequeued element is %d\n", temp_node->data);
    free(temp_node);
}

void *thread_enqueue(void *param) {
    int i;

    for (i = 0; i < 10; i++) {
        enqueue(i * 10);
        sleep(1);
    }

    return NULL;
}

void *thread_dequeue(void *param) {
    int i;

    for (i = 0; i < 10; i++) {
        dequeue();
        sleep(1);
    }

    return NULL;
}

int main() {
    int i;
    pthread_t thread_id[20];

    for (i = 0; i < 20; i++) {
        if (i % 2 == 0) {
            pthread_create(&thread_id[i], NULL, thread_enqueue, NULL);
        } else {
            pthread_create(&thread_id[i], NULL, thread_dequeue, NULL);
        }
    }

    for (i = 0; i < 20; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}