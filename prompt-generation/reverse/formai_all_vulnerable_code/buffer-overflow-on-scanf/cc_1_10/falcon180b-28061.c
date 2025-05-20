//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    int i, j, n, m, sum = 0;
    int *a, *b, *c;
    double start_time, end_time;

    printf("Enter the size of the arrays: ");
    scanf("%d", &n);

    a = (int *) malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory error!\n");
        exit(1);
    }

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    m = n / 2;
    b = (int *) malloc(m * sizeof(int));
    c = (int *) malloc(n - m * sizeof(int));

    if (b == NULL || c == NULL) {
        printf("Memory error!\n");
        exit(1);
    }

    for (i = 0; i < m; i++) {
        b[i] = a[i];
    }

    for (i = m; i < n; i++) {
        c[i - m] = a[i];
    }

    start_time = clock();
    for (i = 0; i < m; i++) {
        for (j = 0; j < n - m; j++) {
            sum += b[i] * c[j];
        }
    }

    end_time = clock();

    printf("The sum of the products is: %d\n", sum);
    printf("Time taken: %.6f seconds\n", (double) (end_time - start_time) / CLOCKS_PER_SEC);

    free(a);
    free(b);
    free(c);

    return 0;
}