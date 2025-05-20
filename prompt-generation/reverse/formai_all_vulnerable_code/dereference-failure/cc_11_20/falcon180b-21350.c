//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000
#define REPEAT_TIMES 10

int main() {
    int i, j, n;
    int* arr;
    double elapsed_time;

    srand(time(NULL));

    // generate random array
    arr = (int*) malloc(MAX_SIZE * sizeof(int));
    for (i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // sort array
    for (i = 0; i < REPEAT_TIMES; i++) {
        for (j = 0; j < MAX_SIZE - 1; j++) {
            for (n = j + 1; n < MAX_SIZE; n++) {
                if (arr[j] > arr[n]) {
                    int temp = arr[j];
                    arr[j] = arr[n];
                    arr[n] = temp;
                }
            }
        }
    }

    // measure elapsed time
    clock_t start = clock();
    for (i = 0; i < REPEAT_TIMES; i++) {
        for (j = 0; j < MAX_SIZE - 1; j++) {
            for (n = j + 1; n < MAX_SIZE; n++) {
                if (arr[j] > arr[n]) {
                    int temp = arr[j];
                    arr[j] = arr[n];
                    arr[n] = temp;
                }
            }
        }
    }
    clock_t end = clock();
    elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;

    // print results
    printf("Sorted array:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Elapsed time: %lf seconds\n", elapsed_time);

    free(arr);

    return 0;
}