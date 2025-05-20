//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_ROWS 50
#define MAX_COLS 100
#define MAX_FIB_NUM 1000000
#define DELAY 100000
#define ROW_HEIGHT 20
#define COL_WIDTH 10

int main() {
    int rows, cols, max_fib_num, row, col, i, j, k, fib_num;
    int **fib_table;
    time_t start_time, end_time, elapsed_time;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("Enter the maximum Fibonacci number: ");
    scanf("%d", &max_fib_num);

    fib_table = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        fib_table[i] = (int *)malloc(cols * sizeof(int));
        for (j = 0; j < cols; j++) {
            fib_table[i][j] = 0;
        }
    }

    printf("Generating Fibonacci sequence...\n");
    start_time = time(NULL);
    for (row = 0; row < rows; row++) {
        for (col = 0; col < cols; col++) {
            fib_num = 0;
            for (i = 0; fib_num < max_fib_num && i < 1000; i++) {
                fib_num = fibonacci(fib_num);
            }
            fib_table[row][col] = fib_num;
        }
    }
    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    printf("Elapsed time: %ld seconds\n", elapsed_time);

    for (row = 0; row < rows; row++) {
        for (col = 0; col < cols; col++) {
            printf("%d ", fib_table[row][col]);
        }
        printf("\n");
    }

    for (i = 0; i < rows; i++) {
        free(fib_table[i]);
    }
    free(fib_table);

    return 0;
}

int fibonacci(int num) {
    if (num == 0) {
        return 0;
    } else if (num == 1) {
        return 1;
    } else {
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
}