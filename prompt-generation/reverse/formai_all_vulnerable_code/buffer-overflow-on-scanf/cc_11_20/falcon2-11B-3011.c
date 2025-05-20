//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main(int argc, char *argv[])
{
    int arr[MAX_SIZE];
    int size;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    printf("Enter the elements of array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int min_val, max_val, diff;
    min_val = max_val = arr[0];
    diff = max_val - min_val;

    int buckets[MAX_SIZE + 1];

    for (int i = 0; i < MAX_SIZE + 1; i++)
    {
        buckets[i] = 0;
    }

    for (int i = 1; i < size; i++)
    {
        if (arr[i] >= max_val)
        {
            buckets[i] = i;
        }
        else
        {
            while (i + 1 < size && arr[i + 1] > min_val + diff)
            {
                i++;
            }
            buckets[i] = i;
        }
    }

    printf("Bucketized Array: ");
    for (int i = 0; i < MAX_SIZE + 1; i++)
    {
        printf("%d ", buckets[i]);
    }
    printf("\n");

    for (int i = 0; i < MAX_SIZE + 1; i++)
    {
        int temp = 0;
        for (int j = 0; j < buckets[i]; j++)
        {
            temp = temp * 10 + (arr[j] % 10);
        }
        arr[i] = temp;
    }

    printf("Sorted Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}