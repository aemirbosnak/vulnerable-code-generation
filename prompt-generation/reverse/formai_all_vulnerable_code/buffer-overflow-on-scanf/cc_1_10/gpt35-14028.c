//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_VALUE 100

void bucketSort(int array[], int n);

int main()
{
    int n;
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);
    int array[n];
    printf("\nEnter the elements of the array below:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("\nUnsorted Array: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    bucketSort(array, n);

    printf("\n\nSorted Array: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}

void bucketSort(int array[], int n)
{
    int bucket[MAX_VALUE];
    for(int i = 0; i < MAX_VALUE; i++)
    {
        bucket[i] = 0;
    }
    for(int i = 0; i < n; i++)
    {
        ++bucket[array[i]];
    }

    for(int i = 0, j = 0; j < MAX_VALUE; j++)
    {
        for(int k = bucket[j]; k > 0; k--)
        {
            array[i++] = j;
        }
    }
}