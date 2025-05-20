//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    int *array;
    int i, j, k, temp;
    clock_t start, end;
    double cpu_time_used;

    // Prompt user for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory for the array
    array = (int *)malloc(n * sizeof(int));

    // Prompt user for the elements of the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Initialize the number of buckets
    int num_buckets = n / 2;

    // Allocate memory for the buckets
    int **buckets = (int **)malloc(num_buckets * sizeof(int *));
    for (i = 0; i < num_buckets; i++) {
        buckets[i] = (int *)malloc(n * sizeof(int));
    }

    // Distribute the elements of the array into the buckets
    for (i = 0; i < n; i++) {
        k = abs(array[i]) % num_buckets;
        buckets[k][i] = array[i];
    }

    // Sort the buckets
    for (i = 0; i < num_buckets; i++) {
        for (j = 0; j < n; j++) {
            temp = buckets[i][j];
            buckets[i][j] = buckets[i][n - j - 1];
            buckets[i][n - j - 1] = temp;
        }
    }

    // Merge the sorted buckets back into the array
    for (i = 0; i < n; i++) {
        k = abs(array[i]) % num_buckets;
        array[i] = buckets[k][i];
    }

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free memory
    for (i = 0; i < num_buckets; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(array);

    return 0;
}