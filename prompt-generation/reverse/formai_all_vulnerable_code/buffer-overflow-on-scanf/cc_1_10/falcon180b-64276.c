//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum value in an array
int max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the minimum value in an array
int min(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to implement the greedy algorithm
int greedy(int arr[], int n, int k) {
    int max_sum = max(arr, n);
    int min_sum = min(arr, n);
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= max_sum - min_sum) {
            sum += arr[i];
            count++;
        }
    }
    if (count == k) {
        return sum;
    } else {
        return -1;
    }
}

int main() {
    int n, k;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number of elements to be selected: ");
    scanf("%d", &k);
    int result = greedy(arr, n, k);
    if (result == -1) {
        printf("It is not possible to select %d elements with the given conditions.\n", k);
    } else {
        printf("The maximum sum that can be obtained by selecting %d elements is %d.\n", k, result);
    }
    return 0;
}