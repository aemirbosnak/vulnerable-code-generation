//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define MAX_THREADS 10
#define MAX_ROWS 10
#define MAX_COLS 10

int shared_data[MAX_ROWS][MAX_COLS];
int num_threads;
int num_rows;
int num_cols;
int thread_rows[MAX_THREADS];
int thread_cols[MAX_THREADS];
pthread_t threads[MAX_THREADS];
sem_t mutex;

void *runner(void *arg) {
    int id = *(int *) arg;
    int row = thread_rows[id];
    int col = thread_cols[id];
    int count = 0;

    while(count < 10) {
        sem_wait(&mutex);
        shared_data[row][col] = id + count;
        printf("Thread %d wrote %d at (%d,%d)\n", id, shared_data[row][col], row, col);
        count++;
        sem_post(&mutex);
        usleep(100000);
    }

    return NULL;
}

int main() {
    int i, j;
    srand(time(NULL));

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    printf("Enter number of rows: ");
    scanf("%d", &num_rows);

    printf("Enter number of columns: ");
    scanf("%d", &num_cols);

    for(i = 0; i < num_threads; i++) {
        thread_rows[i] = rand() % num_rows;
        thread_cols[i] = rand() % num_cols;
    }

    sem_init(&mutex, 0, 1);

    for(i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, runner, &i);
    }

    for(i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}