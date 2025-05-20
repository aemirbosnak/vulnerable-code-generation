//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_ROWS 100
#define MAX_COLUMNS 100

typedef struct {
    int id;
    char name[50];
    int age;
} Record;

Record database[MAX_ROWS];
int num_records = 0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *arg) {
    int thread_id = *(int *) arg;
    char thread_name[10];
    sprintf(thread_name, "Thread %d", thread_id);
    pthread_setname_np(pthread_self(), thread_name);

    int i;
    for (i = 0; i < 10; i++) {
        pthread_mutex_lock(&lock);
        if (num_records >= MAX_ROWS) {
            printf("Database is full. Cannot insert more records.\n");
            pthread_mutex_unlock(&lock);
            break;
        }

        printf("Thread %s is inserting a record...\n", thread_name);
        Record record;
        scanf("%d %s %d", &record.id, record.name, &record.age);
        database[num_records] = record;
        num_records++;

        printf("Thread %s inserted a record with ID %d.\n", thread_name, record.id);
        pthread_mutex_unlock(&lock);

        sleep(1);
    }

    return NULL;
}

int main() {
    int i;
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, thread_func, (void *) &i);
    }

    for (i = 0; i < MAX_ROWS; i++) {
        if (database[i].id == 0) {
            break;
        }

        printf("Record %d: ID %d, Name %s, Age %d\n", i, database[i].id, database[i].name, database[i].age);
    }

    return 0;
}