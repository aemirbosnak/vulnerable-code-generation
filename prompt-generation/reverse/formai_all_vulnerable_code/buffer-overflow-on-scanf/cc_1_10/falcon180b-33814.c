//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_RANGE 1000000

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generate_array(int arr[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        arr[i] = rand_int(1, MAX_RANGE);
    }
}

void bucket_sort(int arr[], int size) {
    int i, j, k;
    int *buckets[MAX_RANGE];

    for (i = 0; i < MAX_RANGE; i++) {
        buckets[i] = (int *)malloc(sizeof(int) * size);
    }

    for (i = 0; i < size; i++) {
        k = arr[i] / (MAX_RANGE / size);
        buckets[k][j] = arr[i];
        j++;
    }

    for (i = 0; i < size; i++) {
        arr[i] = buckets[arr[i] / (MAX_RANGE / size)][i];
    }

    for (i = 0; i < MAX_RANGE; i++) {
        free(buckets[i]);
    }
}

int main() {
    int arr[MAX_SIZE], size;
    int i;

    srand(time(NULL));

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    generate_array(arr, size);

    printf("Before sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, size);

    printf("\nAfter sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}