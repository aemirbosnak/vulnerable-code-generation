//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

void BucketSort(int [], int);
void InsertionSort(int [], int);

int main()
{
    int array[] = {83, 45, 23, 90, 34, 29, 70, 19, 100, 87};
    int size = sizeof(array)/sizeof(array[0]);
    BucketSort(array, size);
    printf("Sorted array is: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}

void BucketSort(int array[], int size)
{
    int min = array[0], max = array[0];

    //find minimum and maximum value of array
    for(int i = 1; i < size; i++)
    {
        if(array[i] < min)
            min = array[i];
        else if(array[i] > max)
            max = array[i];
    }

    int bucketSize = (max - min)/10 + 1; //set bucket size

    int **buckets = (int**) malloc(bucketSize * sizeof(int*)); //allocate memory to buckets array
    int *bucketCount = (int*) calloc(bucketSize, sizeof(int)); //allocate memory to bucketCount array

    //put array elements into the respective buckets
    for(int i = 0; i < size; i++)
    {
        int bucketIndex = (array[i] - min)/10;
        int *bucketArray = buckets[bucketIndex];
        if(bucketArray == NULL)
        {
            bucketArray = (int*) malloc(10 * sizeof(int));
            buckets[bucketIndex] = bucketArray;
        }
        bucketArray[bucketCount[bucketIndex]] = array[i];
        bucketCount[bucketIndex]++;
    }

    //sort the individual buckets using Insertion Sort
    for(int i = 0; i < bucketSize; i++)
    {
        if(buckets[i] != NULL)
            InsertionSort(buckets[i], bucketCount[i]);
    }

    //concatenate all the sorted buckets to form the final sorted array
    int index = 0;
    for(int i = 0; i < bucketSize; i++)
    {
        int *bucketArray = buckets[i];
        int bucketCountValue = bucketCount[i];
        for(int j = 0; j < bucketCountValue; j++)
        {
            array[index++] = bucketArray[j];
        }
        free(bucketArray);
    }

    free(bucketCount);
    free(buckets);
}

void InsertionSort(int array[], int size)
{
    int i, j, key;

    for (i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}