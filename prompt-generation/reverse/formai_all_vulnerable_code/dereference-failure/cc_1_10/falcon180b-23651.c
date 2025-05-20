//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_THREADS 10
#define MAX_KEY_LENGTH 20
#define MAX_VALUE_LENGTH 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
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
        printf("Thread %d: %s = %s\n", pthread_self(), db->records[i].key, db->records[i].value);
    }

    return NULL;
}

int main() {
    int i;
    Database db;
    pthread_t threads[MAX_THREADS];

    db.records = (Record *) malloc(MAX_THREADS * sizeof(Record));
    db.num_records = 0;

    pthread_mutex_init(&db.lock, NULL);

    strcpy(db.records[db.num_records].key, "Name");
    strcpy(db.records[db.num_records].value, "John Doe");
    db.num_records++;

    strcpy(db.records[db.num_records].key, "Age");
    strcpy(db.records[db.num_records].value, "30");
    db.num_records++;

    strcpy(db.records[db.num_records].key, "Gender");
    strcpy(db.records[db.num_records].value, "Male");
    db.num_records++;

    for (i = 0; i < db.num_records; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) &db);
    }

    for (i = 0; i < db.num_records; i++) {
        pthread_join(threads[i], NULL);
    }

    free(db.records);

    return 0;
}