//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

int main() {
    int n;
    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);

    int *arr = (int*) malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("Failed to allocate memory. Exiting Program...");
        exit(1);
    }

    printf("Enter the elements to be sorted: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find maximum element to determine number of digits
    int max = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    // Determine number of digits in the maximum element
    int digits = 0;
    while(max > 0) {
        max /= 10;
        digits++;
    }

    // Create 10 buckets and initialize them with 0
    int **buckets = (int**) malloc(BUCKET_SIZE * sizeof(int*));
    for(int i=0; i<BUCKET_SIZE; i++) {
        buckets[i] = (int*) malloc(n * sizeof(int));
        for(int j=0; j<n; j++) {
            buckets[i][j] = 0;
        }
    }

    // Iterate through the digits from the least significant to the most significant
    int divisor = 1;
    for(int i=0; i<digits; i++) {
        // Copy elements to the respective buckets
        for(int j=0; j<n; j++) {
            int digit = (arr[j] / divisor) % 10;
            buckets[digit][j] = arr[j];
        }
        
        // Copy the elements back to the original array in order
        int k = 0;
        for(int j=0; j<BUCKET_SIZE; j++) {
            for(int l=0; l<n; l++) {
                if(buckets[j][l] != 0) {
                    arr[k++] = buckets[j][l];
                    buckets[j][l] = 0;
                }
            }
        }

        // Increment the divisor for the next iteration
        divisor *= 10;
    }

    // Print the sorted array
    printf("Sorted Array: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    // Free allocated memory
    free(arr);
    for(int i=0; i<BUCKET_SIZE; i++) {
        free(buckets[i]);
    }
    free(buckets);
    
    return 0;
}