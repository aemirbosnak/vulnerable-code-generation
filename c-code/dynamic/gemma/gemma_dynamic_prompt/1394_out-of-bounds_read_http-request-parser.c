#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char *buffer = NULL;
    int size = 0;

    // Allocate memory for the buffer
    buffer = malloc(1024);

    // Read the request body from the client
    int read_bytes = read(0, buffer, 1024);

    // Out of bounds read
    int offset = read_bytes * 2;
    char *vulnerable_data = buffer + offset;

    // Print the vulnerable data
    printf("%s", vulnerable_data);

    // Free the memory
    free(buffer);

    return 0;
}
