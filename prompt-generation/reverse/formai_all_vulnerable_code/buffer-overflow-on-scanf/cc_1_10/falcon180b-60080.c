//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000
#define MAX_VALUE 10000

void bucketSort(int arr[], int size) {
    int i, j, k, index, max_val = arr[0];
    int *bucket[MAX_VALUE];

    for (i = 0; i < MAX_VALUE; i++) {
        bucket[i] = (int *)malloc(sizeof(int) * size);
    }

    for (i = 0; i < size; i++) {
        index = arr[i] * MAX_VALUE / max_val;
        bucket[index][k++] = arr[i];
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < MAX_VALUE; j++) {
            if (bucket[j][k - 1]!= -1) {
                arr[i] = bucket[j][--k];
            }
        }
    }
}

int main() {
    int i;
    int arr[MAX_SIZE];
    int size;

    srand(time(NULL));

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter %d integers:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, size);

    printf("Sorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}