//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    int id;
    int row;
    int col;
} thread_data_t;

void *print_pattern(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int id = data->id;
    int row = data->row;
    int col = data->col;

    for (int i = 0; i < row; i++) {
        printf("Thread %d printing row %d, column %d\n", id, row, col);
        for (int j = 0; j < col; j++) {
            printf("*");
        }
        printf("\n");
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    thread_data_t data[MAX_THREADS];
    int num_threads = 0;

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    for (int i = 0; i < num_threads; i++) {
        printf("Enter thread %d data:\n", i+1);
        printf("Enter row: ");
        scanf("%d", &data[i].row);
        printf("Enter column: ");
        scanf("%d", &data[i].col);
        data[i].id = i+1;

        pthread_create(&threads[i], NULL, print_pattern, &data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}