#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buffer = NULL;
    size_t size = 0;

    // Allocate memory for the buffer
    buffer = malloc(size);

    // Attempt to dereference the null pointer
    *(buffer + size) = 'a';

    // Free the memory
    free(buffer);

    return 0;
}
