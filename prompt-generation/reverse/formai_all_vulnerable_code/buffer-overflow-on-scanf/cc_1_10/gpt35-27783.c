//FormAI DATASET v1.0 Category: Memory management ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i;
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    int *ptr = (int*)malloc(n*sizeof(int));
    
    //Checking if memory is allocated or not
    if(ptr==NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {
        printf("Memory allocated.\n");
    }

    //Accepting integers and storing them in heap memory
    printf("Enter the integers:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", ptr+i);
    }

    printf("The entered integers are: ");
    for(i=0; i<n; i++)
    {
        printf("%d ", *(ptr+i));
    }

    //Reallocating memory for additional integers
    printf("\nEnter the number of additional integers you want to enter: ");
    scanf("%d", &n);
    ptr = realloc(ptr,n*sizeof(int));
    
    //Checking if memory is reallocated or not
    if(ptr==NULL)
    {
        printf("Memory not reallocated.\n");
        exit(0);
    }
    else
    {
        printf("Memory reallocated successfully.\n");
    }
 
    //Accepting additional integers and storing them in heap memory
    printf("Enter the additional integers:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", ptr+i);
    }

    printf("The integers after reallocation are: ");
    for(i=0; i<n+5; i++) //Adding additional integers to the count for displaying all integers
    {
        printf("%d ", *(ptr+i));
    }

    free(ptr); //Freeing the memory allocated
    
    return 0; 
}