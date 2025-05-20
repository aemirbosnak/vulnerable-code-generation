//FormAI DATASET v1.0 Category: Memory management ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Enter the value for n: ");
    scanf("%d",&n);
    int *arr;

    //allocate memory dynamically for the array
    arr=(int*)malloc(sizeof(int)*n);

    //check if memory allocation is successful
    if(arr==NULL)
    {
        printf("Memory allocation failed!");
        exit(0);
    }

    printf("Enter %d elements for the array:\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    //calculate the average of the elements in the array
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }
    float avg=(float)sum/n;
    printf("The average of the %d elements is: %f\n",n,avg);

    //reallocate memory for the array
    int new_size=n*2;
    arr=(int*)realloc(arr,new_size*sizeof(int));

    //check if reallocation is successful
    if(arr==NULL)
    {
        printf("Memory reallocation failed!");
        exit(0);
    }

    printf("Enter %d more elements for the array:\n",n);
    for(int i=n;i<new_size;i++)
    {
        scanf("%d",&arr[i]);
    }

    //calculate the sum of all elements in the array
    sum=0;
    for(int i=0;i<new_size;i++)
    {
        sum=sum+arr[i];
    }
    printf("The sum of all %d elements in the array is: %d\n",new_size,sum);

    //free the memory allocated for the array
    free(arr);

    return 0;
}