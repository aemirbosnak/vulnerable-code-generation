//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include<stdio.h>
#include<stdlib.h>

// Bucket Sort Function
void bucket_sort(int arr[], int n)
{
    // Max and Min Values
    int max_val = arr[0], min_val = arr[0];
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > max_val)
            max_val = arr[i];
        if(arr[i] < min_val)
            min_val = arr[i];
    }

    // Bucket Size
    int bucket_size = 5;

    // Number of Buckets
    int num_buckets = ((max_val - min_val) / bucket_size) + 1;

    // Create Buckets
    int **buckets = (int **)malloc(sizeof(int *) * num_buckets);
    for(int i = 0; i < num_buckets; i++)
    {
        buckets[i] = (int *)malloc(sizeof(int) * n);
    }

    // Initialize Buckets
    for(int i = 0; i < num_buckets; i++)
    {
        for(int j = 0; j < n; j++)
        {
            buckets[i][j] = -1;
        }
    }

    // Fill Buckets
    for(int i = 0; i < n; i++)
    {
        int bucket_idx = (arr[i] - min_val) / bucket_size;
        for(int j = 0; j < n; j++)
        {
            if(buckets[bucket_idx][j] == -1)
            {
                buckets[bucket_idx][j] = arr[i];
                break;
            }
        }
    }

    // Sort Buckets
    for(int i = 0; i < num_buckets; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(buckets[i][j] == -1)
                break;
            for(int k = j + 1; k < n; k++)
            {
                if(buckets[i][k] == -1)
                    break;
                if(buckets[i][j] > buckets[i][k])
                {
                    int temp = buckets[i][j];
                    buckets[i][j] = buckets[i][k];
                    buckets[i][k] = temp;
                }
            }
        }
    }

    // Concatenate Buckets
    int idx = 0;
    for(int i = 0; i < num_buckets; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(buckets[i][j] == -1)
                break;
            arr[idx] = buckets[i][j];
            idx++;
        }
    }

    // Free Memory
    for(int i = 0; i < num_buckets; i++)
    {
        free(buckets[i]);
    }
    free(buckets);
}

// Driver Code
int main()
{
    int n = 10;
    int arr[] = {45, 67, 21, 35, 78, 11, 99, 85, 24, 56};

    printf("Original Array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Apply Bucket Sort
    bucket_sort(arr, n);

    printf("Sorted Array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}