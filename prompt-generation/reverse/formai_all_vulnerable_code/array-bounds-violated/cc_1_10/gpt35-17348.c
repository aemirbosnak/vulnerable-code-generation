//FormAI DATASET v1.0 Category: Queue Implementation ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cv_producer = PTHREAD_COND_INITIALIZER;
pthread_cond_t cv_consumer = PTHREAD_COND_INITIALIZER;

void* producer(void* args) {
    while(1) {
        sleep(1);
        
        pthread_mutex_lock(&mutex);
        if (rear == MAX_SIZE-1) {
            printf("Producer Buffer Full\n");
            pthread_cond_wait(&cv_producer, &mutex);
        }

        int item = rand() % 100;
        if (front == -1 && rear == -1) {
            front = 0;
            rear = 0;
        }
        else {
            rear += 1;
        }
        queue[rear] = item;
        printf("Produced Item: %d\n", item);

        if (rear == MAX_SIZE-1 || front == -1) {
            pthread_cond_signal(&cv_consumer);
        }

        pthread_mutex_unlock(&mutex);
    }
}

void* consumer(void* args) {
    while(1) {
        pthread_mutex_lock(&mutex);
        if (front == -1) {
            printf("Consumer Buffer Empty\n");
            pthread_cond_wait(&cv_consumer, &mutex);
        }

        int item = queue[front];
        printf("Consumed Item: %d\n", item);

        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = front + 1;
        }

        if (front == 0) {
            pthread_cond_signal(&cv_producer);
        }

        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    pthread_t thread_producer, thread_consumer;
    srand(time(NULL));

    pthread_create(&thread_producer, NULL, &producer, NULL);
    pthread_create(&thread_consumer, NULL, &consumer, NULL);

    pthread_join(thread_producer, NULL);
    pthread_join(thread_consumer, NULL);

    return 0;
}