#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

int main()
{
    char **messages = NULL;
    int size = 0;

    // Allocate memory for the first message
    messages = malloc(sizeof(char *) * 1);
    messages[0] = malloc(10);
    messages[0] = "Hello, world!";

    // Increase the size of the buffer
    messages = realloc(messages, sizeof(char *) * 2);
    messages[1] = malloc(10);
    messages[1] = "Goodbye, world!";

    // Print the messages
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", messages[i]);
    }

    // Free the memory
    for (int i = 0; i < size; i++)
    {
        free(messages[i]);
    }
    free(messages);

    return 0;
}
