//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    Node* temp = q->front;
    int data = temp->data;

    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = temp->next;
    }

    free(temp);
    return data;
}

int isEmpty(Queue* q) {
    if (q->front == NULL && q->rear == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void* threadFunc(void* arg) {
    Queue* q = (Queue*) arg;

    while (1) {
        if (isEmpty(q)) {
            sleep(1);
        } else {
            int data = dequeue(q);
            printf("Thread %d dequeued %d\n", (int) pthread_self(), data);
            sleep(1);
        }
    }
}

int main() {
    Queue* q = createQueue();

    pthread_t threads[5];

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, threadFunc, (void*) q);
        printf("Thread %d created\n", (int) threads[i]);
        sleep(1);
    }

    for (int i = 0; i < 10; i++) {
        enqueue(q, i);
        printf("Enqueued %d\n", i);
        sleep(1);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}