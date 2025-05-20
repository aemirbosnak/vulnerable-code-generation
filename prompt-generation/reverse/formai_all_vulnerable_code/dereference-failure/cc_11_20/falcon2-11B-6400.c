//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to sort an array using bucket sort
void bucketSort(int *arr, int n) {
    int *buckets = (int *)malloc(n * sizeof(int));
    int *indices = (int *)malloc(n * sizeof(int));
    int *temp = (int *)malloc(n * sizeof(int));
    int i, j, k, m, size;

    // Creating buckets
    for (i = 0; i < n; i++) {
        buckets[i] = 0;
        indices[i] = 0;
    }

    for (i = 0; i < n; i++) {
        if (arr[i] < 0) {
            buckets[0]++;
        } else if (arr[i] == 0) {
            buckets[1]++;
        } else {
            buckets[2]++;
        }
    }

    // Dividing array into buckets
    for (i = 0; i < n; i++) {
        if (buckets[0] > 0) {
            size = buckets[0];
            k = 0;
            for (j = 0; j < n; j++) {
                if (arr[j] < 0) {
                    temp[k++] = arr[j];
                }
            }
            for (j = 0; j < size; j++) {
                indices[k + j] = i;
            }
            for (j = 0; j < n; j++) {
                if (arr[j] < 0) {
                    arr[j] = temp[j];
                }
            }
            buckets[0] = 0;
        }

        if (buckets[1] > 0) {
            size = buckets[1];
            k = 0;
            for (j = 0; j < n; j++) {
                if (arr[j] == 0) {
                    temp[k++] = arr[j];
                }
            }
            for (j = 0; j < size; j++) {
                indices[k + j] = i;
            }
            for (j = 0; j < n; j++) {
                if (arr[j] == 0) {
                    arr[j] = temp[j];
                }
            }
            buckets[1] = 0;
        }

        if (buckets[2] > 0) {
            size = buckets[2];
            k = 0;
            for (j = 0; j < n; j++) {
                if (arr[j] > 0) {
                    temp[k++] = arr[j];
                }
            }
            for (j = 0; j < size; j++) {
                indices[k + j] = i;
            }
            for (j = 0; j < n; j++) {
                if (arr[j] > 0) {
                    arr[j] = temp[j];
                }
            }
            buckets[2] = 0;
        }
    }

    // Rearranging array elements
    for (i = 0; i < n; i++) {
        if (buckets[0] > 0) {
            for (j = 0; j < size; j++) {
                arr[indices[j + k]] = temp[j];
            }
            buckets[0]--;
        }

        if (buckets[1] > 0) {
            for (j = 0; j < size; j++) {
                arr[indices[j + k]] = temp[j];
            }
            buckets[1]--;
        }

        if (buckets[2] > 0) {
            for (j = 0; j < size; j++) {
                arr[indices[j + k]] = temp[j];
            }
            buckets[2]--;
        }
    }

    // Freeing memory
    free(buckets);
    free(indices);
    free(temp);
}

// Function to print an array
void printArray(int *arr, int n) {
    int i;
    printf("Array elements are: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 2, -3, 4, -1, 0, -4, 1, 7, -2};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array elements are: \n");
    printArray(arr, n);

    return 0;
}