#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buffer = NULL;
    int size = 0;

    // Allocate memory for the buffer
    buffer = malloc(size);

    // Attempt to dereference the null pointer
    *buffer = 0xDEADBEEF;

    // Free the memory
    free(buffer);

    return 0;
}
