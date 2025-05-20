//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: distributed
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
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;

void push(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    pthread_mutex_lock(&mutex);

    if (front == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    pthread_cond_signal(&cv);
    pthread_mutex_unlock(&mutex);
}

int pop() {
    int data = -1;
    Node* temp = NULL;

    pthread_mutex_lock(&mutex);

    if (front!= NULL) {
        temp = front;
        data = temp->data;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }
    }

    pthread_mutex_unlock(&mutex);

    return data;
}

void* threadFunc(void* arg) {
    int i;

    for (i = 0; i < 10; i++) {
        push(i);
        printf("Pushed %d\n", i);
        sleep(1);
    }

    return NULL;
}

int main() {
    int i;
    pthread_t threads[10];

    for (i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, threadFunc, (void*) NULL);
        printf("Thread %d created\n", i);
        sleep(1);
    }

    for (i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
        printf("Thread %d joined\n", i);
        sleep(1);
    }

    while (front!= NULL) {
        pop();
        printf("Popped %d\n", front->data);
        sleep(1);
    }

    return 0;
}