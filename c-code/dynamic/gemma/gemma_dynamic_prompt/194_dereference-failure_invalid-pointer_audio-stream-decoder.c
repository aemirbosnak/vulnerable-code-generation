#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

// Invalid pointer example program for audio stream decoder

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Allocate memory for a buffer
    int *buffer = malloc(1024);

    // Access an invalid pointer
    buffer[-1] = 0xdeadbeef;

    // Free the memory
    free(buffer);

    return 0;
}
