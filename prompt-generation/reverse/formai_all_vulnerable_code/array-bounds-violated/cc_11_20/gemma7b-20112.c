//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char buff[1024];
    int i, j, k;
    printf("Enter C code: ");
    fgets(buff, 1024, stdin);

    // Strip comments and whitespace
    for (i = 0; buff[i] != '\0'; i++)
    {
        if (buff[i] == '/' && buff[i + 1] == '/')
        {
            buff[i] = '\0';
            i++;
        } else if (buff[i] == ' ' && buff[i - 1] != '}')
        {
            buff[i] = '\0';
        }
    }

    // Indent blocks
    for (i = 0; buff[i] != '\0'; i++)
    {
        if (buff[i] == '{' || buff[i] == '}')
        {
            for (j = i + 1; buff[j] != '\0' && buff[j] != '{' && buff[j] != '}'; j++)
            {
                buff[j] = ' ';
            }
        }
    }

    // Format braces
    for (i = 0; buff[i] != '\0'; i++)
    {
        if (buff[i] == '{')
        {
            for (j = i - 1; buff[j] != '{' && buff[j] != '}'; j--)
            {
                buff[j] = ' ';
            }
        }
    }

    // Print beautified code
    printf("Beautified C code:\n");
    printf("%s", buff);

    return 0;
}