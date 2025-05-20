#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buffer = malloc(1024);
    int size = 0;
    int i = 0;

    while (1)
    {
        // Receive data from the stream
        int read_size = read(0, buffer, 1024);

        // Update the size of the buffer if necessary
        if (read_size > size)
        {
            size = read_size;
            buffer = realloc(buffer, size);
        }

        // Play the data
        write(1, buffer, read_size);

        // Check if the stream has ended
        if (read_size == 0)
            break;

        // Increment the index
        i++;
    }

    free(buffer);
    return 0;
}
