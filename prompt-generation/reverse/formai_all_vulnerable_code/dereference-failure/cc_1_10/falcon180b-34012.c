//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_KEYS 100

typedef struct {
    int key;
    char value[100];
} Record;

Record database[MAX_KEYS];
int numRecords = 0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *threadFunction(void *arg) {
    int threadId = *(int *) arg;
    char *value = (char *) malloc(100 * sizeof(char));

    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&lock);
        if (numRecords >= MAX_KEYS) {
            printf("Database is full. Cannot insert record.\n");
            pthread_mutex_unlock(&lock);
            free(value);
            return NULL;
        }

        sprintf(value, "Thread %d inserted record %d", threadId, numRecords);
        strcpy(database[numRecords].value, value);
        database[numRecords].key = numRecords;
        numRecords++;
        printf("Thread %d inserted record %d\n", threadId, numRecords - 1);

        pthread_mutex_unlock(&lock);
        sleep(1);
    }

    free(value);
    return NULL;
}

int main() {
    int i;
    pthread_t threads[MAX_THREADS];

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, threadFunction, (void *) &i);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < numRecords; i++) {
        printf("Record %d: %s\n", i, database[i].value);
    }

    return 0;
}