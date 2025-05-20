//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000
#define MAX_VALUE 10000

void bucketSort(int arr[], int n);
void swap(int* a, int* b);

int main() {
    int i, n;
    srand(time(NULL));
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[MAX_SIZE];
    for (i = 0; i < n; i++) {
        arr[i] = rand() % MAX_VALUE;
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void bucketSort(int arr[], int n) {
    int i, j, count[MAX_VALUE] = {0};
    int *bucket[MAX_VALUE] = {0};

    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (i = 0; i < MAX_VALUE; i++) {
        if (count[i] > 0) {
            bucket[i] = (int*) malloc(count[i] * sizeof(int));
        }
    }

    for (i = 0; i < n; i++) {
        j = arr[i];
        bucket[j] = (int*) realloc(bucket[j], (count[j] + 1) * sizeof(int));
        bucket[j][count[j]] = arr[i];
        count[j]++;
    }

    i = 0;
    for (j = 0; j < MAX_VALUE; j++) {
        if (count[j] > 0) {
            for (int k = 0; k < count[j]; k++) {
                arr[i] = bucket[j][k];
                i++;
            }
        }
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}