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
    buffer = malloc(1024);

    // Get the size of the message from the user
    int message_size = 0;
    printf("Enter the size of the message: ");
    scanf("%d", &message_size);

    // Create a message
    char message[message_size + 1];
    printf("Enter the message: ");
    scanf("%s", message);

    // Write the message to the buffer
    memcpy(buffer, message, message_size);

    // Free the memory allocated for the buffer
    free(buffer);

    return 0;
}
