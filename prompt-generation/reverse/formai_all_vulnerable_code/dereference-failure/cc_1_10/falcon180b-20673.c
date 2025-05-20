//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 10

typedef struct {
    int data;
    struct node *next;
} Node;

Node *front = NULL, *rear = NULL;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void push(int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    new_node->data = value;
    new_node->next = NULL;

    pthread_mutex_lock(&lock);

    if (rear == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }

    printf("Element pushed: %d\n", value);

    pthread_mutex_unlock(&lock);
}

void pop() {
    pthread_mutex_lock(&lock);

    if (front == NULL) {
        printf("Queue is empty\n");
        pthread_mutex_unlock(&lock);
        return;
    }

    Node *temp = front;
    front = front->next;

    printf("Element popped: %d\n", temp->data);

    free(temp);
    pthread_mutex_unlock(&lock);
}

void *consumer(void *arg) {
    int i;

    for (i = 0; i < 5; i++) {
        pop();
        sleep(1);
    }

    return NULL;
}

void *producer(void *arg) {
    int i;

    for (i = 0; i < 5; i++) {
        push(i);
        sleep(1);
    }

    return NULL;
}

int main() {
    int i;

    pthread_t thread_id[2];

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