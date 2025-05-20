#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buffer = NULL;
    int size = 0;

    // Mallocate memory for the buffer
    buffer = (char *)malloc(size);

    // Attempt to dereference a null pointer
    *buffer = 0xdeadbeef;

    // Free the memory
    free(buffer);

    return 0;
}
