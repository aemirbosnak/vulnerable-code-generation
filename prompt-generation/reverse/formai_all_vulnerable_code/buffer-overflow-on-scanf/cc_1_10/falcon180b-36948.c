//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to find the maximum value in an array
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to implement the greedy algorithm
void greedyAlgorithm(int arr[], int size) {
    int max = findMax(arr, size);
    int count = 0;
    int i = 0;
    while (count < max) {
        int j = 0;
        while (j < size - 1 && arr[j] < arr[i]) {
            j++;
        }
        if (j == size - 1) {
            i++;
        } else {
            for (int k = j + 1; k < size; k++) {
                if (arr[k] >= arr[i]) {
                    i = k;
                    break;
                }
            }
        }
        count++;
    }
    printf("The maximum subset sum is %d\n", max);
    printf("The elements of the subset are:\n");
    for (int j = 0; j < size; j++) {
        if (arr[j] == max) {
            printf("%d ", arr[j]);
        }
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The original array is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    greedyAlgorithm(arr, size);
    return 0;
}