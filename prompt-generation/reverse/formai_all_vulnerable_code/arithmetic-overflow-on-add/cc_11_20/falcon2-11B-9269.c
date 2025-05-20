//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    char *array;

    while (1)
    {
        printf("Please enter a valid integer: ");
        scanf("%d", &size);

        if (size >= 0)
            break;

        printf("Invalid input. Please try again.\n");
    }

    while (1)
    {
        printf("Please enter the size of the array: ");
        scanf("%d", &size);

        if (size > 0)
            break;

        printf("Invalid input. Please try again.\n");
    }

    array = (char *)malloc(size * sizeof(char));

    if (array == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    while (1)
    {
        printf("Please enter the elements of the array: ");
        char c;

        while (1)
        {
            scanf("%c", &c);

            if (c >= 'a' && c <= 'z')
                break;

            printf("Invalid input. Please try again.\n");
        }

        array[size - 1] = c;

        printf("Element %d: %c\n", size - 1, array[size - 1]);

        if (++size == 0)
            break;
    }

    printf("Memory management complete.\n");

    free(array);

    return 0;
}