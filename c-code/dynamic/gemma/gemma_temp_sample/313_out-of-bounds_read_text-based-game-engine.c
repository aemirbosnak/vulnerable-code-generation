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
    char ch;

    // Allocate memory for the buffer
    buffer = malloc(size);

    // Read the character
    ch = getchar();

    // Out-of-bounds read
    buffer[size] = ch;

    // Free the memory
    free(buffer);

    return 0;
}
