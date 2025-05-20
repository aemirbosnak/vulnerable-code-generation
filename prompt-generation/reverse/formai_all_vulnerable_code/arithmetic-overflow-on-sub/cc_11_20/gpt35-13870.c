//FormAI DATASET v1.0 Category: Benchmarking ; Style: energetic
#include<stdio.h>
#include<time.h>

int main()
{
    clock_t start, end;

    int array[5000], n, i, j, temp, k, x;
    double timeTaken;

    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);

    //Fill the array with random numbers between 1 and 1000
    for(i=0;i<n;i++)
    {
        array[i] = (rand()%1000)+1;
    }

    /*Print the array before sorting*/
    printf("\n\nArray before sorting: \n\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",array[i]);
    }

    /*Bubble sort algorithm*/
    start = clock();
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(array[j]>array[j+1])
            {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }

    end = clock();
    timeTaken = ((double) (end - start)) / CLOCKS_PER_SEC;

    /*Print the array after sorting*/
    printf("\n\nArray after sorting: \n\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",array[i]);
    }

    printf("\n\nTime taken to sort the array: %f seconds", timeTaken);

    /*Binary search algorithm*/
    printf("\n\nEnter the number to search: ");
    scanf("%d",&x);

    start = clock();
    i = 0;
    j = n-1;
    k = (i+j)/2;

    while(i<=j)
    {
        if(array[k]<x)
        {
            i=k+1;
        }
        else if(array[k]>x)
        {
            j=k-1;
        }
        else
        {
            printf("\n\n%d found in the array at position %d",x,k+1);
            break;
        }
        k = (i+j)/2;
    }

    if(i>j)
    {
        printf("\n\n%d not found in the array",x);
    }

    end = clock();
    timeTaken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTime taken to search the array: %f seconds", timeTaken);

    return 0;
}