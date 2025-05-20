//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i, j, len, flag = 0;

    // Get the user input
    printf("Enter a message: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Strip the newline character
    len = strlen(buffer);
    if (buffer[len - 1] == '\n')
    {
        buffer[len - 1] = '\0';
    }

    // Remove all special characters
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (buffer[i] == j)
            {
                buffer[i] = ' ';
            }
        }
    }

    // Check if the input is valid
    if (strlen(buffer) > 0)
    {
        flag = 1;
    }

    // Print the sanitized message
    if (flag)
    {
        printf("Sanitized message: %s\n", buffer);
    }
    else
    {
        printf("Error: invalid input.\n");
    }

    return 0;
}