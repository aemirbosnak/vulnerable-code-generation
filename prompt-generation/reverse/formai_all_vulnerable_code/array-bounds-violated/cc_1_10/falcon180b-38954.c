//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main() {
    int myArray[SIZE] = {5, 3, 9, 1, 7, 2, 8, 6, 4, 0};
    int i;
    int max = myArray[0];
    int min = myArray[0];

    // Find the maximum and minimum values in the array
    for (i = 0; i < SIZE; i++) {
        if (myArray[i] > max) {
            max = myArray[i];
        }
        if (myArray[i] < min) {
            min = myArray[i];
        }
    }

    // Calculate the range of the array
    int range = max - min + 1;

    // Initialize the bucket array
    int bucket[range];
    for (i = 0; i < range; i++) {
        bucket[i] = 0;
    }

    // Place the elements in the appropriate buckets
    for (i = 0; i < SIZE; i++) {
        bucket[myArray[i] - min]++;
    }

    // Modify the bucket array to contain the correct position of each element
    for (i = 1; i < range; i++) {
        bucket[i] += bucket[i - 1];
    }

    // Place the elements back in the original array in sorted order
    for (i = SIZE - 1; i >= 0; i--) {
        myArray[bucket[myArray[i] - min] - 1] = myArray[i];
        bucket[myArray[i] - min]--;
    }

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", myArray[i]);
    }

    return 0;
}