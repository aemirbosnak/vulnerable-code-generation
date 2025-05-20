//FormAI DATASET v1.0 Category: Memory management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to Memory Management in C!\n");

    printf("Enter the size of integer array you want to create: ");
    int size;
    scanf("%d",&size);

    int* num_array;
    num_array = (int*) malloc(size * sizeof(int)); // allocating memory dynamically

    if(num_array == NULL)
    {
        printf("Memory Allocation Failed!");
        exit(1);
    }

    printf("Enter %d integers:\n",size);
    for(int i=0; i<size; i++)
    {
        scanf("%d", &num_array[i]);
    }

    printf("The entered integers are: ");
    for(int i=0; i<size; i++)
    {
        printf("%d ", num_array[i]);
    }

    num_array = (int*) realloc(num_array, (size+5) * sizeof(int)); // reallocating memory dynamically

    printf("\n\nEnter 5 more integers:\n");
    for(int i=size; i<(size+5); i++)
    {
        scanf("%d", &num_array[i]);
    }

    printf("The entered integers are: ");
    for(int i=0; i<(size+5); i++)
    {
        printf("%d ", num_array[i]);
    }

    free(num_array); // free allocated memory

    printf("\n\nThanks for using Memory Management in C!\n");

    return 0;
}