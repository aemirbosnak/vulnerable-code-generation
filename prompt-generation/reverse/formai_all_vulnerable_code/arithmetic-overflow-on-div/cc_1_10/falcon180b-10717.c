//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

//Function to get maximum value in array
int getMax(int arr[], int n)
{
    int max = arr[0];
    for(int i=1; i<n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

//Function to perform bucket sort
void bucketSort(int arr[], int n)
{
    int max = getMax(arr, n);
    int bucketSize = max/n;
    int *buckets[n];
    for(int i=0; i<n; i++)
    {
        buckets[i] = (int *)malloc(bucketSize*sizeof(int));
        for(int j=0; j<bucketSize; j++)
            buckets[i][j] = -1;
    }
    for(int i=0; i<n; i++)
    {
        int j = arr[i]/bucketSize;
        buckets[j][arr[i]%bucketSize] = i;
    }
    int k = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<bucketSize; j++)
        {
            if(buckets[i][j]!= -1)
            {
                arr[k++] = buckets[i][j];
            }
        }
    }
}

//Function to print array
void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

//Main function
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    bucketSort(arr, n);
    printf("Sorted Array:\n");
    printArray(arr, n);
    return 0;
}