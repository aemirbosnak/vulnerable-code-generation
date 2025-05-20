#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main()
{
    char *ptr = NULL;
    int i = 0;

    // Allocate memory for 10 elements
    ptr = malloc(10 * sizeof(char));

    // Loop through the allocated memory
    for (i = 0; i < 10; i++)
    {
        // Attempt to dereference the pointer, but the memory is not valid
        (*(ptr + i)) = 'A';
    }

    // Free the memory
    free(ptr);

    return 0;
}
