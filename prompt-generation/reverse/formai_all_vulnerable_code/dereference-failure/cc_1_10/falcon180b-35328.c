//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 1000
#define MAX_NUM_THREADS 10

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} Record;

typedef struct {
    Record *records;
    int num_records;
    pthread_mutex_t lock;
} Database;

void *thread_func(void *arg) {
    Database *db = (Database *) arg;
    int i;

    for (i = 0; i < db->num_records; i++) {
        pthread_mutex_lock(&db->lock);
        printf("Key: %s, Value: %s\n", db->records[i].key, db->records[i].value);
        pthread_mutex_unlock(&db->lock);
    }

    return NULL;
}

int main() {
    int i, num_threads;
    pthread_t threads[MAX_NUM_THREADS];
    Database db;

    db.records = (Record *) malloc(MAX_NUM_THREADS * sizeof(Record));
    db.num_records = 0;

    pthread_mutex_init(&db.lock, NULL);

    strcpy(db.records[db.num_records].key, "John");
    strcpy(db.records[db.num_records].value, "25");
    db.num_records++;

    strcpy(db.records[db.num_records].key, "Jane");
    strcpy(db.records[db.num_records].value, "30");
    db.num_records++;

    num_threads = db.num_records;

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) &db);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    free(db.records);

    return 0;
}