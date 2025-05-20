//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucket_sort(int *arr, int n) {
    int i, j, range, *temp;
    range = n / 10;
    int **bucket = (int **)malloc(range * sizeof(int *));
    for (i = 0; i < range; i++) {
        bucket[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        j = arr[i] / range;
        temp = &bucket[j][i % range];
        while (*temp!= 0) {
            temp += 1;
        }
        *temp = arr[i];
    }

    for (i = 0; i < range; i++) {
        temp = bucket[i];
        for (j = 0; j < n; j++) {
            arr[j] = *temp;
            temp += 1;
        }
    }

    for (i = 0; i < range; i++) {
        free(bucket[i]);
    }
    free(bucket);
}

int main() {
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(0));
    for (i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    bucket_sort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}