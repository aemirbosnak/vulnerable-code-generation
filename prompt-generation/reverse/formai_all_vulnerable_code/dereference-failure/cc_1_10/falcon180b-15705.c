//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucketSort(int arr[], int n) {
    int i, j, max, min, range, count[MAX_SIZE] = {0};
    int* bucket[MAX_SIZE];

    // Find the maximum and minimum values in the array
    max = arr[0];
    min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }

    // Calculate the range of the array
    range = max - min + 1;

    // Create empty buckets
    for (i = 0; i < range; i++)
        bucket[i] = NULL;

    // Place the elements in the appropriate buckets
    for (i = 0; i < n; i++) {
        j = arr[i] - min;
        if (bucket[j] == NULL) {
            bucket[j] = (int*)malloc(sizeof(int));
        }
        count[j]++;
    }

    // Sort the buckets
    for (i = 0; i < range; i++) {
        if (bucket[i]!= NULL) {
            for (j = 0; j < count[i]; j++) {
                printf("%d ", *(bucket[i] + j));
            }
            free(bucket[i]);
        }
    }
}

int main() {
    int i, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bucketSort(arr, n);

    return 0;
}