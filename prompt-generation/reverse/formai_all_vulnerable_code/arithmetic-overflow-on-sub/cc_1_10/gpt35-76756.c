//FormAI DATASET v1.0 Category: Sorting ; Style: mind-bending
#include <stdio.h>

//Function to print the array
void printArr(int arr[], int size)
{
    printf("\nYour Sorted Array is: ");
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n\nGoddamn mind-bending, isn't it? ;)");
}

//Sorting function
void sortArr(int arr[], int size)
{
    int temp;
    for(int i=0; i<size-1; i++)
    {
        for(int j=0; j<size-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printArr(arr, size);
}

//Main Function
int main()
{
    printf("Welcome to the Mind-Bending Sorting Program!\n\n");
    
    //Taking user input
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    //Initializing the array
    int arr[size];
    for(int i=0; i<size; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    //Sorting the array
    sortArr(arr, size);
    
    printf("Thank you for using the Mind-Bending Sorting Program :)");
    return 0;
}