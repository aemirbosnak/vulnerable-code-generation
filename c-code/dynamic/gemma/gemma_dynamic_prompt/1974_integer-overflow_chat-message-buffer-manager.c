#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int buffer_size = 10;
    char *message_buffer = malloc(buffer_size);

    int message_length = 0;
    char message[1024] = "This is a long message that will cause an integer overflow";

    message_length = strlen(message) + 1;

    if (message_length > buffer_size)
    {
        printf("Error: Message too long.\n");
        return 1;
    }

    memcpy(message_buffer, message, message_length);

    printf("Message stored: %s\n", message_buffer);

    free(message_buffer);

    return 0;
}
