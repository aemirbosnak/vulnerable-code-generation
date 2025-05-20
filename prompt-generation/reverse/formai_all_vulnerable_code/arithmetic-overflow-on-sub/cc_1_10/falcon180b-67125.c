//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void bucketSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    int bucketSize = max / n + 1;

    int* bucket[n];
    for (int i = 0; i < n; i++)
    {
        bucket[i] = (int*)malloc(bucketSize * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] >= i * bucketSize && arr[j] < (i + 1) * bucketSize)
            {
                bucket[i] = (int*)realloc(bucket[i], (j + 1) * sizeof(int));
                bucket[i][j] = arr[j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        quickSort(bucket[i], 0, n - 1);
    }

    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (bucket[i][j]!= -1)
            {
                arr[index] = bucket[i][j];
                index++;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    clock_t start = clock();
    bucketSort(arr, n);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken: %lf seconds\n", time_taken);

    return 0;
}