//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int i, n, max = 0, min = 1000, bucket_size, *arr;
    float range, step;
    char ch;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int*) malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    range = max - min;
    step = range / MAX_SIZE;
    bucket_size = step + 1;

    printf("Enter the bucket size: ");
    scanf("%d", &bucket_size);

    int *bucket[MAX_SIZE];
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int*) malloc(bucket_size * sizeof(int));
    }

    printf("Bucket size: %d\n", bucket_size);
    printf("Elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    for (i = 0; i < n; i++) {
        int bucket_index = (arr[i] - min) / step;
        bucket[bucket_index] = realloc(bucket[bucket_index], (bucket_size + 1) * sizeof(int));
        bucket[bucket_index][bucket_size - 1] = arr[i];
    }

    printf("\n");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("Bucket %d: ", i);
        for (int j = 0; j < bucket_size; j++) {
            if (bucket[i][j]!= NULL)
                printf("%d ", bucket[i][j]);
            else
                break;
        }
    }

    free(arr);
    for (i = 0; i < MAX_SIZE; i++) {
        free(bucket[i]);
    }

    return 0;
}