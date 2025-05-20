//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define URL_MAX_LENGTH 2048

int main()
{
    // Take user input as URL
    char url[URL_MAX_LENGTH];
    printf("Enter URL to sanitize: ");
    scanf("%s", url);

    // Check the URL for any invalid characters
    char invalid_characters[] = "<>@!#$%^&*()_+[]{}?;/\\\"'";
    int len = strlen(url);
    for (int i = 0; i < len; i++)
    {
        if (strchr(invalid_characters, url[i]) != NULL)
        {
            printf("Invalid character detected: %c\n", url[i]);
            return 1;
        }
    }

    // Convert the URL to lower case
    for (int i = 0; i < len; i++)
    {
        url[i] = tolower(url[i]);
    }

    // Remove any trailing slash from the URL
    if (url[len - 1] == '/')
    {
        url[len - 1] = '\0';
        len--;
    }

    // Remove any duplicated slashes in the URL
    for (int i = 0; i < len - 1; i++)
    {
        if (url[i] == '/' && url[i + 1] == '/')
        {
            memmove(&url[i], &url[i + 1], len - i);
            len--;
        }
    }

    // Print out the sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}