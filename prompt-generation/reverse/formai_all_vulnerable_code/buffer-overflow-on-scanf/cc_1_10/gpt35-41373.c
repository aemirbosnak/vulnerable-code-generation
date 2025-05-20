//FormAI DATASET v1.0 Category: Memory management ; Style: complex
#include<stdio.h>
#include<stdlib.h>

int main()
{
    // Define variables
    int i, n;
    int *ptr, *temp;

    // Run user input for number of integers
    printf("Enter the number of integers you want to store: ");
    scanf("%d", &n);

    // Allocate memory dynamically for n integers
    ptr = (int*)malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory allocation error!");
        exit(0);
    }

    // Get integers from the user and store them in the dynamically allocated memory
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }

    // Display the integers
    printf("The integers you entered are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }

    // Resize the dynamically allocated memory to hold (n+1) integers
    temp = (int*)realloc(ptr, (n + 1) * sizeof(int));
    if (temp == NULL)
    {
        printf("Memory reallocation error!");
        exit(0);
    }
    else
    {
        ptr = temp; // assign the new memory block to the original pointer
    }

    // Get the new integer from the user and store it in the newly allocated memory block
    printf("\nEnter one more integer: ");
    scanf("%d", ptr + n);

    // Display the integers after adding the new one
    printf("The integers after adding one more integer are:\n");
    for (i = 0; i < (n + 1); i++)
    {
        printf("%d ", *(ptr + i));
    }

    // Free dynamically allocated memory
    free(ptr);

    return 0;
}