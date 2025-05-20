//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void bucket_sort(int arr[], int size) {
    int i, j, max = arr[0], min = arr[0];
    int *bucket[MAX_SIZE];

    for (i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    for (i = 0; i <= max - min; i++) {
        bucket[i] = malloc(sizeof(int) * size);
    }

    for (i = 0; i < size; i++) {
        j = (arr[i] - min) * size / (max - min);
        if (j == size) {
            j--;
        }
        bucket[j] = realloc(bucket[j], sizeof(int) * (++bucket[j][0]));
        bucket[j][bucket[j][0]] = arr[i];
    }

    for (i = 0; i < size; i++) {
        arr[i] = bucket[0][i];
    }

    for (i = 0; i <= max - min; i++) {
        free(bucket[i]);
    }
}

int main() {
    int size, i;

    srand(time(NULL));
    size = rand() % MAX_SIZE + 1;

    int arr[MAX_SIZE];
    for (i = 0; i < size; i++) {
        arr[i] = rand() % MAX_SIZE;
    }

    printf("Before Sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, size);

    printf("After Sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}