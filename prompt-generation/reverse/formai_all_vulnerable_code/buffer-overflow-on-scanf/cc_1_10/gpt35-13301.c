//FormAI DATASET v1.0 Category: Searching algorithm ; Style: imaginative
#include<stdio.h>
#define MAX_SIZE 50

//Function to search an element in an array
int search(int arr[], int size, int item)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(arr[i]==item)
        {
            return i; //Item is found, return index
        }
    }
    return -1; //Item is not found, return -1
}

int main()
{
    int arr[MAX_SIZE];
    int size, i, item;

    printf("Enter size of array: ");
    scanf("%d",&size);

    //Input elements in the array
    printf("Enter %d elements: ", size);
    for(i=0; i<size; i++)
    {
        scanf("%d",&arr[i]);
    }

    //Input the element to be searched
    printf("Enter element to be searched: ");
    scanf("%d",&item);

    //Call the search function to search the element in the array
    int index = search(arr,size,item);

    //Print the result
    if(index==-1)
    {
        printf("%d not found in the array.",item);
    }
    else
    {
        printf("%d found at index %d in the array.",item,index);
    }

    return 0;
}