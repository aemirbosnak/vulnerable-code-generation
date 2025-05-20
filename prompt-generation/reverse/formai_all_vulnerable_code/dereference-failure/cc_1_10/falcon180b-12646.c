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

void enqueue(int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if(new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;

    pthread_mutex_lock(&mutex);
    if(rear == NULL) {
        front = rear = new_node;
    }
    else {
        rear->next = new_node;
        rear = new_node;
    }
    pthread_mutex_unlock(&mutex);
}

int dequeue() {
    int value;
    Node* temp_node;
    pthread_mutex_lock(&mutex);
    if(front == NULL) {
        printf("Queue is empty\n");
        pthread_mutex_unlock(&mutex);
        return -1;
    }
    else if(front == rear) {
        temp_node = front;
        value = front->data;
        front = rear = NULL;
    }
    else {
        temp_node = front;
        value = front->data;
        front = front->next;
    }
    pthread_mutex_unlock(&mutex);
    free(temp_node);
    return value;
}

void* consumer_thread(void* arg) {
    int num;
    while(1) {
        num = dequeue();
        if(num == -1)
            break;
        printf("Consumer %d consumed %d\n", (int) pthread_self(), num);
        sleep(1);
    }
    return NULL;
}

void* producer_thread(void* arg) {
    int num;
    for(num=1; num<=10; num++) {
        enqueue(num);
        printf("Producer %d produced %d\n", (int) pthread_self(), num);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t thread_id[2];
    int i;

    for(i=0; i<2; i++) {
        pthread_create(&thread_id[i], NULL, (i==0)? producer_thread : consumer_thread, NULL);
        printf("Thread %d created\n", i+1);
    }

    for(i=0; i<2; i++) {
        pthread_join(thread_id[i], NULL);
        printf("Thread %d joined\n", i+1);
    }

    return 0;
}