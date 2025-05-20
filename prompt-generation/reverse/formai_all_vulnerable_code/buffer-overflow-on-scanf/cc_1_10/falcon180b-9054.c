//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {
    int i, j, n;
    int *array1, *array2;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the size of the arrays: ");
    scanf("%d", &n);

    array1 = (int *)malloc(n * sizeof(int));
    array2 = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        array1[i] = rand() % MAX_SIZE;
        array2[i] = rand() % MAX_SIZE;
    }

    start = clock();
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (array1[j] > array1[j + 1]) {
                int temp = array1[j];
                array1[j] = array1[j + 1];
                array1[j + 1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Bubble Sort took %lf seconds to execute.\n", cpu_time_used);

    start = clock();
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 2; j++) {
            if (array2[j] > array2[j + 1]) {
                int temp = array2[j];
                array2[j] = array2[j + 1];
                array2[j + 1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Selection Sort took %lf seconds to execute.\n", cpu_time_used);

    return 0;
}