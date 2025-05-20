//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_VALUE 10000

void bucket_sort(int arr[], int n) {
    int i, j;
    int *bucket[MAX_SIZE];
    int max_val = 0;

    for (i = 0; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int *)malloc(MAX_VALUE * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        j = arr[i] * MAX_VALUE / max_val;
        bucket[j] = (int *)realloc(bucket[j], (j + 1) * sizeof(int));
        bucket[j][j] = arr[i];
    }

    for (i = 0; i < n; i++) {
        j = arr[i] * MAX_VALUE / max_val;
        arr[i] = bucket[j][j];
    }

    for (i = 0; i < MAX_SIZE; i++) {
        free(bucket[i]);
    }
}

void generate_random_array(int arr[], int n) {
    int i;

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
}

int main() {
    int arr[MAX_SIZE];
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    generate_random_array(arr, n);

    bucket_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}