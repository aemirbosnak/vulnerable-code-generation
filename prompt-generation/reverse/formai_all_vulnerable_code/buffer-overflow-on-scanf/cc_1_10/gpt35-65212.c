//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n)
{
    // Create n empty buckets
    int i, j;
    int min_val = arr[0];
    int max_val = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] < min_val)
            min_val = arr[i];
        else if (arr[i] > max_val)
            max_val = arr[i];
    }
    int bucket_range = (max_val - min_val) / n + 1;
    int* buckets[n];
    for (i = 0; i < n; i++)
        buckets[i] = (int*)malloc(bucket_range*sizeof(int));
 
    // Distribute given array values to buckets
    for (i = 0; i < n; i++) {
        int bucket_index = (arr[i] - min_val) / bucket_range;
        buckets[bucket_index][(arr[i] - min_val) % bucket_range] = arr[i];
    }
 
    // Sort each bucket and put sorted values to original array
    int index = 0;
    for (i = 0; i < n; i++) {
        int bucket_size = (max_val - min_val + 1) / bucket_range;
        for (j = 0; j < bucket_size; j++) {
            int* bucket = buckets[i];
            for (int k = 0; k < bucket_range; k++) {
                if (bucket[k] != 0) {
                    arr[index++] = bucket[k];
                    bucket[k] = 0;
                }
            }
        }
    }
    //Deallocating the buckets
    for (i = 0; i < n; i++)
        free(buckets[i]);
}
 
int main()
{
    printf("Enter the number of elements in the array: ");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: \n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Original array: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    bucketSort(arr, n);
    printf("Sorted array: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}