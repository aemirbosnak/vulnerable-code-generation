//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUCKETS 10
#define MAX_ELEMENTS_PER_BUCKET 100
#define MAX_NUMBER_LENGTH 10

typedef struct {
    int count;
    int elements[MAX_ELEMENTS_PER_BUCKET];
} Bucket;

// Function to initialize Buckets
void initialize_buckets(Bucket *buckets) {
    for (int i = 0; i < MAX_BUCKETS; i++) {
        buckets[i].count = 0;
    }
}

// Hash function to get Bucket Index
int hash(int value) {
    if (value < 0) value = -value; // Ensure non-negative
    return value % MAX_BUCKETS;
}

// Function to sort array using Bucket Sort
void bucket_sort(int *array, int size) {
    Bucket buckets[MAX_BUCKETS];
    initialize_buckets(buckets);

    // Step 1: Distribute input array values into buckets
    for (int i = 0; i < size; i++) {
        int index = hash(array[i]);
        if (buckets[index].count < MAX_ELEMENTS_PER_BUCKET) {
            buckets[index].elements[buckets[index].count++] = array[i];
        } else {
            printf("Warning: Bucket %d is full, cannot add %d!\n", index, array[i]);
        }
    }

    // Step 2: Sort individual buckets and merge
    int index = 0;
    for (int i = 0; i < MAX_BUCKETS; i++) {
        // Sort using simple insertion sort
        for (int j = 1; j < buckets[i].count; j++) {
            int key = buckets[i].elements[j];
            int k = j - 1;

            while (k >= 0 && buckets[i].elements[k] > key) {
                buckets[i].elements[k + 1] = buckets[i].elements[k];
                k--;
            }
            buckets[i].elements[k + 1] = key;
        }
        
        // Copy sorted elements back to the original array
        for (int j = 0; j < buckets[i].count; j++) {
            array[index++] = buckets[i].elements[j];
        }
    }
}

// Function to print the array
void print_array(int *array, int size) {
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to read integers from the user
void read_integers(int *array, int *size) {
    printf("Enter the number of elements (max %d): ", MAX_ELEMENTS_PER_BUCKET * MAX_BUCKETS);
    scanf("%d", size);

    if (*size > MAX_ELEMENTS_PER_BUCKET * MAX_BUCKETS) {
        printf("Exceeded maximum limit. Adjusting to %d elements.\n", MAX_ELEMENTS_PER_BUCKET * MAX_BUCKETS);
        *size = MAX_ELEMENTS_PER_BUCKET * MAX_BUCKETS;
    }

    printf("Enter %d integers: ", *size);
    for (int i = 0; i < *size; i++) {
        scanf("%d", &array[i]);
    }
}

// Main function
int main() {
    int *array = malloc(MAX_ELEMENTS_PER_BUCKET * MAX_BUCKETS * sizeof(int));
    int size = 0;

    if (array == NULL) {
        printf("Memory allocation failed! Unable to allocate memory.\n");
        return 1;
    }

    // Surprise! Let's read integers and sort them
    read_integers(array, &size);
    
    printf("Sorting the array...\n");
    bucket_sort(array, size);
    
    print_array(array, size);
    
    free(array); // Clean-up allocated memory
    return 0;
}