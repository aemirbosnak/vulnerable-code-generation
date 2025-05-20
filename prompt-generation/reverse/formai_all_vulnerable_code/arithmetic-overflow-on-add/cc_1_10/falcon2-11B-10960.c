//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: random
#include<stdio.h>
#include<stdlib.h>

void bucketSort(int arr[], int n)
{
    int *temp, i, j, *ptr, max_idx, bucket[100];
    for(i = 0; i < n; i++)
        bucket[arr[i] % 100]++;

    for(i = 0; i < 100; i++)
    {
        temp = (int *)malloc(sizeof(int) * 100);
        if(temp == NULL)
        {
            printf("Memory error");
            return;
        }

        max_idx = 0;
        for(j = 1; j < 100; j++)
        {
            if(bucket[j] > bucket[max_idx])
                max_idx = j;
        }

        for(j = 0; j < 100; j++)
        {
            ptr = &temp[bucket[j]];
            for(i = 0; i < bucket[j]; i++)
            {
                *ptr = arr[max_idx];
                max_idx++;
                ptr++;
            }
        }

        for(i = 0; i < 100; i++)
            bucket[i] = 0;

        for(j = 0; j < 100; j++)
        {
            if(temp[j]!= NULL)
            {
                free(temp[j]);
                temp[j] = NULL;
            }
        }

        for(j = 0; j < 100; j++)
        {
            arr[j] = temp[j];
        }

        free(temp);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Original array is: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array is: ");
    printArray(arr, n);

    return 0;
}