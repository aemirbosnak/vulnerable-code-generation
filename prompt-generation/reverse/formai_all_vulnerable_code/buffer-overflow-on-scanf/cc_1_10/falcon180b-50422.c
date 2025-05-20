//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000
#define MIN 1

int main() {
    int i, j, k, n, m, count, sum;
    int *arr1, *arr2;
    double start, end;

    printf("Enter the size of the first array: ");
    scanf("%d", &n);
    printf("Enter the size of the second array: ");
    scanf("%d", &m);

    arr1 = (int *) malloc(n * sizeof(int));
    arr2 = (int *) malloc(m * sizeof(int));

    printf("Enter the elements of the first array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the elements of the second array: ");
    for (j = 0; j < m; j++) {
        scanf("%d", &arr2[j]);
    }

    start = clock();
    for (k = MIN; k <= MAX; k += 1000) {
        count = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (arr1[i] == k && arr2[j] == k) {
                    count++;
                }
            }
        }
        sum += count;
    }
    end = clock();

    printf("Time taken for benchmarking: %lf seconds\n", (double) (end - start) / CLOCKS_PER_SEC);

    printf("Number of occurrences of %d in the first array: %d\n", k, count);
    printf("Number of occurrences of %d in the second array: %d\n", k, count);

    free(arr1);
    free(arr2);

    return 0;
}