//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 10

typedef struct {
    int row;
    int col;
    int value;
} element;

element matrix1[MAX_SIZE][MAX_SIZE];
element matrix2[MAX_SIZE][MAX_SIZE];
element result[MAX_SIZE][MAX_SIZE];

void *sum_rows(void *arg);
void *sum_cols(void *arg);

int main() {
    int i, j;
    for(i=0; i<MAX_SIZE; i++) {
        for(j=0; j<MAX_SIZE; j++) {
            matrix1[i][j].value = i+j;
            matrix2[i][j].value = i-j;
        }
    }

    int num_threads = 4;
    pthread_t threads[num_threads];

    // Create threads to sum rows
    for(i=0; i<MAX_SIZE; i++) {
        pthread_create(&threads[i], NULL, sum_rows, (void *)&matrix1[i]);
    }

    // Create threads to sum columns
    for(j=0; j<MAX_SIZE; j++) {
        pthread_create(&threads[MAX_SIZE+j], NULL, sum_cols, (void *)&matrix2[0][j]);
    }

    // Join all threads
    for(i=0; i<MAX_SIZE; i++) {
        pthread_join(threads[i], NULL);
    }
    for(j=0; j<MAX_SIZE; j++) {
        pthread_join(threads[MAX_SIZE+j], NULL);
    }

    // Print results
    for(i=0; i<MAX_SIZE; i++) {
        for(j=0; j<MAX_SIZE; j++) {
            printf("%d ", result[i][j].value);
        }
        printf("\n");
    }

    return 0;
}

void *sum_rows(void *arg) {
    int row = *(int *)arg;
    int sum = 0;
    int i;
    for(i=0; i<MAX_SIZE; i++) {
        sum += matrix1[row][i].value;
    }
    result[row][0].value = sum;
    return NULL;
}

void *sum_cols(void *arg) {
    int col = *(int *)arg;
    int sum = 0;
    int i;
    for(i=0; i<MAX_SIZE; i++) {
        sum += matrix2[i][col].value;
    }
    result[0][col].value = sum;
    return NULL;
}