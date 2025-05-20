//FormAI DATASET v1.0 Category: Sorting ; Style: protected
#include<stdio.h>
#define MAX 50

// function prototype
void sort(int arr[], int n);

int main()
{
    int arr[MAX], i, n;

    // input
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // check if array size is not beyond limit
    if(n>MAX)
    {
        printf("Array size out of limit!\n");
        return 0;
    }

    // input elements
    printf("Enter the array elements: ");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);

    // sort function call
    sort(arr, n);

    // print sorted array
    printf("\nThe sorted array is: ");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);

    return 0;
}

// sort function implementation
void sort(int arr[], int n)
{
    int i, j, temp;

    // bubble sort algorithm
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}