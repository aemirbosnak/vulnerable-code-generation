//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

void bucket_sort(int arr[], int size, int bucket_size) {
    int i, j, k, temp;
    int *bucket[MAX_SIZE];
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int *)malloc(size * sizeof(int));
    }
    for (i = 0; i < size; i++) {
        k = arr[i] / bucket_size;
        if (bucket[k] == NULL) {
            bucket[k] = (int *)malloc(bucket_size * sizeof(int));
        }
        bucket[k][k * bucket_size / 2] = arr[i];
    }
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < bucket_size; j++) {
            if (bucket[i][j]!= 0) {
                temp = bucket[i][j];
                arr[k++] = temp;
                bucket[i][j] = 0;
            }
        }
    }
}

int main() {
    int i, size, bucket_size;
    int arr[MAX_SIZE];
    srand(time(NULL));
    size = rand() % MAX_SIZE + 1;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the size of the bucket: ");
    scanf("%d", &bucket_size);
    bucket_sort(arr, size, bucket_size);
    printf("Sorted array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}