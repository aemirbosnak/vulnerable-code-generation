//FormAI DATASET v1.0 Category: Sorting ; Style: single-threaded
#include <stdio.h>

void merge(int array[], int const left, int const middle, int const right)
{
    int const size1 = middle - left + 1;
    int const size2 = right - middle;

    int leftArray[size1];
    int rightArray[size2];

    for(int i = 0; i < size1; i++)
        leftArray[i] = array[left + i];
    for(int j = 0; j < size2; j++)
        rightArray[j] = array[middle + 1 + j];

    int indexLeft = 0, indexRight = 0, index = left;

    while(indexLeft < size1 && indexRight < size2)
    {
        if(leftArray[indexLeft] <= rightArray[indexRight])
            array[index++] = leftArray[indexLeft++];
        else
            array[index++] = rightArray[indexRight++];
    }

    while(indexLeft < size1)
        array[index++] = leftArray[indexLeft++];

    while(indexRight < size2)
        array[index++] = rightArray[indexRight++];
}

void mergeSort(int array[], int const left, int const right)
{
    if(left >= right)
        return;

    int middle = (left + right - 1) / 2;

    mergeSort(array, left, middle);
    mergeSort(array, middle + 1, right);
    merge(array, left, middle, right);
}

int main()
{
    int length;
    printf("Enter the length of the array: ");
    scanf("%d", &length);

    int array[length];
    printf("Enter the elements of the array: ");

    for(int i = 0; i < length; i++)
        scanf("%d", &array[i]);

    printf("\nUnsorted array:\n");

    for(int i = 0; i < length; i++)
        printf("%d ", array[i]);

    mergeSort(array, 0, length - 1);

    printf("\n\nSorted array:\n");

    for(int i = 0; i < length; i++)
        printf("%d ", array[i]);

    return 0;
}