//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to find the maximum value in an array
int find_max(int arr[], int size) {
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

// Function to find the minimum value in an array
int find_min(int arr[], int size) {
    int min = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

// Function to find the kth largest element in an array
int find_kth_largest(int arr[], int size, int k) {
    int max = find_max(arr, size);

    for (int i = 0; i < size; i++) {
        if (arr[i] == max) {
            k--;
        }
    }

    return arr[k];
}

// Function to find the kth smallest element in an array
int find_kth_smallest(int arr[], int size, int k) {
    int min = find_min(arr, size);

    for (int i = 0; i < size; i++) {
        if (arr[i] == min) {
            k--;
        }
    }

    return arr[k];
}

int main() {
    int n, k;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    int kth_largest = find_kth_largest(arr, n, k);
    int kth_smallest = find_kth_smallest(arr, n, k);

    printf("The %dth largest element in the array is: %d\n", k, kth_largest);
    printf("The %dth smallest element in the array is: %d\n", k, kth_smallest);

    return 0;
}