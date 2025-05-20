//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum element in an array
int find_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform bucket sort
void bucket_sort(int arr[], int n) {
    int max = find_max(arr, n);
    int bucket_size = max / n;
    int **buckets = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        buckets[i] = (int *)malloc(bucket_size * sizeof(int));
        for (int j = 0; j < bucket_size; j++) {
            buckets[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / bucket_size;
        buckets[bucket_index][arr[i] % bucket_size]++;
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket_size; j++) {
            while (buckets[i][j] > 0) {
                arr[index++] = i * bucket_size + j;
                buckets[i][j]--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucket_sort(arr, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}