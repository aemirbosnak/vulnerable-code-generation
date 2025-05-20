//Gemma-7B DATASET v1.0 Category: Error handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void handle_error(int error_code)
{
    switch (error_code)
    {
        case 1:
            printf("Error: Invalid input.\n");
            break;
        case 2:
            printf("Error: Memory allocation failure.\n");
            break;
        case 3:
            printf("Error: File not found.\n");
            break;
        default:
            printf("Error: Unknown error.\n");
            break;
    }
    exit(1);
}

int main()
{
    int result = 0;
    int* ptr = NULL;

    // Dynamic memory allocation
    ptr = (int*)malloc(10 * sizeof(int));
    if (ptr == NULL)
    {
        handle_error(2);
    }

    // Invalid input
    result = scanf("%d", ptr);
    if (result != 1)
    {
        handle_error(1);
    }

    // File not found
    FILE* file = fopen("non-existent.txt", "r");
    if (file == NULL)
    {
        handle_error(3);
    }

    // Free memory
    free(ptr);

    return 0;
}