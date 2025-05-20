//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    int n, i, j, k, max = 0;
    int **buckets;
    int *bucket_sizes;
    int *input;
    int *output;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    input = (int *)malloc(n * sizeof(int));
    output = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &input[i]);
        if (input[i] > max) {
            max = input[i];
        }
    }

    buckets = (int **)malloc((max + 1) * sizeof(int *));
    bucket_sizes = (int *)malloc((max + 1) * sizeof(int));

    for (i = 0; i <= max; i++) {
        buckets[i] = (int *)malloc(n * sizeof(int));
        bucket_sizes[i] = 0;
    }

    for (i = 0; i < n; i++) {
        buckets[input[i]][bucket_sizes[input[i]]++] = input[i];
    }

    k = 0;
    for (i = 0; i <= max; i++) {
        for (j = 0; j < bucket_sizes[i]; j++) {
            output[k++] = buckets[i][j];
        }
        free(buckets[i]);
    }
    free(buckets);
    free(bucket_sizes);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");

    free(input);
    free(output);

    return 0;
}