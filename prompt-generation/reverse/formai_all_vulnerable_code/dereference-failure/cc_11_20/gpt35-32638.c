//FormAI DATASET v1.0 Category: Arithmetic ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *arr;
    arr = (int *)malloc(size * sizeof(int));
    srand(time(NULL));

    //populate the array with random values
    for(int i=0; i<size; i++)
    {
        arr[i] = rand();
    }

    //print the original array
    printf("\nOriginal Array:\n");
    for(int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }

    //find the sum of all elements in the array
    int sum = 0;
    for(int i=0; i<size; i++)
    {
        sum += arr[i];
    }
    printf("\n\nSum of all elements: %d\n", sum);

    //find the average of all elements in the array
    float average = (float)sum / size;
    printf("\nAverage of all elements: %.2f\n", average);

    //find the maximum and minimum elements in the array
    int max = arr[0];
    int min = arr[0];
    for(int i=1; i<size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
        else if(arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("\nMaximum element: %d\n", max);
    printf("\nMinimum element: %d\n", min);

    //sort the array in ascending order using bubble sort
    for(int i=0; i<size-1; i++)
    {
        for(int j=0; j<size-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("\nArray sorted in ascending order:\n");
    for(int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }

    //sort the array in descending order using selection sort
    for(int i=0; i<size-1; i++)
    {
        int maxIndex = i;
        for(int j=i+1; j<size; j++)
        {
            if(arr[j] > arr[maxIndex])
            {
                maxIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
    printf("\n\nArray sorted in descending order:\n");
    for(int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }

    //free the allocated memory
    free(arr);
    return 0;
}