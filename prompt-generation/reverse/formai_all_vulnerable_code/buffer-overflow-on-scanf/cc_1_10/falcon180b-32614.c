//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000
#define M 1000

int main() {
    int i, j, k, n, m, seed, *a, *b, *c, sum;
    clock_t start, end;

    printf("Enter the size of the arrays: ");
    scanf("%d", &n);

    a = (int*) malloc(n * sizeof(int));
    b = (int*) malloc(n * sizeof(int));
    c = (int*) malloc(n * sizeof(int));

    printf("Enter the elements of array 1:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the elements of array 2:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    printf("Enter the number of iterations: ");
    scanf("%d", &m);

    srand(time(NULL));
    seed = rand();

    start = clock();
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            sum = 0;
            for (k = 0; k < n; k++) {
                sum += ((a[k] & b[k]) | (a[k] ^ b[k])) << k;
            }
            c[j] = sum >> (n - 1);
        }
    }
    end = clock();

    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    printf("Result:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}