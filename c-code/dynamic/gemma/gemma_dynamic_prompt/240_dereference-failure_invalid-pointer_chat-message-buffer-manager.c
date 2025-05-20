#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *message_buffer = NULL;
    int message_size = 0;

    // Allocate memory for the message buffer
    message_buffer = malloc(1024);

    // Write a message to the buffer
    message_buffer[0] = 'H';
    message_buffer[1] = 'i';
    message_buffer[2] = 'r';
    message_buffer[3] = '\0';

    // Attempt to dereference an invalid pointer
    *(message_buffer + 1024) = 'A';

    // Free the memory allocated for the message buffer
    free(message_buffer);

    return 0;
}
