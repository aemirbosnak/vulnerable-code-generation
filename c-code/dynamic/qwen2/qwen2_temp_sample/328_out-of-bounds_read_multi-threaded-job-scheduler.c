#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10
#define JOB_QUEUE_SIZE 100

typedef struct {
    int id;
} Job;

Job queue[JOB_QUEUE_SIZE];
int front = 0;
int rear = -1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_not_empty = PTHREAD_COND_INITIALIZER;

void enqueue(Job job) {
    pthread_mutex_lock(&mutex);
    while ((rear + 1) % JOB_QUEUE_SIZE == front) {
        pthread_cond_wait(&cond_not_full, &mutex);
    }
    rear = (rear + 1) % JOB_QUEUE_SIZE;
    queue[rear] = job;
    pthread_cond_signal(&cond_not_empty);
    pthread_mutex_unlock(&mutex);
}

Job dequeue() {
    pthread_mutex_lock(&mutex);
    while (front == (rear + 1) % JOB_QUEUE_SIZE) {
        pthread_cond_wait(&cond_not_empty, &mutex);
    }
    Job job = queue[front];
    front = (front + 1) % JOB_QUEUE_SIZE;
    pthread_cond_signal(&cond_not_full);
    pthread_mutex_unlock(&mutex);
    return job;
}

void* worker_thread(void* arg) {
    int thread_id = *(int*)arg;
    while (1) {
        Job job = dequeue();
        printf("Thread %d processing job %d\n", thread_id, job.id);
        // Deliberate out-of-bounds read vulnerability here
        char data[10];
        memcpy(data, "Some data", sizeof(data));
        // The following line causes an out-of-bounds read
        printf("%s\n", data + 20);
        sleep(1);
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, worker_thread, &thread_ids[i]);
    }

    for (int i = 0; i < JOB_QUEUE_SIZE; i++) {
        Job job;
        job.id = i;
        enqueue(job);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
