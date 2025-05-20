//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000
#define MAX_VALUE 10000

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void sort(int arr[], int n) {
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
    int *bucket = (int *) malloc(range * sizeof(int));
    for (int i = 0; i < range; i++) {
        bucket[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }
    int j = 0;
    for (int i = 0; i < range; i++) {
        for (int k = 0; k < bucket[i]; k++) {
            arr[j++] = i + min;
        }
    }
    free(bucket);
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
    time_t start, end;
    time(&start);
    sort(arr, n);
    time(&end);
    printf("Time taken: %ld seconds\n", end - start);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}