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
    int message_length = 0;
    char message[1024] = "This is a message";

    buffer = malloc(size); // Invalid memory allocation, but the program continues
    buffer[message_length] = message; // Dereference failure, as the pointer is invalid

    printf("Message: %s", buffer[message_length]); // May crash, as the pointer is invalid

    free(buffer);

    return 0;
}
