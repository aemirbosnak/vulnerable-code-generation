//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000
#define MAX_RANGE 1000000

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bucket_sort(int arr[], int n) {
    int i, j, index, max = arr[0], min = arr[0], range, temp[n];
    int* buckets[MAX_RANGE];

    for (i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    range = max - min + 1;

    for (i = 0; i < range; i++)
        buckets[i] = NULL;

    for (i = 0; i < n; i++) {
        index = (arr[i] - min) * (MAX_RANGE / range);
        temp[index] = arr[i];
    }

    for (i = 0; i < range; i++) {
        if (buckets[i] == NULL)
            continue;

        for (j = 0; j < MAX_SIZE && buckets[i][j]!= -1; j++) {
            arr[j] = buckets[i][j];
        }

        while (j < MAX_SIZE) {
            buckets[i][j] = -1;
            j++;
        }
    }
}

int main() {
    int i, n, max, min;
    int arr[MAX_SIZE];

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    max = arr[0];
    min = arr[0];
    for (i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    printf("Sorted array using bucket sort:\n");
    bucket_sort(arr, n);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}