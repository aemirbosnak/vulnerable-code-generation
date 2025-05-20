//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: paranoid
#include <stdio.h>

#define MAX 50
#define BUCKET_SIZE 5

void bucket_sort(int array[], int n) {
    // Declare buckets and initialize counts
    int i, j, k, buc_count[BUCKET_SIZE], buc[MAX][BUCKET_SIZE];
    for (i = 0; i < BUCKET_SIZE; i++) {
        buc_count[i] = 0;
    }

    // Distribute array elements into buckets
    for (i = 0; i < n; ++i) {
        int buc_index = array[i] / BUCKET_SIZE;
        buc[buc_index][buc_count[buc_index]] = array[i];
        buc_count[buc_index]++;
    }

    // Sort the elements in each bucket using Insertion Sort
    for (i = 0; i < BUCKET_SIZE; ++i) {
        for (j = 0; j < buc_count[i] - 1; ++j) {
            for (k = 0; k < buc_count[i] - j - 1; ++k) {
                if (buc[i][k] > buc[i][k + 1]) {
                    // Swap elements in the same bucket
                    int temp = buc[i][k + 1];
                    buc[i][k + 1] = buc[i][k];
                    buc[i][k] = temp;
                }
            }
        }
    }

    // Merge all the buckets to get the final sorted array
    int index = 0;
    for (i = 0; i < BUCKET_SIZE; ++i) {
        for (j = 0; j < buc_count[i]; ++j) {
            array[index++] = buc[i][j];
        }
    }
}

int main() {
    int array[MAX], n, i;

    // Read input from user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements of the array:\n", n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &array[i]);
    }

    // Sort and print the array
    bucket_sort(array, n);
    printf("Sorted array:\n");
    for (i = 0; i < n; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}