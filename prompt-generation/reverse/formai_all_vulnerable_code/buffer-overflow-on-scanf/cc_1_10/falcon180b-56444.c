//Falcon-180B DATASET v1.0 Category: Educational ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, temp;
    int *arr;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    arr = (int *) malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    printf("Enter %d integers:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    start = clock();
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array in ascending order:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    printf("CPU time used: %.4f seconds\n", cpu_time_used);

    free(arr);
    return 0;
}