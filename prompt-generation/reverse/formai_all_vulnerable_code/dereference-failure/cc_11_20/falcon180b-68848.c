//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define MAX_VALUE 10000

int main() {
    int n, i, j, max_value = 0;
    float *array;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    array = (float *) malloc(n * sizeof(float));

    // Fill the array with random values
    for (i = 0; i < n; i++) {
        array[i] = rand() % MAX_VALUE;
        if (array[i] > max_value) {
            max_value = array[i];
        }
    }

    // Create the buckets
    float **buckets = (float **) malloc(max_value * sizeof(float *));
    for (i = 0; i < max_value; i++) {
        buckets[i] = (float *) malloc(n * sizeof(float));
    }

    // Distribute the elements into the buckets
    for (i = 0; i < n; i++) {
        j = array[i] / (MAX_VALUE / (MAX_SIZE - 1));
        buckets[j][buckets[j][0] == 0] = array[i];
    }

    // Sort each bucket using insertion sort
    for (i = 0; i < max_value; i++) {
        if (buckets[i][0]!= 0) {
            for (j = 1; j < buckets[i][0]; j++) {
                if (buckets[i][j - 1] > buckets[i][j]) {
                    float temp = buckets[i][j - 1];
                    buckets[i][j - 1] = buckets[i][j];
                    buckets[i][j] = temp;
                }
            }
        }
    }

    // Merge the sorted buckets back into the original array
    for (i = 0; i < n; i++) {
        array[i] = 0;
    }
    for (i = 0; i < max_value; i++) {
        for (j = 0; j < buckets[i][0]; j++) {
            array[j] = buckets[i][j];
        }
    }

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%f ", array[i]);
    }
    printf("\n");

    free(array);
    for (i = 0; i < max_value; i++) {
        free(buckets[i]);
    }
    free(buckets);

    return 0;
}