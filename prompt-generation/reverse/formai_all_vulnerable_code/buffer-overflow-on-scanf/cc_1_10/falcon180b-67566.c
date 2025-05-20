//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void bucketSort(int arr[], int size) {
    int i, j, max_val = arr[0], min_val = arr[0], range, bucket_size;
    int *bucket[MAX_SIZE];

    for (i = 0; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    range = max_val - min_val + 1;
    bucket_size = range / size;

    for (i = 0; i < size; i++) {
        bucket[i] = malloc(bucket_size * sizeof(int));
    }

    for (i = 0; i < size; i++) {
        int index = (arr[i] - min_val) / bucket_size;
        int j = 0;
        while (bucket[index][j]!= 0) {
            j++;
        }
        bucket[index][j] = arr[i];
    }

    int k = 0;
    for (i = 0; i < size; i++) {
        for (j = 0; j < bucket_size; j++) {
            if (bucket[i][j]!= 0) {
                arr[k++] = bucket[i][j];
            }
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    printf("Before sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, size);

    printf("After sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}