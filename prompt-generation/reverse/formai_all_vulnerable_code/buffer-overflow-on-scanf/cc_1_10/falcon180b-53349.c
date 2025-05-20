//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_KEY_LEN 256
#define MAX_VAL_LEN 1024
#define MAX_THREADS 4

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VAL_LEN];
} Record;

typedef struct {
    Record records[MAX_THREADS];
    int num_records;
    pthread_t threads[MAX_THREADS];
} ThreadData;

void *thread_func(void *data) {
    ThreadData *thread_data = (ThreadData *)data;
    int num_records = thread_data->num_records;
    Record *records = thread_data->records;
    int i;

    for (i = 0; i < num_records; i++) {
        printf("Thread %d processing record %s\n", pthread_self(), records[i].key);
        sleep(1);
    }

    return NULL;
}

int main() {
    ThreadData thread_data;
    int i, num_threads = 0;
    pthread_t threads[MAX_THREADS];

    printf("Enter number of records: ");
    scanf("%d", &thread_data.num_records);

    printf("Enter records:\n");
    for (i = 0; i < thread_data.num_records; i++) {
        scanf("%s %s", thread_data.records[i].key, thread_data.records[i].value);
    }

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_func, &thread_data);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}