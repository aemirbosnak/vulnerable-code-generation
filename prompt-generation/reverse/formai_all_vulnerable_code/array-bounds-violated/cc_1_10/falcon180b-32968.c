//Falcon-180B DATASET v1.0 Category: Sorting ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Function to compare two integers
int compare(void *a, void *b)
{
    int *temp1 = a;
    int *temp2 = b;
    return (*temp1 - *temp2);
}

//Function to perform counting sort on an array of integers
void countingSort(int arr[], int n)
{
    int max = arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }

    int *count = (int *)malloc(max*sizeof(int));
    for(int i=0;i<=max;i++)
    {
        count[i] = 0;
    }

    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }

    int sum = 0;
    for(int i=1;i<=max;i++)
    {
        sum += count[i];
    }

    int sortedArr[n];
    for(int i=n-1;i>=0;i--)
    {
        sortedArr[--count[arr[i]]] = arr[i];
    }

    for(int i=0;i<n;i++)
    {
        arr[i] = sortedArr[i];
    }
}

int main()
{
    int n;
    printf("Enter the number of integers: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter %d integers:\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    countingSort(arr,n);

    printf("Sorted array:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}