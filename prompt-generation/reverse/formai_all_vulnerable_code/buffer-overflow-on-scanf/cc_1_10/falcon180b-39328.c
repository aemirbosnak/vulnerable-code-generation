//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers
int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    if (x < y)
        return -1;
    else if (x > y)
        return 1;
    else
        return 0;
}

// Function to perform bucket sort
void bucket_sort(int arr[], int n) {
    int i, j, k, max_val = arr[0], min_val = arr[0], range;
    int *bucket[n];

    // Find the maximum and minimum values in the array
    for (i = 0; i < n; i++) {
        if (arr[i] > max_val)
            max_val = arr[i];
        if (arr[i] < min_val)
            min_val = arr[i];
    }

    // Calculate the range of the array
    range = max_val - min_val + 1;

    // Create empty buckets
    for (i = 0; i < n; i++) {
        bucket[i] = (int *)malloc(range * sizeof(int));
        for (j = 0; j < range; j++)
            bucket[i][j] = 0;
    }

    // Place elements in appropriate buckets
    for (i = 0; i < n; i++) {
        k = (arr[i] - min_val) / (max_val - min_val + 1) * n;
        bucket[k][(arr[i] - min_val) % (max_val - min_val + 1)]++;
    }

    // Concatenate the buckets back into the array
    i = 0;
    for (k = 0; k < n; k++) {
        for (j = 0; j < range; j++) {
            if (bucket[k][j] > 0) {
                arr[i++] = min_val + j;
                bucket[k][j]--;
            }
        }
    }
}

// Function to print an array
void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucket_sort(arr, n);
    printf("Sorted array:\n");
    print_array(arr, n);
    return 0;
}