//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_KEYS 1000
#define MAX_VALUES 1000

typedef struct {
    char key[50];
    char value[100];
    int index;
} Record;

Record database[MAX_KEYS];
int num_records = 0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* thread_func(void* arg) {
    int thread_num = *((int*) arg);
    char thread_name[10];
    sprintf(thread_name, "Thread %d", thread_num);
    pthread_setname_np(pthread_self(), thread_name);

    while (1) {
        pthread_mutex_lock(&lock);
        if (num_records >= MAX_KEYS) {
            printf("Thread %s: Database is full.\n", thread_name);
            pthread_mutex_unlock(&lock);
            break;
        }
        printf("Thread %s: Adding record...\n", thread_name);
        scanf("%s %s", database[num_records].key, database[num_records].value);
        database[num_records].index = num_records;
        num_records++;
        pthread_mutex_unlock(& lock);
        sleep(1);
    }

    return NULL;
}

int main() {
    int i;
    pthread_t threads[MAX_THREADS];

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void*) &i);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}