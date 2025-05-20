//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int array[MAX_SIZE], n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Bucket sort implementation
    int min = array[0], max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] < min) {
            min = array[i];
        } else if (array[i] > max) {
            max = array[i];
        }
    }

    int bucket_size = (max - min) / n + 1;
    int **buckets = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        buckets[i] = (int *) malloc(bucket_size * sizeof(int));
        for (int j = 0; j < bucket_size; j++) {
            buckets[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        int bucket_index = (array[i] - min) / bucket_size;
        buckets[bucket_index][array[i] - min % bucket_size] = i;
    }

    int sorted_array[n];
    for (int i = 0; i < n; i++) {
        sorted_array[i] = -1;
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket_size; j++) {
            if (buckets[i][j]!= -1) {
                sorted_array[index++] = buckets[i][j];
            }
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", sorted_array[i]);
    }

    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
    free(buckets);

    return 0;
}