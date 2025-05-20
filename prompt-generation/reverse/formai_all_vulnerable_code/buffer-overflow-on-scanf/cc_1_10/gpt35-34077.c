//FormAI DATASET v1.0 Category: Memory management ; Style: modular
#include<stdio.h>
#include<stdlib.h>

//Global variable declaration
int *ptr;

//Function declaration
void allocate_memory(int);
void initialize_memory(int);
void display_memory(int);

//Function Definition
void allocate_memory(int n)
{
    ptr = (int*) malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }
}

void initialize_memory(int n)
{
    for (int i=0; i<n; i++)
    {
        *(ptr+i) = i+1;
    }
}

void display_memory(int n)
{
    printf("Allocated memory: ");
    for (int i=0; i<n; i++)
    {
        printf("%d ", *(ptr+i));
    }
    printf("\n");
}

//Main function
int main()
{
    int n;
    printf("Enter the size of memory to be allocated: ");
    scanf("%d", &n);

    allocate_memory(n);
    initialize_memory(n);
    display_memory(n);

    free(ptr);
    printf("Memory freed successfully\n");

    return 0;
}