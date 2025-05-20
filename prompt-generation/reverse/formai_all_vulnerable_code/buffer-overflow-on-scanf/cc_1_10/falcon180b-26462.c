//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to find the maximum value in an array
int findMax(int arr[], int size) {
    int max = arr[0];
    for(int i=1; i<size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to apply the greedy algorithm to a given array
void greedyAlgorithm(int arr[], int size) {
    int max = findMax(arr, size);
    int sum = 0;

    for(int i=0; i<size; i++) {
        if(arr[i] == max) {
            sum += arr[i];
        }
    }
    printf("The maximum sum that can be obtained is: %d\n", sum);
}

// Main function
int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for(int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("The given array is: ");
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    greedyAlgorithm(arr, size);

    return 0;
}