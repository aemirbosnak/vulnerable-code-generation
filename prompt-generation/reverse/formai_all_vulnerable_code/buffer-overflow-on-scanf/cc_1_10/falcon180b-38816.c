//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 100000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucketsort(int arr[], int n) {
    int i, j, k, max, min, range, *temp;
    int *bucket[n];

    for (i = 0; i < n; i++) {
        bucket[i] = (int *)malloc(sizeof(int));
        bucket[i][0] = -1;
    }

    for (i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            k = arr[i] * n / MAX;
            if (bucket[k][0] == -1) {
                bucket[k][0] = i;
            } else {
                temp = (int *)realloc(bucket[k], sizeof(int) * ++bucket[k][0]);
                temp[bucket[k][0] - 1] = i;
                bucket[k] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (bucket[i][0]!= -1) {
            temp = (int *)malloc(sizeof(int) * bucket[i][0]);
            for (j = 0; j < bucket[i][0]; j++) {
                temp[j] = arr[bucket[i][j]];
            }
            for (j = 0; j < bucket[i][0]; j++) {
                arr[bucket[i][j]] = temp[j];
            }
            free(temp);
        }
    }
}

int main() {
    int i, n;
    srand(time(NULL));
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
        arr[i] = rand() % MAX;
    }
    printf("Unsorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucketsort(arr, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}