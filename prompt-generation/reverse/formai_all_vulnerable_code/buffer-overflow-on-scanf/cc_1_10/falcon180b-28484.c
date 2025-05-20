//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 100000
#define ITERATIONS 1000000

void shape_shift(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j)
                continue;
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int i, j, n, m, sum;
    int *arr1, *arr2;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    arr1 = (int *)malloc(n * sizeof(int));
    arr2 = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the first array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr1[i]);

    printf("Enter the elements of the second array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr2[i]);

    start = clock();
    for (m = 0; m < ITERATIONS; m++) {
        for (i = 0; i < n; i++) {
            sum = 0;
            for (j = 0; j < n; j++) {
                if (arr1[i] == arr2[j]) {
                    sum++;
                }
            }
            if (sum > 0) {
                printf("%d occurs %d times in the second array.\n", arr1[i], sum);
            }
        }
        shape_shift(arr2, n);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nCPU time used: %lf seconds\n", cpu_time_used);

    free(arr1);
    free(arr2);

    return 0;
}