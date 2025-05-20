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

    // Allocate memory for file data
    buffer = malloc(1024);

    // Read file data from client
    size = read(0, buffer, 1024);

    // Access an element beyond the bounds of the array
    buffer[size] = 'A';

    // Free memory
    free(buffer);

    return 0;
}
