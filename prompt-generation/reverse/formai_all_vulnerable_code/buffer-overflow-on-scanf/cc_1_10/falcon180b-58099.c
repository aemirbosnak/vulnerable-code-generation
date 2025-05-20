//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Function to sort an array using bucket sort
void bucket_sort(int arr[], int n) {
    int max_val = arr[0]; // Initialize max_val to first element
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Create empty buckets
    int* buckets = (int*) malloc(max_val * sizeof(int));
    if (buckets == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < max_val; i++) {
        buckets[i] = 0;
    }

    // Place elements in buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / 10; // Divide by 10 to get bucket index
        buckets[arr[i]]++;
    }

    // Sort elements and fill original array
    int j = 0;
    for (int i = 0; i < max_val; i++) {
        while (buckets[i] > 0) {
            arr[j++] = i * 10;
            buckets[i]--;
        }
    }

    // Free memory
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

    // Sort array using bucket sort
    bucket_sort(arr, n);

    // Print sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}