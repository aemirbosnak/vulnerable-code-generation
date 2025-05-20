//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

void bucket_sort(int arr[], int n)
{
    int i, j, max = 0, min = 1000000;
    int *bucket[MAX_SIZE];
    for(i=0; i<n; i++)
    {
        if(arr[i]>max)
            max = arr[i];
        if(arr[i]<min)
            min = arr[i];
    }
    int range = max-min+1;
    for(i=0; i<MAX_SIZE; i++)
        bucket[i] = NULL;
    for(i=0; i<n; i++)
    {
        int index = (arr[i]-min)*MAX_SIZE/range;
        if(bucket[index] == NULL)
        {
            bucket[index] = malloc(sizeof(int));
            *(int*)bucket[index] = arr[i];
        }
        else
        {
            void *temp = realloc(bucket[index], sizeof(int)*2);
            if(temp == NULL)
            {
                printf("Error: Memory could not be allocated.\n");
                exit(0);
            }
            bucket[index] = temp;
            *(int*)(bucket[index]+sizeof(int)) = arr[i];
        }
    }
    int k = 0;
    for(i=0; i<MAX_SIZE; i++)
    {
        if(bucket[i]!= NULL)
        {
            for(j=0; j<2; j++)
            {
                arr[k++] = *(int*)bucket[i]+j*sizeof(int);
            }
        }
    }
}

int main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    bucket_sort(arr, n);
    printf("Sorted array: ");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}