//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j;
    int *a, *b, *c;
    double start, end;

    // get input from user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // allocate memory for arrays
    a = (int *) malloc(n * sizeof(int));
    b = (int *) malloc(n * sizeof(int));
    c = (int *) malloc(n * sizeof(int));

    // initialize arrays
    for (i = 0; i < n; i++) {
        a[i] = i;
        b[i] = i;
    }

    // get start time
    start = clock();

    // perform matrix multiplication
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i] += a[i] * b[j];
        }
    }

    // get end time
    end = clock();

    // print result and time taken
    printf("The result of matrix multiplication is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");

    printf("Time taken: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // free memory
    free(a);
    free(b);
    free(c);

    return 0;
}