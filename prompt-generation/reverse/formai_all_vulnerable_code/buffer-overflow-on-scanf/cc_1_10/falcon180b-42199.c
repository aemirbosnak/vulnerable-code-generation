//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bucket_sort(int arr[], int n);
void swap(int *a, int *b);

int main() {
    int arr[MAX], n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, n);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void bucket_sort(int arr[], int n) {
    int i, j, max = arr[0], min = arr[0];
    int *bucket[MAX];

    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int bucket_size = range / n;

    for (i = 0; i < n; i++) {
        bucket[i] = (int *)malloc(bucket_size * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        int index = (arr[i] - min) / bucket_size;
        bucket[index] = realloc(bucket[index], (++bucket[index][0]) * sizeof(int));
        bucket[index][bucket[index][0]] = arr[i];
    }

    int k = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < bucket[i][0]; j++) {
            arr[k++] = bucket[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        free(bucket[i]);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}