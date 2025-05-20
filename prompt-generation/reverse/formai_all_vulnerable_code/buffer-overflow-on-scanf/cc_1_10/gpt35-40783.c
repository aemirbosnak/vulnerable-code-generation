//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS 20

pthread_mutex_t mutex;
pthread_cond_t cond;
int thread_counter = 0;

void *worker(void *arg) {
    int id = *((int*)arg);
    printf("Thread %d created\n", id);

    usleep(id*10000); // simulate work
    printf("Thread %d finished work\n", id);

    pthread_mutex_lock(&mutex);
    thread_counter--;
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);

    printf("Thread %d exited\n", id);
    pthread_exit(NULL);
}

void spawn_threads(int n) {
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    for (int i = 0; i < n; i++) {
        thread_ids[i] = i+1;
        pthread_create(&threads[i], NULL, worker, &thread_ids[i]);
        thread_counter++;
    }

    pthread_mutex_lock(&mutex);
    while (thread_counter > 0) {
        pthread_cond_wait(&cond, &mutex);
    }
    pthread_mutex_unlock(&mutex);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
}

int main() {
    int num_threads;

    printf("Enter number of threads to spawn [1-20]: ");
    scanf("%d", &num_threads);

    if (num_threads > 0 && num_threads <= MAX_THREADS) {
        spawn_threads(num_threads);
        printf("All threads finished work\n");
    } else {
        printf("Invalid number of threads\n");
    }

    return 0;
}