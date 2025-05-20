//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int i, j;
    int *array;
    int n;
    float time_taken;

    srand(time(NULL));

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    array = (int *) malloc(n * sizeof(int));

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Sorting the array using Bucket Sort
    for (i = 0; i < n; i++) {
        int bucket_index = array[i] * SIZE / n;
        int *bucket = (int *) malloc(n * sizeof(int));
        int count = 0;

        for (j = 0; j < n; j++) {
            if (array[j] == array[i]) {
                bucket[count++] = array[j];
            }
        }

        for (j = 0; j < count; j++) {
            array[bucket_index + j] = bucket[j];
        }

        free(bucket);
    }

    // Printing the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    free(array);

    return 0;
}