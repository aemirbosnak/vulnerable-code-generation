//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

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

// Function to find the median of an array
int findMedian(int arr[], int n) {
    int median;
    int mid = n / 2;
    if (n % 2 == 0) {
        median = (arr[mid - 1] + arr[mid]) / 2;
    } else {
        median = arr[mid];
    }
    return median;
}

// Function to find the mode of an array
int findMode(int arr[], int n) {
    int mode = arr[0];
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == mode) {
            count++;
        } else {
            count--;
        }
        if (count == 0) {
            mode = arr[i];
            count = 1;
        }
    }
    return mode;
}

// Function to find the range of an array
int findRange(int arr[], int n) {
    int max = findMax(arr, n);
    int min = findMin(arr, n);
    return max - min;
}

// Function to find the mean of an array
double findMean(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double) sum / n;
}

// Function to find the standard deviation of an array
double findStdDev(int arr[], int n) {
    double mean = findMean(arr, n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (arr[i] - mean) * (arr[i] - mean);
    }
    return sqrt(sum / n);
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Maximum value in the array: %d\n", findMax(arr, n));
    printf("Minimum value in the array: %d\n", findMin(arr, n));
    printf("Median value in the array: %d\n", findMedian(arr, n));
    printf("Mode value in the array: %d\n", findMode(arr, n));
    printf("Range of the array: %d\n", findRange(arr, n));
    printf("Mean of the array: %lf\n", findMean(arr, n));
    printf("Standard deviation of the array: %lf\n", findStdDev(arr, n));

    return 0;
}