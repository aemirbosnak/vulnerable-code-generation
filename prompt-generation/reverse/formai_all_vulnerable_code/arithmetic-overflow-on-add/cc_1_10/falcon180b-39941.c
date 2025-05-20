//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Structure for passing data to threads
struct v {
    int row;
    int col;
    int **mat;
};

// Function to be executed by each thread
void *runner(void *param) {
    struct v *data = param;
    int sum = 0;

    // Calculate sum of row elements
    for (int i = 0; i < data->col; i++) {
        sum += data->mat[data->row][i];
    }

    // Print result
    printf("Sum of row %d is %d\n", data->row, sum);

    return NULL;
}

int main() {
    int mat[MAX_ROWS][MAX_COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = 3;
    int cols = 3;
    pthread_t threads[rows];

    // Create threads
    for (int i = 0; i < rows; i++) {
        struct v data;
        data.row = i;
        data.col = cols;
        data.mat = mat;
        pthread_create(&threads[i], NULL, runner, (void *)&data);
    }

    // Join threads
    for (int i = 0; i < rows; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}