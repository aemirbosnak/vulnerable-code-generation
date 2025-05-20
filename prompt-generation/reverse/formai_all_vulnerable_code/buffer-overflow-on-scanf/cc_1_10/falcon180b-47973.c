//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to find the maximum value in an array
int max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Function to find the maximum value in an array using Greedy Algorithm
int maxGreedy(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Function to find the maximum value in an array using Dynamic Programming
int maxDP(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main() {
    int arr[MAX], n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("The maximum value in the array using Greedy Algorithm is: %d\n", maxGreedy(arr, n));
    printf("The maximum value in the array using Dynamic Programming is: %d\n", maxDP(arr, n));

    return 0;
}