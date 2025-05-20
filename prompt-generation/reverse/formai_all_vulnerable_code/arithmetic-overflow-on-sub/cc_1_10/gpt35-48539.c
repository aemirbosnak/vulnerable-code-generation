//FormAI DATASET v1.0 Category: Memory management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Enter number of integers to be stored in memory:\n");
    scanf("%d", &size);
    
    int *ptr = (int*) malloc(size * sizeof(int)); // allocate memory dynamically
    
    if(ptr == NULL) // check if memory allocation was successful or not
    {
        printf("Memory allocation failed!");
        exit(0); // terminate the program
    }
    
    printf("Enter %d integers:\n", size);
    for(int i=0; i<size; i++)
    {
        scanf("%d", &*(ptr+i)); // store values input by user in allocated memory
    }
    
    printf("The integers entered are:\n");
    for(int i=0; i<size; i++)
    {
        printf("%d ", *(ptr+i)); // print all the integers
    }
    
    int new_size;
    printf("\nEnter new number of integers to be allocated:\n");
    scanf("%d", &new_size);
    
    int *new_ptr = (int*) realloc(ptr, new_size * sizeof(int)); // reallocate memory dynamically
    
    if(new_ptr == NULL) // check if memory allocation was successful or not
    {
        printf("\nMemory reallocation failed!");
        exit(0); // terminate the program
    }
    
    printf("\nSuccessfully reallocated memory!\n");
    ptr = new_ptr; // store the new address returned by realloc() in the original pointer variable
    
    printf("\nEnter %d new integers:\n", new_size-size);
    for(int i=size; i<new_size; i++)
    {
        scanf("%d", &*(ptr+i)); // store new values input by user in reallocated memory
    }
    
    printf("The new integers are:\n");
    for(int i=0; i<new_size; i++)
    {
        printf("%d ", *(ptr+i)); // print all the integers (old and new)
    }
    
    free(ptr); // free the allocated memory
    
    return 0;
}