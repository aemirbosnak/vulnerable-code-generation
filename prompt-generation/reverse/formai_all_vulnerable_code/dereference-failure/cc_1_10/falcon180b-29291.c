//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_ITER 100

int main(int argc, char *argv[]) {
    int i, j, n;
    int *arr1, *arr2;
    clock_t start, end;

    srand(time(NULL));
    n = rand() % MAX_SIZE + 1;

    arr1 = (int *) malloc(n * sizeof(int));
    arr2 = (int *) malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        arr1[i] = rand() % 100;
        arr2[i] = rand() % 100;
    }

    printf("Sorting %d integers...\n", n);
    for (j = 0; j < MAX_ITER; j++) {
        start = clock();
        for (i = 0; i < n - 1; i++) {
            int min_idx = i;
            int min_val = arr1[i];
            for (int k = i + 1; k < n; k++) {
                if (arr1[k] < min_val) {
                    min_idx = k;
                    min_val = arr1[k];
                }
            }
            if (min_idx!= i) {
                int temp = arr1[i];
                arr1[i] = arr1[min_idx];
                arr1[min_idx] = temp;
            }
        }
        end = clock();
        printf("Iteration %d took %ld clock cycles.\n", j + 1, end - start);
    }

    free(arr1);
    free(arr2);

    return 0;
}