#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buffer = NULL;
    int size = 1024 * 4;
    buffer = malloc(size);
    if (buffer == NULL)
    {
        return 1;
    }

    // Read data from beyond the allocated memory
    buffer[size - 1] = 'A';
    printf("%s", buffer);

    free(buffer);
    return 0;
}
