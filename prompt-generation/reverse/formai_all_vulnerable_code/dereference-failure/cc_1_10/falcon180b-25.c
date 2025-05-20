//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000
#define MAX_VAL 1000000

// Function to generate random integers
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print an array
void print_array(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform bucket sort
void bucket_sort(int arr[], int size) {
    // Calculate the maximum value in the array
    int max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Calculate the range of the array
    int range = max_val - arr[0] + 1;

    // Create the buckets
    int *buckets = malloc(range * sizeof(int));
    if (buckets == NULL) {
        printf("Error: Could not allocate memory for buckets.\n");
        exit(1);
    }
    for (int i = 0; i < range; i++) {
        buckets[i] = 0;
    }

    // Count the frequency of each value in the array
    for (int i = 0; i < size; i++) {
        int index = arr[i] - arr[0];
        buckets[index]++;
    }

    // Place the values in the correct position in the sorted array
    int pos = 0;
    for (int i = 0; i < range; i++) {
        while (buckets[i] > 0) {
            arr[pos++] = i + arr[0];
            buckets[i]--;
        }
    }

    free(buckets);
}

// Function to generate a random array of integers
int *gen_array(int size) {
    int *arr = malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Error: Could not allocate memory for array.\n");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        arr[i] = rand_int(1, MAX_VAL);
    }
    return arr;
}

// Main function
int main() {
    srand(time(NULL));

    int size = rand() % MAX_SIZE + 1;
    int *arr = gen_array(size);
    print_array(arr, size);

    bucket_sort(arr, size);

    printf("Sorted Array: ");
    print_array(arr, size);

    free(arr);
    return 0;
}