//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, target, i, j;
    int *arr;
    clock_t start, end;
    double cpu_time_used;

    //Initialize random seed
    srand(time(0));

    //Get array size from user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    //Allocate memory for array
    arr = (int *) malloc(n * sizeof(int));

    //Fill array with random numbers
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    //Get target value from user
    printf("Enter the target value: ");
    scanf("%d", &target);

    //Start timer
    start = clock();

    //Perform linear search
    for (i = 0; i < n; i++) {
        if (arr[i] == target) {
            printf("Element found at index %d\n", i);
            break;
        }
    }

    //Stop timer
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    //Print time taken for search
    printf("Time taken for search: %.6f seconds\n", cpu_time_used);

    //Free memory
    free(arr);

    return 0;
}