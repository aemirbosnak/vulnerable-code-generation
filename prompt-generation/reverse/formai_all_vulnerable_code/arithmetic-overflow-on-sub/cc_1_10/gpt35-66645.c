//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int array[], int n)
{
    // Determine the maximum element in the array
    int max_value = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max_value) {
            max_value = array[i];
        }
    }
    
    // Create the buckets
    int* buckets = (int*) calloc(max_value + 1, sizeof(int));
    
    // Add the elements of array into the corresponding bucket
    for (int i = 0; i < n; i++) {
        buckets[array[i]]++;
    }
    
    // Sort the elements of each bucket
    for (int i = 0, j = 0; i <= max_value; i++) {
        while (buckets[i]-- > 0) {
            array[j++] = i;
        }
    }
    
    // Free the buckets
    free(buckets);
}

int main()
{
    int n;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int array[n];
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    
    bucket_sort(array, n);
    
    printf("The sorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}