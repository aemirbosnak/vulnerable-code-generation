#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptr = NULL;
    int i = 0;

    // Allocate memory for the pointer
    ptr = malloc(10);

    // Loop to demonstrate the dereference failure
    for (i = 0; i < 10; i++)
    {
        // Attempt to dereference the pointer
        printf("%c", *(ptr + i));
    }

    // Free the memory
    free(ptr);

    return 0;
}
