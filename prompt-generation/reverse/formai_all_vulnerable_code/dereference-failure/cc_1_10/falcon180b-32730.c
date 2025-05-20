//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MIN_VALUE 1
#define MAX_VALUE 100

int main() {
    int n, i, j;
    int *arr;
    float *freq;
    int *cum_freq;
    int num_buckets = 10;
    int bucket_size = (MAX_VALUE - MIN_VALUE + 1) / num_buckets;
    int max_index = MAX_VALUE - MIN_VALUE + 1;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    freq = (float *)malloc(max_index * sizeof(float));
    cum_freq = (int *)malloc(max_index * sizeof(int));

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        freq[arr[i] - MIN_VALUE]++;
    }

    cum_freq[0] = freq[0];
    for (i = 1; i < max_index; i++) {
        cum_freq[i] = cum_freq[i-1] + freq[i];
    }

    for (i = n - 1; i >= 0; i--) {
        j = (arr[i] - MIN_VALUE) / bucket_size;
        cum_freq[j]--;
        arr[cum_freq[j]] = arr[i];
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    free(freq);
    free(cum_freq);

    return 0;
}