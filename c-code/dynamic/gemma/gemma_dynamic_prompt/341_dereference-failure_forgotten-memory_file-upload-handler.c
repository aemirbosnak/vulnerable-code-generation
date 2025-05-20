#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buf = NULL;
    int size = 0;

    // Allocate memory for file data
    buf = malloc(size);

    // Attempt to dereference a null pointer
    *(buf + size) = 'A';

    // Free the memory
    free(buf);

    return 0;
}
