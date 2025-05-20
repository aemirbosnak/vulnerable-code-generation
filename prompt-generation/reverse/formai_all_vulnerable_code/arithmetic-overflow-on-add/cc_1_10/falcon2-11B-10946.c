//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to compare two strings
int compare_str(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// function to perform bucket sort
void bucketSort(char *arr, int n) {
    int *buckets = malloc(n * sizeof(int));
    int *counts = malloc(n * sizeof(int));
    int *merged_arr = malloc(n * sizeof(char));

    // Counting the number of occurrences of each character
    for (int i = 0; i < n; i++) {
        buckets[arr[i] - 'a']++;
    }

    // Initializing buckets with the number of occurrences of each character
    for (int i = 0; i < n; i++) {
        buckets[arr[i] - 'a'] += counts[i];
    }

    // Initializing merged array with 'a'
    for (int i = 0; i < n; i++) {
        merged_arr[i] = 'a';
    }

    // Merging the buckets into the merged array
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            merged_arr[counts[j]] = (char)i + 'a';
            counts[j]++;
        }
    }

    // Copying the sorted array to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = merged_arr[i];
    }

    // Freeing the memory
    free(buckets);
    free(counts);
    free(merged_arr);
}

int main() {
    char arr[] = {'a', 'b', 'a', 'c', 'b', 'a', 'd', 'e', 'f'};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%c", arr[i]);
    }

    return 0;
}