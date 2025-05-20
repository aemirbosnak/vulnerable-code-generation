//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int n;

    printf("Enter the number of elements in the array (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int *buckets = (int *)malloc(max * sizeof(int));
    if (buckets == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < max; i++) {
        buckets[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / 10;
        buckets[arr[i] / 10]++;
    }

    int j = 0;
    for (int i = 0; i < max; i++) {
        while (buckets[i] > 0) {
            arr[j] = i * 10 + (buckets[i] - 1) * (10 / max);
            j++;
            buckets[i]--;
        }
    }

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(buckets);
    return 0;
}