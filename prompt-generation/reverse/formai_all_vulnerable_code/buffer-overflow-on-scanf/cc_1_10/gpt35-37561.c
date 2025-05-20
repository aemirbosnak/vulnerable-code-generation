//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Define maximum number of elements in the array
#define MAX_NUM_ELEMENTS 10

// Bucket sort implementation function
void bucket_sort(int array[], int num_elements) {

    int i, j, temp;
    int buckets[MAX_NUM_ELEMENTS];

    // Initialize all elements of buckets array to 0
    for (i = 0; i < MAX_NUM_ELEMENTS; ++i) {
        buckets[i] = 0;
    }

    // Put elements into their respective buckets
    for (i = 0; i < num_elements; ++i) {
        ++buckets[array[i]];
    }

    // Sort elements in each bucket and place them back into the original array
    for (i = 0, j = 0; j < MAX_NUM_ELEMENTS; ++j) {
        for (temp = buckets[j]; temp > 0; --temp) {
            array[i++] = j;
        }
    }
}

// Main function
int main() {

    int i, num_elements;
    int array[MAX_NUM_ELEMENTS];

    // Prompt user for array input
    printf("Enter number of elements in array (maximum %d): ", MAX_NUM_ELEMENTS);
    scanf("%d", &num_elements);

    printf("Enter %d elements: ", num_elements);
    for (i = 0; i < num_elements; ++i) {
        scanf("%d", &array[i]);
    }

    // Perform bucket sort
    bucket_sort(array, num_elements);

    // Print sorted array
    printf("Sorted array: ");
    for (i = 0; i < num_elements; ++i) {
        printf("%d ", array[i]);
    }

    return 0;
}