//Code Llama-13B DATASET v1.0 Category: Searching algorithm ; Style: scientific
// A unique C searching algorithm example program in a scientific style
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random array of integers
int* generate_random_array(int n) {
    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
    return arr;
}

// Function to print an array
void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to search for an element in an array
int search_array(int* arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    // Set random seed
    srand(time(NULL));

    // Generate a random array of integers
    int n = 10;
    int* arr = generate_random_array(n);

    // Print the array
    printf("Random array: ");
    print_array(arr, n);

    // Search for an element in the array
    int key = 7;
    int index = search_array(arr, n, key);
    if (index != -1) {
        printf("Element %d found at index %d\n", key, index);
    } else {
        printf("Element %d not found in the array\n", key);
    }

    // Free memory
    free(arr);

    return 0;
}