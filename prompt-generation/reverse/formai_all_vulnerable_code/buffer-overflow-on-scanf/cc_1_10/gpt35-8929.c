//FormAI DATASET v1.0 Category: Memory management ; Style: content
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr, *temp;
    int i, n;

    printf("Enter the number of elements you want to store: ");
    scanf("%d", &n);

    ptr = (int*)malloc(n * sizeof(int));

    if(ptr == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }

    printf("Enter the elements:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", (ptr+i));
    }

    printf("The elements in the array are:\n");
    for(i=0; i<n; i++)
    {
        printf("%d ", *(ptr+i));
    }

    printf("\nEnter the new size of the array: ");
    scanf("%d", &n);

    temp = (int*)realloc(ptr, n * sizeof(int));

    if(temp == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }

    ptr = temp;

    printf("Enter the new elements:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", (ptr+i));
    }

    printf("The new elements in the array are:\n");
    for(i=0; i<n; i++)
    {
        printf("%d ", *(ptr+i));
    }

    free(ptr);

    return 0;
}