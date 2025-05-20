//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: genious
// Bucketsort Implementation in C

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, temp;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &num);

    int arr[num];
    printf("Enter %d integers:\n", num);

    for(int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array: ");
    for(int i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }

    int min = arr[0];
    int max = arr[0];

    for(int i = 1; i < num; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }

        if(arr[i] < min)
        {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int buckets[range];

    for(int i = 0; i < range; i++)
    {
        buckets[i] = 0;
    }

    for(int i = 0; i < num; i++)
    {
        buckets[arr[i] - min]++;
    }

    for(int i = 1; i < range; i++)
    {
        buckets[i] += buckets[i-1];
    }

    int sorted[num];

    for(int i = num - 1; i >= 0; i--)
    {
        sorted[--buckets[arr[i]-min]] = arr[i];
    }

    printf("\nSorted array: ");
    for(int i = 0; i < num; i++)
    {
        printf("%d ", sorted[i]);
    }

    return 0;
}