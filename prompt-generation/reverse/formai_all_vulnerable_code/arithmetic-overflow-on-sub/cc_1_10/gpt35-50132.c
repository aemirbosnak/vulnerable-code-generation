//FormAI DATASET v1.0 Category: Memory management ; Style: mind-bending
#include<stdio.h>
int main()
{
    int *arr,*ptr;
    int i,j,k,n,t;

    printf("Enter the number of elements: ");
    scanf("%d",&n);

    arr = (int*)malloc(n*sizeof(int)); //allocating memory dynamically

    if(arr == NULL)
    {
        printf("Error! memory not allocated.");
        return 0;
    }

    //code to input the elements of array
    for(i=0;i<n;i++)
    {
        printf("Enter element[%d]: ",i);
        scanf("%d",(arr+i));
    }

    //code to print the elements of array
    printf("\nElements of array are: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(arr+i));
    }

    //code to sort the elements of the array using bubble sort
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(*(arr+j)>*(arr+j+1))
            {
                t = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = t;
            }
        }
    }

    //code to print the sorted array
    printf("\n\nSorted array is: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(arr+i));
    }

    ptr = arr;

    //code to delete the memory allocated
    free(ptr);

    return 0;
}