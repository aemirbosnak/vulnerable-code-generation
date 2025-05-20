//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000000
#define BUCKET_SIZE 1000

int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return x - y;
}

void bucket_sort(int arr[], int n) {
    int bucket[MAX_SIZE];
    int i, j, k;
    float range = (float)n / MAX_SIZE;
    float min_val = arr[0];
    float max_val = arr[0];

    for (i = 0; i < n; i++) {
        if (arr[i] < min_val)
            min_val = arr[i];
        if (arr[i] > max_val)
            max_val = arr[i];
    }

    // Calculate the range of each bucket
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = ceil((i * range) + min_val);
    }

    // Insert the elements into the appropriate bucket
    for (i = 0; i < n; i++) {
        j = (int)((float)n / MAX_SIZE * (arr[i] - min_val));
        k = bucket[j];
        while (k <= arr[i]) {
            k += BUCKET_SIZE;
        }
        bucket[j] = k;
    }

    // Sort the buckets
    for (i = 0; i < MAX_SIZE; i++) {
        qsort(arr + (int)bucket[i], BUCKET_SIZE, sizeof(int), compare);
    }

    // Merge the sorted buckets
    int index = 0;
    for (i = 0; i < MAX_SIZE; i++) {
        while (bucket[i] < n) {
            arr[index++] = arr[bucket[i]++];
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucket_sort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}