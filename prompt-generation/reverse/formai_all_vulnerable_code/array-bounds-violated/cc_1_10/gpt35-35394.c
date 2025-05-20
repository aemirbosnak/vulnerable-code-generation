//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: complete
#include <stdio.h>

// Function to implement bucket sort
void bucketSort(int arr[], int n, int maxVal) {
    // Create buckets based on the maximum value
    int buckets[maxVal + 1];
    for (int i = 0; i < maxVal + 1; i++) {
        buckets[i] = 0;
    }
    
    // Fill the buckets with elements from the array
    for (int i = 0; i < n; i++) {
        buckets[arr[i]]++;
    }
    
    // Traverse the buckets and insert the elements back to the original array in sorted order
    int index = 0;
    for (int i = 0; i < maxVal + 1; i++) {
        int count = buckets[i];
        while (count--) {
            arr[index++] = i;
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Find the maximum value in the array
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    
    // Call the bucket sort function
    bucketSort(arr, n, maxVal);
    
    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}