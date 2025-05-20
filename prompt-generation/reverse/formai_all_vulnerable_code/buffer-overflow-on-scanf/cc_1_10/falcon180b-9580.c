//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 10000

int main()
{
    int i, n, max, min, temp;
    int *arr;
    clock_t start, end;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    arr = (int *)malloc(n*sizeof(int));
    
    printf("Enter the elements:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        
        if(i == 0)
        {
            max = arr[i];
            min = arr[i];
        }
        else if(arr[i] > max)
        {
            max = arr[i];
        }
        else if(arr[i] < min)
        {
            min = arr[i];
        }
    }
    
    start = clock();
    for(i=0; i<n; i++)
    {
        if(arr[i] == max)
        {
            printf("%d ", arr[i]);
        }
    }
    end = clock();
    
    printf("\nTime taken: %f seconds\n", (double)(end-start)/CLOCKS_PER_SEC);
    
    temp = max;
    max = min;
    min = temp;
    
    start = clock();
    for(i=0; i<n; i++)
    {
        if(arr[i] == min)
        {
            printf("%d ", arr[i]);
        }
    }
    end = clock();
    
    printf("\nTime taken: %f seconds\n", (double)(end-start)/CLOCKS_PER_SEC);
    
    free(arr);
    
    return 0;
}