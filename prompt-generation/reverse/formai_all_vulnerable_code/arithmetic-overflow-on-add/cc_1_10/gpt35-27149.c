//FormAI DATASET v1.0 Category: Data mining ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the array

void printArray(int[], int);
void insertionSort(int[], int);
void dataMining(int[], int);

int main()
{
    int array[MAX_SIZE], size;

    printf("\nEnter the size of the array: ");
    scanf("%d", &size);

    printf("\nEnter the elements of the array: ");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("\nSorting the array using Insertion Sort...\n");
    insertionSort(array, size);

    printf("\nThe sorted array is: ");
    printArray(array, size);

    printf("\nUsing data mining to find the outliers...\n");
    dataMining(array, size);

    return 0;
}

void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void insertionSort(int arr[], int size) 
{
    int i, key, j;

    for(i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void dataMining(int arr[], int size)
{
    int i;

    // Finding the median of the sorted array
    float median;
    if(size % 2 == 0)
    {
        median = (float)(arr[size / 2] + arr[(size / 2) - 1]) / 2;
    }
    else
    {
        median = (float)arr[size / 2];
    }

    // Computing the Interquartile Range (IQR)
    float Q1, Q3, IQR;
    if(size % 2 == 0)
    {
        Q1 = (float)(arr[(size / 2) / 2] + arr[((size / 2) / 2) - 1]) / 2;
        Q3 = (float)(arr[((size / 2) + (size / 2) / 2)] + arr[(((size / 2) + (size / 2) / 2) - 1)]) / 2;
    }
    else
    {
        Q1 = (float)arr[(size / 2) / 2];
        Q3 = (float)arr[(size / 2) + (size / 2) / 2];
    }

    IQR = Q3 - Q1;

    // Finding the lower and upper limits
    float lowerLimit = Q1 - (1.5 * IQR);
    float upperLimit = Q3 + (1.5 * IQR);

    printf("\nThe median is: %.2f", median);
    printf("\nThe lower limit is: %.2f", lowerLimit);
    printf("\nThe upper limit is: %.2f", upperLimit);

    // Finding the outliers
    printf("\nThe outliers are: ");
    for(i = 0; i < size; i++)
    {
        if(arr[i] < lowerLimit || arr[i] > upperLimit)
        {
            printf("%d ", arr[i]);
        }
    }
}