//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define MAX_RANGE 1000

int generateRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucketSort(int arr[], int n) {
    int i, j, max = arr[0], min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    int range = max - min + 1;
    int* bucket = (int*) malloc(range * sizeof(int));

    for (i = 0; i < range; i++)
        bucket[i] = 0;

    for (i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }

    for (i = 1; i < range; i++)
        bucket[i] += bucket[i - 1];

    for (i = n - 1; i >= 0; i--) {
        arr[bucket[arr[i] - min] - 1] = arr[i];
        bucket[arr[i] - min]--;
    }

    free(bucket);
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        int index = generateRandom(0, n - 1);
        swap(&arr[i], &arr[index]);
    }

    printf("Before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nAfter sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}