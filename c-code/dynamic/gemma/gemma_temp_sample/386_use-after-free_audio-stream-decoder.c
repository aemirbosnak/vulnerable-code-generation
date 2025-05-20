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

    // Allocate memory for the buffer
    buffer = malloc(1024);

    // Free the memory allocated for the buffer
    free(buffer);

    // Use the freed memory for writing data
    buffer[0] = 'H';
    buffer[1] = 'i';
    buffer[2] = 's';

    // Print the data stored in the buffer
    printf("%s", buffer);

    return 0;
}
