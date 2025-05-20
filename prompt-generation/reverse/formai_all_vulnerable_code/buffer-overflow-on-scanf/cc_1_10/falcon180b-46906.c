//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MIN_VALUE 1
#define MAX_VALUE 1000

void generateArray(int arr[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }
}

void bucketSort(int arr[], int size)
{
    int *buckets[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
    {
        buckets[i] = (int *)malloc(sizeof(int) * size);
    }

    for (int i = 0; i < size; i++)
    {
        int bucketIndex = arr[i] * MAX_SIZE / (MAX_VALUE - MIN_VALUE + 1);
        buckets[bucketIndex][0] = arr[i];
    }

    for (int i = 0; i < MAX_SIZE; i++)
    {
        int j = 0;
        while (buckets[i][j]!= 0)
        {
            arr[j] = buckets[i][j];
            j++;
        }
    }

    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(buckets[i]);
    }
}

int main()
{
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(sizeof(int) * size);

    generateArray(arr, size);

    printf("Unsorted array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, size);

    printf("\nSorted array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}