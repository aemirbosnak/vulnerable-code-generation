//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_THREADS 10
#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Entry;

typedef struct {
    int count;
    pthread_mutex_t lock;
    Entry entries[MAX_THREADS];
} ThreadData;

void *thread_function(void *arg) {
    ThreadData *data = (ThreadData *) arg;
    int index = (int) data - (int) &arg;
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];

    while (1) {
        pthread_mutex_lock(&data->lock);
        if (data->count >= MAX_THREADS) {
            pthread_mutex_unlock(&data->lock);
            break;
        }
        data->count++;
        pthread_mutex_unlock(&data->lock);

        printf("Enter key: ");
        scanf("%s", key);
        printf("Enter value: ");
        scanf("%s", value);

        strcpy(data->entries[index].key, key);
        strcpy(data->entries[index].value, value);

        printf("Indexed %s -> %s\n", key, value);
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    ThreadData data;
    data.count = 0;
    pthread_mutex_init(&data.lock, NULL);

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, &data);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}