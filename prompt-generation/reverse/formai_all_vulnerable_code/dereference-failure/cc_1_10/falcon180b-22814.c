//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {
    int i, j, n;
    int *array1, *array2;
    clock_t start, end;

    //initialize arrays
    array1 = (int *) malloc(MAX_SIZE * sizeof(int));
    array2 = (int *) malloc(MAX_SIZE * sizeof(int));

    //fill arrays with random numbers
    for (i = 0; i < MAX_SIZE; i++) {
        array1[i] = rand() % 100;
        array2[i] = rand() % 100;
    }

    //ask user for array size
    printf("Enter array size: ");
    scanf("%d", &n);

    //initialize start time
    start = clock();

    //perform merge sort on arrays
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (array1[j] > array1[j + 1]) {
                int temp = array1[j];
                array1[j] = array1[j + 1];
                array1[j + 1] = temp;
            }
        }
    }

    //initialize end time and calculate elapsed time
    end = clock();
    double elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;

    //print sorted array and elapsed time
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array1[i]);
    }
    printf("\nElapsed time: %.6f seconds\n", elapsed_time);

    //free memory
    free(array1);
    free(array2);

    return 0;
}