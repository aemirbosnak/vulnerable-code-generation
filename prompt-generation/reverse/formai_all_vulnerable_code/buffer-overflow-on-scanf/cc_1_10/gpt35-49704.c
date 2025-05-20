//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: complex
#include<stdio.h>
#include<stdlib.h>

// Function to sort elements using bucket sort
void bucketSort(float arr[], int n)
{
    // Creating n buckets
    int i, j, k;
    int bucketNum[n];
    for (i = 0; i < n; i++)
    {
        bucketNum[i] = 0;
    }
 
    // Count the number of elements in each bucket
    for (i = 0; i < n; i++)
    {
        bucketNum[(int)(arr[i]*n)]++;
    }
 
    // Sort elements of each bucket
    for (i = 0; i < n; i++)
    {
        float bucket[bucketNum[i]];
        k = 0;
        for (j = 0; j < n; j++)
        {
            if ((int)(arr[j]*n) == i)
            {
                bucket[k++] = arr[j];
            }
        }
 
        // Insertion sort
        for (j = 1; j < bucketNum[i]; j++)
        {
            float temp = bucket[j];
            k = j - 1;
            while (k >= 0 && bucket[k] > temp)
            {
                bucket[k + 1] = bucket[k];
                k--;
            }
            bucket[k + 1] = temp;
        }
 
        // Copy sorted elements of each bucket into the original array
        k = 0;
        for (j = 0; j < n; j++)
        {
            if ((int)(arr[j]*n) == i)
            {
                arr[j] = bucket[k++];
            }
        }
    }
}

// Driver program to test above functions
int main()
{
    float arr[100];
    int n, i;
 
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
 
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%f", &arr[i]);
    }
 
    bucketSort(arr, n);
 
    printf("Sorted elements are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%f ", arr[i]);
    }
    printf("\n");

    return 0;
}