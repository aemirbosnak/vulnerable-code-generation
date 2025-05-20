#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *message_buffer = NULL;
    int message_length = 0;

    // Allocate memory for the message buffer
    message_buffer = malloc(1024);

    // Store the message length
    message_length = 512;

    // Attempt to dereference the null pointer
    *(message_buffer + message_length) = 'H';

    // Print the message
    printf("%s", message_buffer);

    // Free the memory
    free(message_buffer);

    return 0;
}
