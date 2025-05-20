//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers
int compare(const void* a, const void* b) {
    if(*(int*)a > *(int*)b)
        return 1;
    else if(*(int*)a < *(int*)b)
        return -1;
    else
        return 0;
}

// Function to perform bucket sort
void bucket_sort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];

    // Find the maximum and minimum values in the array
    for(int i=1; i<n; i++) {
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min)
            min = arr[i];
    }

    // Calculate the range of the array
    int range = max - min + 1;

    // Create an array of empty buckets
    int* buckets[range];

    // Place each element in its corresponding bucket
    for(int i=0; i<n; i++) {
        int index = (arr[i] - min) / range;
        if(buckets[index] == NULL)
            buckets[index] = malloc(sizeof(int));
        int* bucket = buckets[index];
        int j = 0;
        while(j < *(int*)bucket && *(int*)(bucket+j) < arr[i])
            j++;
        *(int*)(bucket+j) = arr[i];
    }

    // Concatenate the sorted buckets back into the original array
    int j = 0;
    for(int i=0; i<range; i++) {
        if(buckets[i]!= NULL) {
            int* bucket = buckets[i];
            while(j < *(int*)bucket) {
                arr[j] = *(int*)(bucket+j);
                j++;
            }
            free(bucket);
        }
    }
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform bucket sort
    bucket_sort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}