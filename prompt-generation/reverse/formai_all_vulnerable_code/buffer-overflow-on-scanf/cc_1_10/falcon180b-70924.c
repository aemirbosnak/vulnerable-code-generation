//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 4
#define MAX_NUM 10000
#define PRIME_NUM 101

int num_threads;
int max_num;
int prime_num;
pthread_mutex_t mutex;

void *worker(void *param) {
    int i;
    int thread_num = *(int *)param;

    for (i = thread_num * max_num / num_threads; i < (thread_num + 1) * max_num / num_threads; i++) {
        if (i % prime_num == 0) {
            pthread_mutex_lock(&mutex);
            printf("Thread %d found prime number: %d\n", thread_num, i);
            pthread_mutex_unlock(&mutex);
        }
    }

    return NULL;
}

int main() {
    int i;
    pthread_t threads[NUM_THREADS];
    int thread_nums[NUM_THREADS];

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    printf("Enter the maximum number to check: ");
    scanf("%d", &max_num);

    printf("Enter the prime number: ");
    scanf("%d", &prime_num);

    pthread_mutex_init(&mutex, NULL);

    for (i = 0; i < num_threads; i++) {
        thread_nums[i] = i;
        pthread_create(&threads[i], NULL, worker, &thread_nums[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}