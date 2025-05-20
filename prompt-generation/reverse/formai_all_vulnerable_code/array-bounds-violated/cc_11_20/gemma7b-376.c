//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i = 0;
    char ch;

    printf("Enter a URL: ");
    while ((ch = getchar()) != '\n')
    {
        if (i < MAX_BUFFER_SIZE - 1)
        {
            buffer[i++] = ch;
        }
    }

    buffer[i] = '\0';

    // Sanitize the URL

    // Remove all special characters
    for (i = 0; buffer[i] != '\0'; i++)
    {
        if (!isalnum(buffer[i]) && buffer[i] != '-' && buffer[i] != '_')
        {
            buffer[i] = '_';
        }
    }

    // Remove all duplicate slashes
    i = 0;
    for (int j = 1; buffer[j] != '\0'; j++)
    {
        if (buffer[j] == '/' && buffer[i] == '/')
        {
            buffer[j] = '_';
        }
        else
        {
            i = j;
        }
    }

    // Remove all leading and trailing slashes
    if (buffer[0] == '/')
    {
        memmove(buffer, buffer + 1, strlen(buffer) - 1);
    }
    if (buffer[strlen(buffer) - 1] == '/')
    {
        buffer[strlen(buffer) - 1] = '\0';
    }

    // Print the sanitized URL
    printf("Sanized URL: %s\n", buffer);

    return 0;
}