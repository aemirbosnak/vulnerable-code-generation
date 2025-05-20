#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buffer = malloc(1024);
    int len = 0;

    // Read the request body from the socket
    int read_size = read(0, buffer, 1024);

    // Write the request body to the file
    if (read_size > 0)
    {
        len = write(1, buffer, read_size);
    }

    // Free the memory
    free(buffer);

    return 0;
}
