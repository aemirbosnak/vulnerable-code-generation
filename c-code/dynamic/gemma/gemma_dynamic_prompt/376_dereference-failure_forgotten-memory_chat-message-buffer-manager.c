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
        return 1;
    }

    // Create a message
    char message[] = "Hello, world!";

    // Attempt to dereference the buffer beyond its size
    buffer[size] = message;

    // Print the message
    printf("%s", buffer[size]);

    // Free the memory
    free(buffer);

    return 0;
}
