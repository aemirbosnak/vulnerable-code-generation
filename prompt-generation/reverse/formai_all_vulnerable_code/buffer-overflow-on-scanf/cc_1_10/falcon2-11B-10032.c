//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Dennis Ritchie
#include <stdio.h>

// Function to sort an array using bucket sort algorithm
void bucketSort(int arr[], int n) {
    int *buckets = (int *)malloc(sizeof(int) * n);

    // Initialize buckets
    for (int i = 0; i < n; i++) {
        buckets[i] = i;
    }

    // Sort each bucket
    for (int i = 0; i < n; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (buckets[j] < buckets[minIdx]) {
                minIdx = j;
            }
        }

        // Swap elements in bucket
        int temp = buckets[minIdx];
        buckets[minIdx] = buckets[i];
        buckets[i] = temp;
    }

    // Re-assemble the array from buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        arr[buckets[i]] = arr[k++];
    }

    // Free memory allocated for buckets
    free(buckets);
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Press any key to exit...\n");
    getchar();
    return 0;
}