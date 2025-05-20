//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int n, i, j, k, temp;
    int bucket[MAX];
    int arr[MAX];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate the range of the array
    int min = arr[0];
    int max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Calculate the size of each bucket
    int bucketSize = (max - min) / n;

    // Initialize the buckets with zeros
    for (i = 0; i < MAX; i++) {
        bucket[i] = 0;
    }

    // Place the elements in the appropriate buckets
    for (i = 0; i < n; i++) {
        j = arr[i] / bucketSize;
        bucket[j]++;
    }

    // Place the elements in the final sorted array
    k = 0;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < bucket[i]; j++) {
            temp = arr[k];
            arr[k] = i * bucketSize + j * bucketSize;
            k++;
        }
    }

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}