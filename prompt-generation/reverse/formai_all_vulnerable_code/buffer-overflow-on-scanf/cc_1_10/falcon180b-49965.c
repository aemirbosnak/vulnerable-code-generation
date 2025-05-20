//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define MAX_VALUE 10000

void bucketSort(int arr[], int n);

int main()
{
    int arr[MAX_SIZE];
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void bucketSort(int arr[], int n)
{
    int maxVal = arr[0];
    for(int i=1; i<n; i++)
    {
        if(arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }

    int bucketSize = maxVal / n;
    int **buckets = (int **)malloc(n * sizeof(int *));
    for(int i=0; i<n; i++)
    {
        buckets[i] = (int *)malloc(bucketSize * sizeof(int));
        for(int j=0; j<bucketSize; j++)
        {
            buckets[i][j] = -1;
        }
    }

    for(int i=0; i<n; i++)
    {
        int bucketIndex = arr[i] / bucketSize;
        buckets[bucketIndex][arr[i] % bucketSize] = i;
    }

    int index = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<bucketSize; j++)
        {
            if(buckets[i][j]!= -1)
            {
                arr[index++] = buckets[i][j];
            }
        }
    }
}