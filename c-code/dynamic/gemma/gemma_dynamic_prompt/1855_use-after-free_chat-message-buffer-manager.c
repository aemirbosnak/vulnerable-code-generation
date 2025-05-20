#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 10;
    char **messages = (char **)malloc(size * sizeof(char *));
    for(int i = 0; i < size; i++)
    {
        messages[i] = (char *)malloc(1024);
    }

    messages[0] = "Hello, world!";
    messages[1] = "This is a message.";
    messages[2] = "The buffer is full!";

    for(int i = 0; i < size; i++)
    {
        printf("%s\n", messages[i]);
    }

    for(int i = 0; i < size; i++)
    {
        free(messages[i]);
    }
    free(messages);

    return 0;
}
