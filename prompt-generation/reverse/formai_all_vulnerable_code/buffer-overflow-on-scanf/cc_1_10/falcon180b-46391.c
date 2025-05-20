//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int n) {
    int i, j;
    int *bucket[MAX];

    for (i = 0; i < MAX; i++) {
        bucket[i] = (int *)malloc(sizeof(int));
    }

    for (i = 0; i < n; i++) {
        int index = arr[i] * MAX / (MAX - 1);
        bucket[index] = (int *)realloc(bucket[index], sizeof(int) * (++bucket[index][0]));
        bucket[index][bucket[index][0] - 1] = arr[i];
    }

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < bucket[i][0]; j++) {
            arr[j] = bucket[i][j];
        }
    }

    for (i = 0; i < MAX; i++) {
        free(bucket[i]);
    }
}

int main() {
    int i, n;
    int arr[MAX];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        int j = rand() % n;
        swap(&arr[i], &arr[j]);
    }

    sort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}