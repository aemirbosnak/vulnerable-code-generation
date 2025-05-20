//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // Maximum number of elements in the array
#define BUCKET_SIZE 10 // Size of each bucket

// Function to compare two strings in alphabetical order
int compare_strings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

// Function to perform bucket sort on an array of strings
void bucket_sort(char **arr, int n) {
    int i, j;
    char **buckets[BUCKET_SIZE]; // Create an array of buckets

    // Initialize all buckets to NULL
    for (i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = NULL;
    }

    // Place each element in the appropriate bucket
    for (i = 0; i < n; i++) {
        int bucket_index = (*arr)[i] % BUCKET_SIZE;
        char **bucket = &buckets[bucket_index];
        (*bucket) = realloc(*bucket, (1 + strlen((*bucket)? (*bucket) : "")) * sizeof(char*));
        (*bucket)[(*arr)[i]] = (*arr)[i];
    }

    // Concatenate all the buckets back into the original array
    i = 0;
    for (j = 0; j < BUCKET_SIZE; j++) {
        char **bucket = buckets[j];
        while (bucket!= NULL) {
            (*arr)[i++] = *(bucket++);
        }
    }
}

// Function to print the sorted array
void print_array(char **arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%s ", *(arr + i));
    }
    printf("\n");
}

int main() {
    int n;
    char **arr;

    // Get the number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory for the array
    arr = (char **)malloc(n * sizeof(char *));

    // Get each element from the user
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        char input[MAX_SIZE];
        scanf("%s", input);
        (*(arr + i)) = strdup(input);
    }

    // Perform bucket sort on the array
    bucket_sort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    print_array(arr, n);

    // Free the memory allocated for the array
    for (int i = 0; i < n; i++) {
        free((arr + i));
    }
    free(arr);

    return 0;
}