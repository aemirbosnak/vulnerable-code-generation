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

    // Allocate memory for the buffer
    buffer = malloc(1024);

    // Free the memory, but attempt to use it afterwards
    free(buffer);

    // Use the freed memory to store data
    buffer[0] = 'H';
    buffer[1] = 'E';
    buffer[2] = 'L';

    // Print the data stored in the freed memory
    printf("%s", buffer);

    return 0;
}
