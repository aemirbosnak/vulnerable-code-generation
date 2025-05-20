//FormAI DATASET v1.0 Category: Memory management ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

//recursive function to allocate memory for the array
int *allocate_memory(int num)
{
    int *arr;
    arr=(int*)malloc(num*sizeof(int));
    //error handling if memory is not allocated
    if(arr==NULL)
    {
        printf("\nMemory not allocated!");
        exit(0);
    }
    //returning the allocated memory array
    return arr;
}

//recursive function to fill the values in the array
void fill_values(int *arr,int num,int i)
{
    //base condition of the recursive function
    if(i==num)
    {
        return;
    }
    else
    {
        //taking input from user to fill the array
        printf("\nEnter the value at position %d: ",i+1);
        scanf("%d",&arr[i]);

        //calling the function again by increasing the value of i
        fill_values(arr,num,i+1);
    }
}

//recursive function to display the values of the array
void display_values(int *arr,int num,int i)
{
    //base condition of the recursive function
    if(i==num)
    {
        return;
    }
    else
    {
        //displaying the value of the array
        printf("%d\t",arr[i]);
        
        //calling the function again by increasing the value of i
        display_values(arr,num,i+1);
    }
}

int main()
{
    int *arr; //declaring a pointer variable
    int num; //declaring a variable to store the size of the array
    int choice; //declaring a variable to store the user's choice to continue or exit
    int i=0; //declaring a variable to be used in the recursive functions

    //taking input from user for the size of the array
    printf("\nEnter the size of the array: ");
    scanf("%d",&num);

    //function call to allocate the memory for the array
    arr=allocate_memory(num);

    //function call to fill the values in the array
    fill_values(arr,num,i);

    //displaying the values of the array
    printf("\nThe values in the array are: ");
    display_values(arr,num,i);

    //asking user if they want to continue or exit
    printf("\n\nDo you want to continue(1/0)? ");
    scanf("%d",&choice);

    //recursive call to the main function if user chooses to continue
    if(choice==1)
    {
        main();
    }
    else
    {
        //freeing the memory allocation given to the array
        free(arr);
        printf("\n\nProgram exited successfully!");
        return 0;
    }
}