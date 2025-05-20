//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Bucket structure
struct bucket {
    int count;
    int* values;
};

// Function to perform bucket sort
void bucketSort(int* array, int size) {
    int i, j;

    // Find minimum and maximum values in the array
    int minVal = array[0];
    int maxVal = array[0];
    for (i = 1; i < size; i++) {
        if (array[i] < minVal) {
            minVal = array[i];
        } else if (array[i] > maxVal) {
            maxVal = array[i];
        }
    }

    // Calculate the range of each bucket
    int range = (maxVal - minVal) / size + 1;

    // Create the buckets
    int bucketCount = (maxVal - minVal) / range + 1;
    struct bucket buckets[bucketCount];
    for (i = 0; i < bucketCount; i++) {
        buckets[i].count = 0;
        buckets[i].values = (int*)malloc(sizeof(int) * size);
    }

    // Place array elements into the buckets
    for (i = 0; i < size; i++) {
        int bucketIndex = (array[i] - minVal) / range;
        buckets[bucketIndex].values[buckets[bucketIndex].count++] = array[i];
    }

    // Sort each bucket using insertion sort
    for (i = 0; i < bucketCount; i++) {
        for (j = 1; j < buckets[i].count; j++) {
            int temp = buckets[i].values[j];
            int k = j;
            while (k > 0 && temp < buckets[i].values[k - 1]) {
                buckets[i].values[k] = buckets[i].values[k - 1];
                k--;
            }
            buckets[i].values[k] = temp;
        }
    }

    // Concatenate the buckets in sorted order
    int index = 0;
    for (i = 0; i < bucketCount; i++) {
        for (j = 0; j < buckets[i].count; j++) {
            array[index++] = buckets[i].values[j];
        }
    }

    // Free memory
    for (i = 0; i < bucketCount; i++) {
        free(buckets[i].values);
    }
}

// Main function
int main() {
    int size, i;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int array[size];
    printf("Enter array elements:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    bucketSort(array, size);
    printf("Sorted array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}