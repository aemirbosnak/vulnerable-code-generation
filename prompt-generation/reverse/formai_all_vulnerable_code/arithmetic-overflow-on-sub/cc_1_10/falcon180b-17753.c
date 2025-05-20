//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucket_sort(int *arr, int size) {
    int i, j, max = arr[0], min = arr[0];
    int *bucket = malloc(size * sizeof(int));

    for (i = 0; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    int range = max - min + 1;
    int bucket_size = range / size;

    for (i = 0; i < size; i++) {
        bucket[i] = 0;
    }

    for (i = 0; i < size; i++) {
        bucket[(arr[i] - min) / bucket_size]++;
    }

    for (i = 1; i < size; i++) {
        bucket[i] += bucket[i - 1];
    }

    int index = 0;
    for (i = size - 1; i >= 0; i--) {
        for (j = 0; j < bucket[i]; j++) {
            arr[index++] = min + i * bucket_size;
        }
    }

    free(bucket);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int rand_index = rand() % size;
        int temp = arr[i];
        arr[i] = arr[rand_index];
        arr[rand_index] = temp;
    }

    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, size);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}