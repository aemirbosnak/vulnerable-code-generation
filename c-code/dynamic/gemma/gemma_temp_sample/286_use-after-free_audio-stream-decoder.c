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

    // Free the memory, but try to use it anyway
    free(buffer);
    buffer[0] = 'A';

    // Print the content of the buffer
    printf("%c", buffer[0]);

    return 0;
}
