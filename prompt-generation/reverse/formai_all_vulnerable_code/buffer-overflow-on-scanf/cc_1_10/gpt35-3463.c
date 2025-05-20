//FormAI DATASET v1.0 Category: Browser Plugin ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the mean
float calculateMean(float arr[], int n) {
    float sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }
    return (sum/n);
}

// Function to calculate the median
float calculateMedian(float arr[], int n) {
    // Sort the array
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] > arr[j]) {
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    if(n%2 == 0) {
        return ((arr[(n/2)-1] + arr[n/2])/2);
    } else {
        return (arr[n/2]);
    }
}

// Function to calculate the mode
float calculateMode(float arr[], int n) {
    // Sort the array
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] > arr[j]) {
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int maxCount = 0;
    float mode = 0;
    for(int i=0; i<n; i++) {
        int count = 1;
        for(int j=i+1; j<n; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }
        if(count > maxCount) {
            maxCount = count;
            mode = arr[i];
        }
    }
    return mode;
}

int main() {
    int choice, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    // Allocate memory dynamically for the array
    float *arr = (float*) malloc(n * sizeof(float));
    printf("Enter the elements of the array:\n");
    for(int i=0; i<n; i++) {
        scanf("%f", &arr[i]);
    }
    printf("\nWhat do you want to calculate?\n1. Mean \n2. Median \n3. Mode\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("\nMean = %f", calculateMean(arr, n));
            break;
        case 2:
            printf("\nMedian = %f", calculateMedian(arr, n));
            break;
        case 3:
            printf("\nMode = %f", calculateMode(arr, n));
            break;
        default:
            printf("\nInvalid choice!");
    }
    // Free the dynamically allocated memory
    free(arr);
    return 0;
}