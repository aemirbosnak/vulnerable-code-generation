#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **buffer = NULL;
    int size = 0;

    // Allocate memory for the buffer
    buffer = malloc(16);
    if (buffer == NULL)
    {
        return 1;
    }

    // Increase the size of the buffer
    size = 10;
    buffer = realloc(buffer, size * 2);
    if (buffer == NULL)
    {
        return 1;
    }

    // Free the memory allocated for the buffer
    free(buffer);

    // Use the freed memory, causing a use after free vulnerability
    buffer[0] = 'A';

    return 0;
}
