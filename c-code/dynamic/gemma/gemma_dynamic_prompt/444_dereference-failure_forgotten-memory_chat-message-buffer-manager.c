#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **buffer = NULL;
    int size = 0;

    // Allocate memory for the buffer
    buffer = malloc(10 * sizeof(char *));
    if (buffer == NULL)
    {
        exit(1);
    }

    // Fill the buffer with data
    for (int i = 0; i < 10; i++)
    {
        buffer[i] = malloc(10 * sizeof(char));
        if (buffer[i] == NULL)
        {
            exit(1);
        }
        memset(buffer[i], 'a', 10);
    }

    // Free the memory
    for (int i = 0; i < 10; i++)
    {
        free(buffer[i]);
    }
    free(buffer);

    return 0;
}
