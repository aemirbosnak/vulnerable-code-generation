//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10000000
#define MAX_TERMS 1000

int main() {
    int i, j, n, m, a, b, c, terms;
    int *fib;
    double start_time, end_time;
    srand(time(NULL));

    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    if (terms > MAX_TERMS) {
        printf("Error: Maximum number of terms is %d.\n", MAX_TERMS);
        return 1;
    }

    fib = (int *)malloc(terms * sizeof(int));

    printf("Enter the starting number: ");
    scanf("%d", &n);

    if (n > MAX_NUM) {
        printf("Error: Starting number too large.\n");
        return 1;
    }

    printf("Enter the ending number: ");
    scanf("%d", &m);

    if (m > MAX_NUM) {
        printf("Error: Ending number too large.\n");
        return 1;
    }

    fib[0] = n;
    fib[1] = m;

    for (i = 2; i < terms; i++) {
        a = fib[i - 1];
        b = fib[i - 2];
        c = a + b;
        if (c > MAX_NUM) {
            printf("Error: Fibonacci number too large.\n");
            return 1;
        }
        fib[i] = c;
    }

    printf("Fibonacci sequence:\n");
    for (i = 0; i < terms; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    start_time = clock();
    for (i = 0; i < terms; i++) {
        for (j = 0; j < terms; j++) {
            if (fib[i] == fib[j]) {
                printf("%d appears %d times in the sequence.\n", fib[i], i + 1);
                break;
            }
        }
    }
    end_time = clock();

    printf("Execution time: %.6f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    free(fib);
    return 0;
}