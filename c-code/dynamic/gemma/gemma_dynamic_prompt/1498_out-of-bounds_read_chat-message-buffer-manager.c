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
    buffer = malloc(size);

    // Read data from the buffer, out of bounds
    char data = buffer[size - 1];

    // Print the data
    printf("%c", data);

    return 0;
}
