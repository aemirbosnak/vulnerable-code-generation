//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void bucket_sort(int arr[], int n) {
    int i, j, k, max, min, temp;
    int bucket[SIZE] = {0};

    // Find minimum and maximum elements in array
    max = arr[0];
    min = arr[0];
    for (i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }

    // Calculate range and bucket size
    int range = max - min + 1;
    int bucket_size = range / SIZE;

    // Place elements in appropriate buckets
    for (i = 0; i < n; i++) {
        k = arr[i] - min;
        bucket[k / bucket_size]++;
    }

    // Sort the array using the bucket values
    for (i = 0; i < n; i++) {
        k = arr[i] - min;
        bucket[k / bucket_size]--;
        temp = arr[i];
        for (j = 0; j <= k / bucket_size; j++) {
            if (bucket[j] == 0) {
                arr[i] = arr[i + j * bucket_size];
                i--;
            } else {
                bucket[j]--;
            }
        }
    }
}

int main() {
    int arr[SIZE] = {0};
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

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