//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum value of an array
int findMax(int array[], int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Function to find the minimum value of an array
int findMin(int array[], int size) {
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

// Function to find the maximum difference between two arrays
int findMaxDiff(int array1[], int array2[], int size) {
    int maxDiff = 0;
    int min1 = findMin(array1, size);
    int max1 = findMax(array1, size);
    int min2 = findMin(array2, size);
    int max2 = findMax(array2, size);
    for (int i = 0; i < size; i++) {
        int diff = array1[i] - array2[i];
        if (diff > maxDiff) {
            maxDiff = diff;
        }
    }
    return maxDiff;
}

int main() {
    int size;
    printf("Enter the size of the arrays: ");
    scanf("%d", &size);
    int array1[size], array2[size];
    printf("Enter the elements of the first array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array1[i]);
    }
    printf("Enter the elements of the second array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array2[i]);
    }
    int maxDiff = findMaxDiff(array1, array2, size);
    printf("The maximum difference between the arrays is: %d\n", maxDiff);
    return 0;
}