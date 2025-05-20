//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sanitize_input(char **str)
{
    char **ptr = str;
    int length = 0;

    while (*ptr)
    {
        length++;
        ptr++;
    }

    if (length > 10)
    {
        printf("Error: Input too long. Please limit to 10 characters or less.\n");
        return -1;
    }

    *str = malloc(length);
    ptr = *str;

    printf("Enter your input: ");
    scanf("%s", ptr);

    for (ptr = *str; *ptr; ptr++)
    {
        if (*ptr >= 'a' && *ptr <= 'z')
        {
            *ptr = toupper(*ptr);
        }
        else if (*ptr >= 'A' && *ptr <= 'Z')
        {
            *ptr = tolower(*ptr);
        }
        else if (*ptr >= '0' && *ptr <= '9')
        {
            // Leave number unchanged
        }
        else
        {
            *ptr = '\0';
        }
    }

    return 0;
}

int main()
{
    char *str = NULL;

    if (sanitize_input(&str) == -1)
    {
        return 1;
    }

    printf("Your sanitized input is: %s\n", str);

    free(str);

    return 0;
}