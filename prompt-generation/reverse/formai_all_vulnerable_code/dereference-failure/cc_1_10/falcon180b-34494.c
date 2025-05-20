//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to compare two strings
int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

// Function to swap two strings
void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bucket sort
void bucketSort(char **arr, int n) {
    int i, j;
    char **bucket[MAX_SIZE];

    // Create n empty buckets
    for (i = 0; i < n; i++) {
        bucket[i] = malloc(MAX_SIZE * sizeof(char *));
    }

    // Put each element in its respective bucket
    for (i = 0; i < n; i++) {
        int index = strlen(arr[i]) % MAX_SIZE;
        bucket[index] = realloc(bucket[index], (strlen(arr[i]) + 1) * sizeof(char *));
        bucket[index][strlen(bucket[index])] = strdup(arr[i]);
    }

    // Sort each bucket individually
    for (i = 0; i < n; i++) {
        qsort(bucket[i], MAX_SIZE, sizeof(char *), compare);
    }

    // Concatenate the sorted buckets
    char **result = malloc((n + 1) * sizeof(char *));
    int k = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (bucket[i][j]!= NULL) {
                result[k++] = bucket[i][j];
            }
        }
    }
    result[k] = NULL;

    // Free the memory allocated for the buckets
    for (i = 0; i < n; i++) {
        free(bucket[i]);
    }

    // Copy the result back to the original array
    for (i = 0; i < n; i++) {
        free(arr[i]);
        arr[i] = strdup(result[i]);
    }

    // Free the memory allocated for the result
    free(result);
}

int main() {
    char **arr = malloc(10 * sizeof(char *));
    arr[0] = strdup("apple");
    arr[1] = strdup("banana");
    arr[2] = strdup("cherry");
    arr[3] = strdup("date");
    arr[4] = strdup("elderberry");
    arr[5] = strdup("fig");
    arr[6] = strdup("grape");
    arr[7] = strdup("honeydew");
    arr[8] = strdup("kiwi");
    arr[9] = strdup("lemon");

    int n = 10;

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}