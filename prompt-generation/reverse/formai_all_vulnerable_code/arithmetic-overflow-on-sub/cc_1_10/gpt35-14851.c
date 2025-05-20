//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: dynamic
#include<stdio.h>

void printArray(int n, int arr[])
{
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selectionSort(int n, int arr[])
{
    for(int i=0; i<n-1; i++)
    {
        int minIndex = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        printf("Array after %dth iteration: ", i+1);
        printArray(n, arr);
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original Array: ");
    printArray(n, arr);

    printf("Performing Selection Sort...\n");
    selectionSort(n, arr);

    printf("Array after sorting: ");
    printArray(n, arr);

    return 0;
}