//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int fib[MAX][MAX]; // 2D array to store Fibonacci sequence
    int i, j, n, numRows;

    printf("Enter the number of rows in the spiral: ");
    scanf("%d", &n);

    fib[0][0] = fib[0][1] = 1; // Initialize first row

    numRows = 1; // Number of rows

    for (i = 2; i <= n; i++) {
        fib[i][0] = fib[i - 1][i - 2]; // First element of new row
        fib[i][i] = fib[i - 1][i - 1] + fib[i - 1][i - 2]; // Last element of new row

        if (i > 2) {
            fib[i][i - 1] = fib[i - 1][i - 1] + fib[i - 1][i - 2]; // Second last element of new row
        }

        numRows++; // Increment number of rows
    }

    // Print the spiral sequence
    i = 0;
    j = 0;

    while (numRows > 0) {
        for (; j < n; j++) {
            printf("%d ", fib[i][j]);
        }
        j--; // Back to the previous column

        for (; i < n; i++) {
            printf("%d ", fib[i][j]);
        }
        i--; // Back to the previous row

        numRows--;

        if (numRows > 0) {
            j--; // Back to the previous column
            i--; // Back to the previous row
        }
    }

    printf("\n");

    return 0;
}