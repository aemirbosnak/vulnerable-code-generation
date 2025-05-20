//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_RANGE 1000000

int main() {
    int i, j, n, range;
    int *arr;
    clock_t start, end;
    double cpu_time_used;

    // get user input for number of elements and range
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the range: ");
    scanf("%d", &range);

    // allocate memory for array
    arr = (int *)malloc(n * sizeof(int));

    // fill array with random numbers
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % range;
    }

    // print unsorted array
    printf("Unsorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // start timer
    start = clock();

    // perform bucket sort
    for (i = 0; i < n; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (arr[i] == j) {
                arr[i] = MAX_SIZE - j;
                break;
            }
        }
    }

    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < n; j++) {
            if (arr[j] == i) {
                arr[j] = j;
                break;
            }
        }
    }

    // print sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // stop timer
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // print time taken for sorting
    printf("Time taken for sorting: %f seconds\n", cpu_time_used);

    return 0;
}