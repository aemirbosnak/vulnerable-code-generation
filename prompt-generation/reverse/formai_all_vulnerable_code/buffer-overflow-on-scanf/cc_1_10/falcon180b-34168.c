//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

void bucket_sort(int arr[], int size) {
    int i, j, k;
    int *bucket[MAX_SIZE];
    int max_val = arr[0];
    int min_val = arr[0];

    for (i = 0; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    int range = max_val - min_val + 1;
    int bucket_size = range / size;

    for (i = 0; i < size; i++) {
        bucket[i] = malloc(bucket_size * sizeof(int));
    }

    for (i = 0; i < size; i++) {
        j = arr[i] - min_val;
        k = 0;
        while (bucket[j][k]!= 0) {
            k++;
        }
        bucket[j][k] = arr[i];
    }

    for (i = 0; i < size; i++) {
        k = 0;
        while (bucket[i][k]!= 0) {
            arr[k] = bucket[i][k];
            k++;
        }
    }

    for (i = 0; i < size; i++) {
        free(bucket[i]);
    }
}

int main() {
    int size;
    int arr[MAX_SIZE];

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000;
    }

    bucket_sort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}