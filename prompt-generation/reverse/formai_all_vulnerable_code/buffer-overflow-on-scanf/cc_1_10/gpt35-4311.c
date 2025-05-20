//FormAI DATASET v1.0 Category: Data mining ; Style: unmistakable
#include <stdio.h>

/* Function to calculate sum of elements of an array */
int calculateSum(int arr[], int size) {
    int sum = 0;
    for(int i=0; i<size; i++) {
        sum += arr[i];
    }
    return sum;
}

/* Function to calculate average of elements of an array */
float calculateAvg(int arr[], int size) {
    int sum = calculateSum(arr, size);
    return (float)sum/size;
}

/* Function to calculate variance of elements of an array */
float calculateVariance(int arr[], int size) {
    float avg = calculateAvg(arr, size);
    float variance = 0;
    for(int i=0; i<size; i++) {
        variance += (arr[i] - avg)*(arr[i] - avg);
    }
    variance /= size;
    return variance;
}

/* Function to calculate standard deviation of elements of an array */
float calculateSD(int arr[], int size) {
    float variance = calculateVariance(arr, size);
    float sd = sqrt(variance);
    return sd;
}

int main() {
    int n; // size of array
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n]; // array to hold the data
    printf("Enter the elements of array: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate Statistics
    int sum = calculateSum(arr, n);
    float avg = calculateAvg(arr, n);
    float variance = calculateVariance(arr, n);
    float sd = calculateSD(arr, n);

    // Print Results
    printf("\n--------------Results--------------\n");
    printf("Sum of elements: %d\n", sum);
    printf("Average of elements: %f\n", avg);
    printf("Variance of elements: %f\n", variance);
    printf("Standard Deviation of elements: %f\n", sd);

    return 0;
}