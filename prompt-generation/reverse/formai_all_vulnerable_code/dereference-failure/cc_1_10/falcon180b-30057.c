//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS 4
#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} record_t;

typedef struct {
    record_t *records;
    int num_records;
    pthread_mutex_t lock;
} table_t;

table_t *create_table() {
    table_t *table = malloc(sizeof(table_t));
    table->records = NULL;
    table->num_records = 0;
    pthread_mutex_init(&table->lock, NULL);
    return table;
}

void destroy_table(table_t *table) {
    int i;
    for (i = 0; i < table->num_records; i++) {
        free(table->records[i].key);
        free(table->records[i].value);
    }
    free(table->records);
    pthread_mutex_destroy(&table->lock);
    free(table);
}

int compare_keys(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void *index_thread(void *arg) {
    table_t *table = arg;
    int i;
    qsort(table->records, table->num_records, sizeof(record_t), compare_keys);
    for (i = 0; i < table->num_records; i++) {
        printf("%s:%s\n", table->records[i].key, table->records[i].value);
    }
    return NULL;
}

int main() {
    table_t *table = create_table();
    int i;
    for (i = 0; i < 10; i++) {
        sprintf(table->records[i].key, "key_%d", i);
        sprintf(table->records[i].value, "value_%d", i);
    }
    table->num_records = 10;

    pthread_t threads[NUM_THREADS];
    int rc;
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, index_thread, table);
        if (rc) {
            fprintf(stderr, "Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    destroy_table(table);

    return 0;
}