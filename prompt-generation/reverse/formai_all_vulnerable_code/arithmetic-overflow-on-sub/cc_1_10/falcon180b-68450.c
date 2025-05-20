//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define MAX_THREADS 10
#define MAX_ROWS 20
#define MAX_COLS 20

typedef struct {
    int id;
    int start_row;
    int end_row;
    int col;
} thread_data_t;

void *print_pattern(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int row, col, i, j;

    for (row = data->start_row; row <= data->end_row; row++) {
        for (col = 0; col < data->col; col++) {
            printf("*");
        }
        printf("\n");
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    thread_data_t data[MAX_THREADS];
    int rows, cols, i, j, start_row, end_row, col;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    start_row = 0;
    end_row = rows - 1;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i == j) {
                data[i].id = i;
                data[i].start_row = start_row;
                data[i].end_row = end_row;
                data[i].col = cols;
            }
        }
    }

    for (i = 0; i < rows; i++) {
        pthread_create(&threads[i], NULL, print_pattern, (void *) &data[i]);
    }

    for (i = 0; i < rows; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}