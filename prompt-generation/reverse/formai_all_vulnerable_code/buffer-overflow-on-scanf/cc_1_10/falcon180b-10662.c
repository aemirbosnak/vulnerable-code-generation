//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {
    int i, j, n, m, sum = 0;
    int *a, *b;
    clock_t start, end;

    printf("Enter the size of the arrays: ");
    scanf("%d", &n);

    a = (int *) malloc(n * sizeof(int));
    if (!a) {
        printf("Memory error\n");
        exit(0);
    }

    printf("Enter the elements of the first array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &m);

    b = (int *) malloc(m * sizeof(int));
    if (!b) {
        printf("Memory error\n");
        exit(0);
    }

    printf("Enter the elements of the second array: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    start = clock();
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            sum += a[i] * b[j];
        }
    }
    end = clock();

    printf("The sum of the product is %d\n", sum);
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}