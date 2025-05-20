//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_VALUE 1000000

void bucket_sort(int arr[], int n) {
    int i, j, k, count[MAX_VALUE] = {0};
    int *bucket[MAX_VALUE];

    // Initialize the buckets
    for (i = 0; i < MAX_VALUE; i++) {
        bucket[i] = (int *) malloc(n * sizeof(int));
    }

    // Insert elements into the correct bucket
    for (i = 0; i < n; i++) {
        k = arr[i] * MAX_VALUE / MAX_VALUE;
        count[k]++;
    }
    for (i = 0; i < MAX_VALUE; i++) {
        j = 0;
        for (k = 0; k < n; k++) {
            if ((arr[k] * MAX_VALUE / MAX_VALUE) == i) {
                bucket[i][j] = arr[k];
                j++;
            }
        }
    }

    // Concatenate the buckets
    int index = 0;
    for (i = 0; i < MAX_VALUE; i++) {
        for (j = 0; j < count[i]; j++) {
            arr[index] = bucket[i][j];
            index++;
        }
    }
}

void generate_array(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    generate_array(arr, n);

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, n);

    printf("After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}