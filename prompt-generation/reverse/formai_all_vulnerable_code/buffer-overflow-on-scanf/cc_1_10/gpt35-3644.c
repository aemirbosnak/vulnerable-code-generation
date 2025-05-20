//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Romeo and Juliet
/* A tale of two buckets */

#include <stdio.h>

#define MAX_VAL 100

/* Function declarations */
void bucketSort(int arr[], int n);
void printArr(int arr[], int n);

int main()
{
    int arr[MAX_VAL], n, i;

    /* Get input */
    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements of array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    /* Sort array using Bucket Sort algorithm */
    bucketSort(arr, n);

    /* Print sorted array */
    printf("\nSorted array:\n");
    printArr(arr, n);

    return 0;
}

/* Function to sort array using Bucket Sort algorithm */
void bucketSort(int arr[], int n)
{
    int i, j, k, count[MAX_VAL];

    for (i = 0; i < MAX_VAL; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        (count[arr[i]])++;
    }

    for (i = 0, j = 0; i < MAX_VAL; i++)
    {
        for (k = count[i]; k > 0; k--)
        {
            arr[j++] = i;
        }
    }
}

/* Function to print array */
void printArr(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}