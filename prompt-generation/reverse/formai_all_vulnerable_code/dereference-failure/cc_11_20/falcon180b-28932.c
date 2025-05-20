//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100
#define MAX_VALUE 1000

int main() {
    int n;
    int *arr;
    int *bucket;
    int i, j, k;
    int max_val = 0;
    int min_val = MAX_VALUE;
    int range = 0;
    int *sorted_arr;
    int m = 0;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory for the array
    arr = (int *)malloc(n * sizeof(int));

    // Get the elements of the array from the user
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        // Update the minimum and maximum values
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Calculate the range of the values in the array
    range = max_val - min_val + 1;

    // Allocate memory for the bucket array
    bucket = (int *)malloc(range * sizeof(int));

    // Initialize the bucket array
    for (i = 0; i < range; i++) {
        bucket[i] = 0;
    }

    // Place the elements in the appropriate bucket
    for (i = 0; i < n; i++) {
        j = (arr[i] - min_val) / range;
        k = (arr[i] - min_val) % range;
        bucket[j * range + k]++;
    }

    // Allocate memory for the sorted array
    sorted_arr = (int *)malloc(n * sizeof(int));

    // Place the elements in the sorted array
    for (i = 0; i < n; i++) {
        for (j = 0; j < range; j++) {
            if (bucket[j] > 0 && arr[i] >= min_val + j * range && arr[i] <= min_val + (j + 1) * range) {
                sorted_arr[m++] = arr[i];
                bucket[j]--;
            }
        }
    }

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", sorted_arr[i]);
    }

    return 0;
}