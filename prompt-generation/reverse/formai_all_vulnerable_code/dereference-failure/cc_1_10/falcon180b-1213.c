//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void bucket_sort(int* arr, int n)
{
    int i, j, max_val = *arr, min_val = *arr;
    int* bucket[MAX_SIZE];
    for(i = 0; i < n; i++)
    {
        if(*(arr+i) > max_val)
        {
            max_val = *(arr+i);
        }
        if(*(arr+i) < min_val)
        {
            min_val = *(arr+i);
        }
    }
    int range = max_val - min_val + 1;
    for(i = 0; i < range; i++)
    {
        bucket[i] = malloc(sizeof(int));
    }
    for(i = 0; i < n; i++)
    {
        int index = (*(arr+i) - min_val) / (MAX_SIZE / n);
        if(index >= n)
        {
            index = n - 1;
        }
        if(index < 0)
        {
            index = 0;
        }
        int* temp = bucket[index];
        bucket[index] = malloc(sizeof(int));
        *bucket[index] = *(arr+i);
        free(temp);
    }
    int index = 0;
    for(i = 0; i < range; i++)
    {
        if(bucket[i])
        {
            for(j = 0; j < MAX_SIZE / n; j++)
            {
                int temp = *(bucket[i]+j);
                *(bucket[i]+j) = *(bucket[i]+(MAX_SIZE / n) - 1 - j);
                *(bucket[i]+(MAX_SIZE / n) - 1 - j) = temp;
            }
            memcpy(arr+index, bucket[i], sizeof(int) * MAX_SIZE / n);
            index += MAX_SIZE / n;
        }
    }
    for(i = 0; i < range; i++)
    {
        free(bucket[i]);
    }
}

int main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int* arr = malloc(sizeof(int) * n);
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &*(arr+i));
    }
    bucket_sort(arr, n);
    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", *(arr+i));
    }
    printf("\n");
    free(arr);
    return 0;
}