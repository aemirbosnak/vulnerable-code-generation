//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define MAX_ACCOUNTS 100
#define MAX_THREADS 10
#define MAX_TRANSACTIONS 100

typedef struct {
    int account_number;
    char name[50];
    float balance;
} Account;

typedef struct {
    int thread_id;
    Account accounts[MAX_ACCOUNTS];
    pthread_mutex_t mutex;
} ThreadData;

void *thread_func(void *arg) {
    ThreadData *thread_data = (ThreadData *) arg;
    int i;

    for (i = 0; i < MAX_ACCOUNTS; i++) {
        pthread_mutex_lock(&thread_data->mutex);
        printf("Thread %d is processing account %d\n", thread_data->thread_id, i);
        pthread_mutex_unlock(&thread_data->mutex);
        sleep(1);
    }

    return NULL;
}

int main() {
    int i, j, num_threads;
    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];

    srand(time(NULL));

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    for (i = 0; i < num_threads; i++) {
        thread_data[i].thread_id = i;
        for (j = 0; j < MAX_ACCOUNTS; j++) {
            thread_data[i].accounts[j].account_number = rand() % MAX_ACCOUNTS;
            sprintf(thread_data[i].accounts[j].name, "Account %d", thread_data[i].accounts[j].account_number);
            thread_data[i].accounts[j].balance = rand() % 1000;
        }
        pthread_create(&threads[i], NULL, thread_func, &thread_data[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}