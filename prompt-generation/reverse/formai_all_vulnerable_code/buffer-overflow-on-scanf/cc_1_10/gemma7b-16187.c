//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_URL_LENGTH 255

void sanitize_url(char *url)
{
    char *p = url;
    char *q = url;

    // Remove leading and trailing spaces
    while (*p == ' ')
    {
        p++;
    }
    while (*q != '\0' && *(q + 1) != ' ')
    {
        q++;
    }

    // Convert special characters to ASCII
    for (; *p != '\0'; p++)
    {
        if (*p >= 'a' && *p <= 'z')
        {
            *p = *p - 32;
        }
        else if (*p >= 'A' && *p <= 'Z')
        {
            *p = *p - 32;
        }
        else if (*p >= '0' && *p <= '9')
        {
            *p = *p - 32;
        }
        else if (*p == '.' || *p == '/' || *p == '\\' || *p == '?')
        {
            *p = '_';
        }
    }

    // Normalize the URL
    url = q;
    return;
}

int main()
{
    char url[MAX_URL_LENGTH];

    printf("Enter a URL: ");
    scanf("%s", url);

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}