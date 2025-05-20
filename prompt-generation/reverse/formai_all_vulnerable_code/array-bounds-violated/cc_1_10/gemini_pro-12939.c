//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// An array of suspects to be sorted
int suspects[] = {
    7, 4, 2, 9, 5, 8, 1, 3, 6
};

// Function to sort the suspects using bucket sort
void bucketSort(int suspects[], int size) {
    // Create an array of buckets
    int i, j;
    int buckets[size]; // Assuming size is the maximum value in the array

    // Initialize all buckets to empty
    for (i = 0; i < size; i++) {
        buckets[i] = 0;
    }

    // Distribute the suspects into their respective buckets
    for (i = 0; i < size; i++) {
        buckets[suspects[i]]++;
    }

    // Place the suspects back into the original array in sorted order
    int index = 0;
    for (i = 0; i < size; i++) {
        for (j = 0; j < buckets[i]; j++) {
            suspects[index] = i;
            index++;
        }
    }
}

// Function to print the sorted suspects
void printSuspects(int suspects[], int size) {
    // Examine the sorted list of suspects
    int i;
    printf("The sorted list of suspects is: ");
    for (i = 0; i < size; i++) {
        printf("%d ", suspects[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Call the bucket sort function
    int size = sizeof(suspects) / sizeof(suspects[0]);
    bucketSort(suspects, size);

    // Print the sorted suspects
    printSuspects(suspects, size);

    return 0;
}