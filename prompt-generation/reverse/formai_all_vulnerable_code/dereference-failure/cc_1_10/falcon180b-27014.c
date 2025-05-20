//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void bucketSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    int range = max - min + 1;
    int *buckets = (int *) malloc(range * sizeof(int));
    for (int i = 0; i < range; i++) {
        buckets[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        buckets[arr[i] - min]++;
    }
    int j = 0;
    for (int i = 0; i < range; i++) {
        while (buckets[i] > 0) {
            arr[j++] = i + min;
            buckets[i]--;
        }
    }
    free(buckets);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[MAX_SIZE];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucketSort(arr, n);
    printf("Sorted elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}