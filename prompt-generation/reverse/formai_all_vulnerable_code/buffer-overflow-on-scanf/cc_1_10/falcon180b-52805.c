//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: calm
#include <stdio.h>

// Function to print the solution
void printSolution(int arr[], int n) {
    printf("The solution is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to find the maximum value in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the minimum value in an array
int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to find the maximum difference between two elements in an array
int findMaxDiff(int arr[], int n) {
    int maxDiff = 0;
    int max1 = findMax(arr, n);
    int min1 = findMin(arr, n);
    for (int i = 0; i < n; i++) {
        if (arr[i]!= max1 && arr[i]!= min1) {
            int max2 = findMax(arr, n);
            int min2 = findMin(arr, n);
            int diff = max2 - min2;
            if (diff > maxDiff) {
                maxDiff = diff;
            }
        }
    }
    return maxDiff;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int maxDiff = findMaxDiff(arr, n);
    printf("The maximum difference between two elements is: %d\n", maxDiff);
    printSolution(arr, n);
    return 0;
}